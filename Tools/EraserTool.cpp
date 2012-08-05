#include "EraserTool.h"
QColor EraserTool::brushColor = Qt::white; //blue;
int EraserTool::brushSize = 2;

void EraserTool::mousePressEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{

                        currentPaintArea->setLastPoint(event->pos());
                         currentPaintArea->setScribbling(true);

}
void EraserTool::mouseMoveEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{

        drawLineTo(event->pos(), currentPaintArea);
}


void  EraserTool::mouseReleaseEvent(QMouseEvent *event, PaintArea *currentPaintArea)
 {
     if (event->button() == Qt::LeftButton ) {
                 
         drawLineTo(event->pos(), currentPaintArea);

     }

 }

void EraserTool::drawLineTo(const QPoint &endPoint, PaintArea *currentPaintArea)
 {
	QPoint lastPoint = currentPaintArea->getLastPoint();
	QImage* yup = currentPaintArea->getImage();
	QPainter painter(yup);
	const QPen pen(Qt::white, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);
         
	painter.drawLine(lastPoint, endPoint);

	int rad = (brushSize / 2) + 2;
	currentPaintArea->update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	currentPaintArea->setLastPoint(endPoint);

        
 }
