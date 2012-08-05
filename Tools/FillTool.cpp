#include "FillTool.h"
#include <deque>


void FillTool::fill(QRgb& currentColor, QRgb* newColor, const QPoint &curPixel)
{
	std::deque<QPoint> pixelQueue;
	if(imageToFill.pixel(curPixel) != currentColor) return;
	if(*newColor == currentColor)
		return;
	pixelQueue.push_front(curPixel);
	QPoint currentPoint;
	QPoint pointToAdd;
	int i = 1;
	while(!pixelQueue.empty())
	{
		currentPoint = pixelQueue.back();
		pixelQueue.pop_back();
		if(imageToFill.pixel(currentPoint) == currentColor)
		{
			imageToFill.setPixel(currentPoint, *newColor);
						pixelQueue.push_back(QPoint(currentPoint.x() +i, currentPoint.y()));
			pixelQueue.push_back(QPoint(currentPoint.x() -1, currentPoint.y()));

			pixelQueue.push_back(QPoint(currentPoint.x(), currentPoint.y() +1));
			pixelQueue.push_back(QPoint(currentPoint.x(), currentPoint.y() - 1));
		}

	}




}



void FillTool::mousePressEvent(QMouseEvent *event, PaintArea *currentPaintArea)
{

	QRgb currentColor = currentPaintArea->getImage()->pixel(event->pos());

	if(currentColor ==  globalToolColor.rgb()) return;
		
	QRgb* newColor = new QRgb(globalToolColor.rgb());
	currentPaintArea->setScribbling(true);

	imageToFill = *currentPaintArea->getImage();
	fill(currentColor,newColor , event->pos()); 
	currentPaintArea->setImage(imageToFill);
	currentPaintArea->update();


}