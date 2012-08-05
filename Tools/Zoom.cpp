#include "Zoom.h"


void ZoomTool::mousePressEvent(QMouseEvent* event, PaintArea* currentPaintArea)
{
	QImage originalImage = *currentPaintArea->getImage();
    QPainter painter(&originalImage);
	currentPaintArea->incrementZoomLevel();

	QPoint* newDrawPoint = new QPoint(originalImage.width(),originalImage.height());
	int originalWidth =originalImage.width();
	int originalHeight =originalImage.height();

	int newWidth =originalImage.width() * scaleFactor;
	int newHeight = originalImage.height() * scaleFactor;



	QImage& newImage = originalImage.copy(0,0,  originalImage.width()/scaleFactor, originalImage.height()/scaleFactor);
	
	painter.drawImage(QRect(0,0,  originalImage.width(),  originalImage.height()), newImage);
	const QSize size(newWidth, newHeight);
	newImage.scaled(size);
	currentPaintArea->setImage(originalImage);
	currentPaintArea->updateImageArea(size);
	//originalImage = &newImage;
	currentPaintArea->resize(newWidth, newHeight);
	currentPaintArea->update();
}
