#include "FunkyLineTool.h"

int FunkyLineTool::brushSize = 2;

void FunkyLineTool::mousePressEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{

                        currentPaintArea->setLastPoint(event->pos());
                         currentPaintArea->setScribbling(true);

}
void FunkyLineTool::mouseMoveEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{

       drawLineTo(event->pos(), currentPaintArea);
}



void FunkyLineTool::drawLineTo(const QPoint &endPoint, PaintArea *currentPaintArea)
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
