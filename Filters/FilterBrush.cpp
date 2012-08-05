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


