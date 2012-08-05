#include "LineTool.h"

int LineTool::brushSize = 2;

void LineTool::mousePressEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{
						originalImage = *currentPaintArea->getImage();
                        currentPaintArea->setLastPoint(event->pos());
                         currentPaintArea->setScribbling(true);

}
void LineTool::mouseMoveEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{
		currentPaintArea->setImage(originalImage);
       drawLineTo( event->pos(), currentPaintArea);
}


void  LineTool::mouseReleaseEvent(QMouseEvent *event, PaintArea *currentPaintArea)
 {
     if (event->button() == Qt::LeftButton ) {
                 
         drawLineTo(event->pos(), currentPaintArea);

     }

 }

void LineTool::drawLineTo(const QPoint &endPoint, PaintArea *currentPaintArea)
 {
	QPoint lastPoint = currentPaintArea->getLastPoint();
	QImage* yup = currentPaintArea->getImage();
	QPainter painter(yup);
	const QPen pen(globalToolColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);
         
	painter.drawLine(lastPoint, endPoint);
	//currentPaintArea->modified = true;

	int rad = (brushSize / 2) + 2;
	currentPaintArea->update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	//currentPaintArea->setLastPoint(endPoint);

        
 }
