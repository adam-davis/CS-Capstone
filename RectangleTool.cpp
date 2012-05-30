#include "RectangleTool.h"

int RectangleTool::brushSize = 2;

void RectangleTool::mousePressEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{
						originalImage = *currentPaintArea->getImage();
                        currentPaintArea->setLastPoint(event->pos());
                         currentPaintArea->setScribbling(true);
						 
}

void RectangleTool::mouseMoveEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{
		currentPaintArea->setImage(originalImage);
        drawRectangleTo( event->pos(), currentPaintArea);
		
}


void  RectangleTool::mouseReleaseEvent(QMouseEvent *event, PaintArea *currentPaintArea)
 {
     if (event->button() == Qt::LeftButton )      
         drawRectangleTo(event->pos(), currentPaintArea);

 }

void RectangleTool::drawRectangleTo(const QPoint &endPoint, PaintArea *currentPaintArea)
 {
	const QPoint lastPoint = currentPaintArea->getLastPoint();
	QImage* yup = currentPaintArea->getImage();
	QPainter painter(yup);
	const QPen pen(globalToolColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);
    
	QRect rectangle = QRect(lastPoint, endPoint);
	painter.drawRect(rectangle);


	int rad = (brushSize / 2) + 2;
	currentPaintArea->update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));

        
 }
