#include "EllipseTool.h"

int EllipseTool::brushSize = 2;

void EllipseTool::mousePressEvent(QMouseEvent* event, PaintArea *ourImage)
{
                        if(ourImage->getUndoPointer() == -1)
                                 ourImage->saveUndoState();
						originalImage = *ourImage->getImage();
                        ourImage->setLastPoint(event->pos());
                         ourImage->setScribbling(true);
						 
}

void EllipseTool::mouseMoveEvent(QMouseEvent* event, PaintArea *ourImage)
{
		ourImage->setImage(originalImage);
        drawEllipseTo( event->pos(), ourImage);
		
}


void  EllipseTool::mouseReleaseEvent(QMouseEvent *event, PaintArea *ourImage)
 {
     if (event->button() == Qt::LeftButton ) {
                 
         drawEllipseTo(event->pos(), ourImage);

     }
	 

 }

void EllipseTool::drawEllipseTo(const QPoint &endPoint, PaintArea *ourImage)
 {
	const QPoint lastPoint = ourImage->getLastPoint();
	QImage* yup = ourImage->getImage();
	QPainter painter(yup);
	const QPen pen(Tool::globalToolColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);
    
	QRect rectangle = QRect(lastPoint, endPoint);
	painter.drawEllipse(rectangle);
	//ourImage->modified = true;

	int rad = (brushSize / 2) + 2;
	ourImage->update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	//ourImage->setLastPoint(endPoint);

        
 }