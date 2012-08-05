#include "PaintArea.h"
#include "ToolManager.h"
#include <QLabel >


static ToolManager* toolManager = new ToolManager();

void PaintArea::rotateImage(int angle)
{
	QTransform rotation;
	rotation.rotate(90);
	setImage(theImage.transformed(rotation, Qt::SmoothTransformation));
	resize(theImage.width(),theImage.height());
	update();

}
PaintArea::PaintArea(QWidget *parent) : QWidget(parent),
	theImage(500, 400,QImage::Format_RGB32),
	// brushInterface(0),
	lastPoint(-1, -1)
{
	scribbling = false;
	newFile = true;
	undoStack = new UndoStack;
	setAttribute(Qt::WA_StaticContents);
	setAttribute(Qt::WA_NoBackground);
	theImage.fill(qRgb(255, 255, 255));
	currentZoomLevel = 0;
	rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
}

void PaintArea::resizeImage(QSize newSize)
{
	if (theImage.size() == newSize)
		return;

	if(undoStack->getUndoPointer() == -1)
		undoStack->saveUndoState(theImage);



	QImage newImage = theImage.scaled(newSize.width(), newSize.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	resize(newSize.width(), newSize.height());
	setImage(newImage);
	undoStack->saveUndoState(theImage);
	update();


}

void PaintArea::updateImageArea(QSize newSize)
{

	if (theImage.size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), theImage);
	theImage = newImage;



}

void PaintArea::mouseMoveEvent(QMouseEvent* event)
{ 
	if ((event->buttons() & Qt::LeftButton) && scribbling)
		toolManager->getCurrentTool()->mouseMoveEvent(event, this);
}

QSize PaintArea::sizeHint() const
{
	return theImage.size();
}

void PaintArea::paintEvent(QPaintEvent *  event )
{
	QPainter painter(this);
	painter.drawImage(QPoint(0, 0), theImage);
}

void  PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && scribbling) {

		toolManager->getCurrentTool()->mouseReleaseEvent(event, this);
		setScribbling(false);
		undoStack->saveUndoState(theImage);
	}

}



void  PaintArea::mousePressEvent(QMouseEvent *event)
{
	if(undoStack->size() > undoStack->getUndoPointer())
		undoStack->cleanUndoStack();


	if (event->button() == Qt::LeftButton && toolManager->getCurrentTool()->getName() != "") 
	{
		if(getUndoPointer() == -1)
			saveUndoState();

		toolManager->getCurrentTool()->mousePressEvent(event, this);

	}


}

void PaintArea::setImage(const QImage &image)
{
	theImage = image;
	update();
	updateGeometry();

}

bool PaintArea::saveImage(const QString &fileName, const char *fileFormat)
{
	setImage(theImage);


	if (theImage.save(fileName, fileFormat)) {
		modified = false;
		newFile = false;
		setObjectName(fileName);
		return true;
	} else {
		return false;
	}
}


bool PaintArea::openImage(const QString& fileLocation)
{
	if (!theImage.load(fileLocation))
		return false;
	newFile = false;

	update();
	updateGeometry();
	setObjectName(fileLocation);

	return true;
}

void PaintArea::setSelection() {
	selection = rubberBand->geometry();
}

void PaintArea::setRubberGeo(QRect rect) {
	rubberBand->setGeometry(rect);
	rubberBand->show();
}