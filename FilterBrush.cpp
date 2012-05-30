#include "FilterBrush.h"
#include <math.h> 
#include <QRgb>
#include <stdlib.h>
#include <sstream>
QColor FilterBrush::brushColor = Qt::blue;
int FilterBrush::brushSize = 2;

void FilterBrush::mousePressEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{

	currentPaintArea->setLastPoint(event->pos());
	currentPaintArea->setScribbling(true);

	QImage* yup = currentPaintArea->getImage();
	std::stringstream ss;

	int xCenter = event->pos().x(),  yCenter = event->pos().y() ,  radius = 35;
	int Left = xCenter - radius;
	int Right = Left + radius * 2;
	int Top = yCenter - radius;
	int Bottom = Top + radius * 2;
	std::string xStr, yStr;
	char *x, *y;
	x = new char();
	y = new char();
	for (int yPos = Top; yPos <= Bottom; ++yPos)
	{
		for (int xPos = Left; xPos <= Right; ++xPos)
		{
			double dist = pow(xCenter - xPos, 2.0) + pow(yCenter - yPos, 2.0);
			if (dist <= pow(radius, 2.0))
			{
				itoa(xPos, x, 10);
				itoa(yPos, y,10);

				xStr = std::string(x);
				yStr = std::string(y);

				if(this->pixels.find(xStr+"w"+yStr) != this->pixels.end())
					continue;

				this->pixels[xStr+"w"+yStr] =   new QPoint(xPos, yPos);
				QRgb color = yup->pixel(xPos, yPos);
				QColor edit(color);
				int red = 255 - edit.red();
				int blue = 255 - edit.blue();
				int green = 255 - edit.green();
				color = qRgb(red, green, blue);
				yup->setPixel(xPos, yPos,color);


			}
			currentPaintArea->update();
		}
	}



	/*Whatchu know bout Beenshams Circle Algorithm? Nothing? Check out wikipedia!
	int f = 1 - radius;
	int ddF_x = 1;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;
	QImage* yup = currentPaintArea->getImage();
	yup->setPixel(xCenter, yCenter + radius, qRgb(255, 255, 255));
	yup->setPixel(xCenter, yCenter - radius, qRgb(255, 255, 255));
	yup->setPixel(xCenter + radius, yCenter, qRgb(255, 255, 255));
	yup->setPixel(xCenter - radius, yCenter, qRgb(255, 255, 255));

	while(x < y)
	{
	ddF_x = 2 * x + 1;
	ddF_y = -2 * y;
	f = x*x + y*y - radius*radius + 2*x - y + 1;
	if(f >= 0) 
	{
	y--;
	ddF_y += 2;
	f += ddF_y;
	}
	x++;
	ddF_x += 2;
	f += ddF_x;    
	yup->setPixel(xCenter + x, yCenter + y, qRgb(255, 255, 255));
	yup->setPixel(xCenter - x, yCenter + y, qRgb(255, 255, 255));
	yup->setPixel(xCenter + x, yCenter - y, qRgb(255, 255, 255));
	yup->setPixel(xCenter - x, yCenter - y, qRgb(255, 255, 255));
	yup->setPixel(xCenter + y, yCenter + x, qRgb(255, 255, 255));
	yup->setPixel(xCenter - y, yCenter + x, qRgb(255, 255, 255));
	yup->setPixel(xCenter + y, yCenter - x, qRgb(255, 255, 255));
	yup->setPixel(xCenter - y, yCenter - x, qRgb(255, 255, 255));
	}*/
	currentPaintArea->update();
}
void FilterBrush::mouseMoveEvent(QMouseEvent* event, PaintArea *currentPaintArea)
{


	QImage* yup = currentPaintArea->getImage();
	std::stringstream ss;

	int xCenter = event->pos().x(),  yCenter = event->pos().y() ,  radius = 35;
	int Left = xCenter - radius;
	int Right = Left + radius * 2;
	int Top = yCenter - radius;
	int Bottom = Top + radius * 2;
	std::string xStr, yStr;
	char *x, *y;
	x = new char();
	y = new char();
	for (int yPos = Top; yPos <= Bottom; ++yPos)
	{
		for (int xPos = Left; xPos <= Right; ++xPos)
		{
			double dist = pow(xCenter - xPos, 2.0) + pow(yCenter - yPos, 2.0);
			if (dist <= pow(radius, 2.0))
			{
				itoa(xPos, x, 10);
				itoa(yPos, y,10);

				xStr = std::string(x);
				yStr = std::string(y);

				if(this->pixels.find(xStr+"w"+yStr) != this->pixels.end())
					continue;

				this->pixels[xStr+"w"+yStr] =   new QPoint(xPos, yPos);
				QRgb color = yup->pixel(xPos, yPos);
				QColor edit(color);
				int red = 255 - edit.red();
				int blue = 255 - edit.blue();
				int green = 255 - edit.green();
				color = qRgb(red, green, blue);
				yup->setPixel(xPos, yPos,color);


			}
			currentPaintArea->update();
		}
	}

}


void  FilterBrush::mouseReleaseEvent(QMouseEvent *event, PaintArea *currentPaintArea)
{
	if (event->button() == Qt::LeftButton ) {

		drawLineTo(event->pos(), currentPaintArea);

		this->pixels.clear();
	}

}

void FilterBrush::drawLineTo(const QPoint &endPoint, PaintArea *currentPaintArea)
{
	/*QPoint lastPoint = currentPaintArea->getLastPoint();
	QImage* yup = currentPaintArea->getImage();
	QPainter painter(yup);
	const QPen pen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);

	painter.drawLine(lastPoint, endPoint);
	//currentPaintArea->modified = true;

	int rad = (brushSize / 2) + 2;
	currentPaintArea->update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	currentPaintArea->setLastPoint(endPoint);*/


}



