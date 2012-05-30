#include "MainWindow.h"
#include <QFileDialog>
#include <QtGui/QMessageBox>
#include <QScrollArea>
#include <QColorDialog>
#include "ImageDownloader.h"
 #include <QBoxLayout>
#include "NewImageDialog.h"
#include "imageresizedialog.h"
#include "imagerotatedialog.h"
#include "PaintBrushOptions.h"
#include "TypeToolOptions.h"
#include "ImageRotator.h"


	static int imageID = 1;

	PaintBrushOptions* pBrushOptions;
MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{

	ui.setupUi(this);
	toolManager = new ToolManager();
	//ui.PaintBrushOptions->hide();
	pBrushOptions = new PaintBrushOptions(ui.dockWidgetContents_5);
	pBrushOptions->setObjectName(QString::fromUtf8("PaintBrushOptions"));
	pBrushOptions->hide();

	ui.EraserToolOptions->hide();
	//Setting up Click Events for toolbar buttons
	this->toolSignalMapper = new QSignalMapper(this);
	connect(toolSignalMapper, SIGNAL(mapped(QString)), this, SLOT(toggleTool(QString)));
	connect(ui.PaintBrush, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
    connect(ui.EyedropperTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
//	connect(ui.ZoomTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.LineTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.FillTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.FunkyLineTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
    connect(ui.RectangleTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.FilterBrush, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.MarqueeSelect, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.EraserTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.EllipseTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	connect(ui.TypeTool, SIGNAL(clicked()), toolSignalMapper, SLOT(map()));
	toolSignalMapper->setMapping(ui.EraserTool, "EraserTool");
	toolSignalMapper->setMapping(ui.PaintBrush, "PaintBrush");
    toolSignalMapper->setMapping(ui.EyedropperTool, "EyedropperTool");
//	toolSignalMapper->setMapping(ui.ZoomTool, "ZoomTool");
	toolSignalMapper->setMapping(ui.LineTool, "LineTool");
	toolSignalMapper->setMapping(ui.FunkyLineTool, "FunkyLineTool");
	toolSignalMapper->setMapping(ui.FillTool, "FillTool");
	toolSignalMapper->setMapping(ui.RectangleTool, "RectangleTool");
	toolSignalMapper->setMapping(ui.FilterBrush, "FilterBrush");
	toolSignalMapper->setMapping(ui.MarqueeSelect, "MarqueeSelect");
	toolSignalMapper->setMapping(ui.EllipseTool, "EllipseTool");
	toolSignalMapper->setMapping(ui.TypeTool, "TypeTool");

	//Connecting the Filters up to the Filter Signal Mapper...
	//Should look into a new way to handle this...it definetley
	//needs to be moved to its own area.
	this->filterSignalMapper = new QSignalMapper(this);
	connect(filterSignalMapper, SIGNAL(mapped(QString)), this, SLOT(applyFilter(QString)));
	connect(ui.actionInverse, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionInverse, "negative");
	connect(ui.actionGrayscale, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionGrayscale, "grayscale");
	connect(ui.actionPixelate, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionPixelate, "pixelation");
	connect(ui.actionSepia_Tone, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionSepia_Tone, "sepia");
	connect(ui.actionBlur, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionBlur, "gaussian");
	connect(ui.actionFind_Edges, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionFind_Edges, "edgeDetect");
	connect(ui.actionEmboss, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionEmboss, "emboss");
	connect(ui.actionSharpen, SIGNAL(triggered()), filterSignalMapper, SLOT(map()));
	filterSignalMapper->setMapping(ui.actionSharpen, "sharpen");


	this->setObjectName("MainWindow");
	imageTabs = new QTabWidget(this);
	setCentralWidget(imageTabs);
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newImage()));
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(open()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(exit()));
	connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(save()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
	connect(ui.actionColor, SIGNAL(triggered()), this, SLOT(colorPicker()));
	connect(ui.actionZoom_In, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(ui.actionZoom_Out, SIGNAL(triggered()), this, SLOT(zoomOut()));
	connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
	connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
	connect(ui.actionOpenUrl, SIGNAL(triggered()), this, SLOT(downloadImage()));
	connect(ui.actionImage_Size_2, SIGNAL(triggered()), this, SLOT(resizeImage()));
	connect(ui.actionRotate, SIGNAL(triggered()), this, SLOT(rotateImage()));
	connect(ui.actionRotate_Clockwise, SIGNAL(triggered()), this, SLOT(rotateImageClockwise()));
	connect(ui.actionRotate_Counter_Clockwise, SIGNAL(triggered()), this, SLOT(rotateImageCounterClockwise()));
	connect(ui.actionCrop, SIGNAL(triggered()), this, SLOT(crop()));
	connect(ui.actionCopy, SIGNAL(triggered()), this, SLOT(toClipboard()));
	connect(ui.actionPaste, SIGNAL(triggered()), this, SLOT(imageFromClipboard()));
	connect(ui.actionCut, SIGNAL(triggered()), this, SLOT(cut()));




	connect(ui.eraserSizeSlider, SIGNAL(sliderReleased()), this, SLOT(resizeEraser()));
   

}


void MainWindow::rotateImageClockwise()
{
	if(imageNotLoaded())
		return;
	 getCurrentPaintArea()->rotateImage(90);
	imageTabs->currentWidget()->repaint();
}
void MainWindow::rotateImageCounterClockwise()
{
	if(imageNotLoaded())
		return;
	getCurrentPaintArea()->rotateImage(-90);
	imageTabs->currentWidget()->repaint();
}


void MainWindow::rotateImage()
{

		if(imageNotLoaded())
			return;

        ImageRotateDialog* imageRotateDiag = new ImageRotateDialog();
        imageRotateDiag->exec();
        PaintArea* ourImage = getCurrentPaintArea();
        QImage* imageToRotate = ourImage->getImage();
        if(imageRotateDiag->rejected)
			return;
        ImageRotator::rotateImage(ourImage, imageRotateDiag->getImageAngle());
        
        ourImage->resize(ourImage->getImage()->width(), ourImage->getImage()->height());
        ourImage->update();
        imageTabs->currentWidget()->repaint();

}

void MainWindow::newImage()
{

	NewImageDialog* newImgDiag = new NewImageDialog();
	newImgDiag->exec();
	if(QString::number(newImgDiag->getNewSize()->height()) == "0")
		return;
	ImageScrollArea *newImageScrollArea = new ImageScrollArea;
	QString name = "new_image1"+QString::number(imageID);
	PaintArea *newImage = new PaintArea();
	newImage->updateImageArea(*newImgDiag->getNewSize());
	newImage->setObjectName(name);
	addNewImageTab(newImage);
	++imageID;
}




void MainWindow::addNewImageTab(PaintArea *newImage)
{
	ImageScrollArea *newImageScrollArea = new ImageScrollArea;
	newImageScrollArea->setObjectName(newImage->objectName());
	newImageScrollArea->addPaintArea(newImage);
	imageTabs->addTab(newImageScrollArea, newImage->objectName());
	if (newImage->getImage()->height() > this->height() ||
		newImage->getImage()->width() > this->width())
 		this->resize(newImage->getImage()->width()+500, newImage->getImage()->height());
	
	imageTabs->setCurrentWidget(newImageScrollArea);
}

void MainWindow::close()
{
	imageTabs->currentWidget()->deleteLater();
	
	PaintArea *currentPaintArea = getCurrentPaintArea();
	delete currentPaintArea;
	imageTabs->removeTab(imageTabs->currentIndex());
}

void MainWindow::save()
{
	if(imageNotLoaded())
		return;
	QString fileLocation = imageTabs->tabText(imageTabs->currentIndex());
	//No Image current loaded
	if(fileLocation == "")

		return;
	PaintArea *currentImage = imageTabs->findChild<PaintArea*>(fileLocation);
	if(currentImage->isNew())
		saveAs();
	else
		currentImage->saveImage(fileLocation, QFileInfo(fileLocation).completeSuffix().toStdString().c_str());
}

void MainWindow::saveAs()
{
	if(imageNotLoaded())
		return;

	QFileDialog *fileDailog = new QFileDialog(this);
	QString fileName =  fileDailog->getSaveFileName(this, tr("Save as....."), "",
    tr("JPG (*.jpg );;.PNG(*.png);;.GIF(*.gif);;.BMP(*.bmp);;.JPEG(*.jpeg)"));
	
	QFile file(fileName);
	QString fileLocation = imageTabs->tabText(imageTabs->currentIndex());
	QFileInfo *fileInfo = new QFileInfo(file);
	if(fileLocation == "")
		return;
	PaintArea *currentImage = imageTabs->findChild<PaintArea*>(fileLocation);

	imageTabs->setTabText(imageTabs->currentIndex(), fileName);

	currentImage->saveImage(fileName, fileInfo->suffix().toStdString().c_str());
}


void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Image Files (*.jpg *.png *.bmp *.jpeg)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
		QFileInfo *fileInfo;

		try
		{
			fileInfo= new QFileInfo(file);
		}

		catch(...) 
		{
			/*TO-DO: Add Error Handling*/
			std::string errors = "Error loading file";
		}
		PaintArea *newImage = new PaintArea();
		newImage->openImage(fileInfo->absoluteFilePath());
		addNewImageTab(newImage);

        file.close();
    }


}





void MainWindow::downloadImage()
{
	ImageDownloader* imgDl = new ImageDownloader();


	imgDl->downloadBegin();

	QEventLoop loop;
	QObject::connect(imgDl->netReply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

	imgDl->downloadFinished();
	QString newName = "yup";
	PaintArea *newImage = new PaintArea(this);
	newImage->setObjectName(newName);
	newImage->openImage(*imgDl->urlImage);
	addNewImageTab(newImage);




}
PaintArea* MainWindow::getCurrentPaintArea()
{
	QString fileLocation = imageTabs->tabText(imageTabs->currentIndex());
	PaintArea *currentImage = imageTabs->currentWidget()->findChild<PaintArea*>(fileLocation);
	return currentImage;
}
void MainWindow::undo()
{
	PaintArea* currentPaintArea = getCurrentPaintArea();
	currentPaintArea->undo();
	currentPaintArea->update();
}

void MainWindow::redo()
{
	PaintArea* currentPaintArea = getCurrentPaintArea();
	currentPaintArea->redo();
	currentPaintArea->update();


}

MainWindow::~MainWindow()
{

}


void MainWindow::applyFilter(const QString &filterName)
{
	Filter* ourLovelyFilter = filterFactory.createFilter(filterName.toStdString());
	if(imageNotLoaded())
		return;
	if(getCurrentPaintArea()->getUndoPointer() == -1)
		getCurrentPaintArea()->saveUndoState();

	ourLovelyFilter->apply(getCurrentPaintArea()->getImage());
	getCurrentPaintArea()->update();
	getCurrentPaintArea()->saveUndoState();
}



//When setting the text of the current tool, set it to be equal
//to the widget name given to the tool in ui_MainWindow.h

void MainWindow::toggleTool(const QString toolName)
{
		//Refactored by aDavis - 03/05/2012
	QString currentTool = toolManager->getCurrentTool()->getName();

	if(currentTool != "" )
		{
			QToolButton* selectedTool = this->findChild<QToolButton*>(currentTool);
			selectedTool->isChecked() ? selectedTool ->setChecked(true) : selectedTool ->setChecked(false);  
		
		}
		 if (toolName != currentTool){

			QToolButton* aselectedTool = this->findChild<QToolButton*>(currentTool);
			
			if(currentTool == "")
				aselectedTool->setChecked(true);
			else
				aselectedTool->setChecked(false);
			toolManager->setCurrentTool(toolName);
		}
		 else
			 	toolManager->setCurrentTool("");

		QString previousTool = currentTool;
		currentTool = toolManager->getCurrentTool()->getName();
		if(toolName != "TypeTool") ui.ToolOptions->setWidget(this->findChild<QWidget*>(toolName+"Options"));
		if(currentTool != "PaintBrush") pBrushOptions->hide();
		QWidget *derp;
		if(previousTool == "TypeTool" && currentTool != "TypeTool")
		{
			 derp = this->getCurrentPaintArea()->findChild<QWidget*>(previousTool+"Options");
			 delete derp;

		}


}




void MainWindow::exit()
{
	qApp->quit();

}


void MainWindow::zoomIn()
{
	scale(1.6);
		
}

void MainWindow::zoomOut()
{
	scale(.625);	
}

void MainWindow::crop() {
	PaintArea* currentPaintArea = getCurrentPaintArea();
	Crop::Crop(currentPaintArea);
}

void MainWindow::toClipboard() {
	PaintArea* currentPaintArea = getCurrentPaintArea();
	CopyPaste *copy = new CopyPaste(currentPaintArea);
	copy->copy();
}

void MainWindow::imageFromClipboard() {
	PaintArea* currentPaintArea = getCurrentPaintArea();
	CopyPaste *paste = new CopyPaste(currentPaintArea);
	paste->paste();
}

void MainWindow::cut() {
	PaintArea* currentPaintArea = getCurrentPaintArea();
	CopyPaste *cut = new CopyPaste(currentPaintArea);
	cut->cut();
}

void MainWindow::resizeEraser()
{
	imageTabs->update();
	EraserTool::setEraserSize(ui.eraserSizeSlider->value());
}



//Refacoted on 03/24 - May be able to be placed in outside class
//AD
void MainWindow::resizeImage()
{
	if(imageNotLoaded())
		return;

	PaintArea* currentPaintArea = getCurrentPaintArea();

	ImageResizeDialog* imgSizeDiag = new ImageResizeDialog(this, currentPaintArea->getImage()->width(), currentPaintArea->getImage()->height());

	imgSizeDiag->exec();
	if(QString::number(imgSizeDiag->getNewSize()->height()) == "0")
		return;
	QSize newSize(*imgSizeDiag->getNewSize());
	
	currentPaintArea->resizeImage(newSize);
	
	


}




void MainWindow::scale(double factor)
{
	QLabel *imgLabel = imageTabs->currentWidget()->findChild<QLabel *>(); 
	const QPixmap *currentPixmap = imgLabel->pixmap();          
	QImage currentImage = currentPixmap->toImage(); 
	
	imgLabel -> resize(factor * imgLabel -> size());
}


void MainWindow::colorPicker()
{
	PaintArea *currentImage = imageTabs->findChild<PaintArea*>();
	QColorDialog *color = new QColorDialog;
	QColor selectedColor = QColorDialog::getColor(Qt::red, this, "Text Color",  QColorDialog::DontUseNativeDialog);
	Tool::setColor(selectedColor);
}


