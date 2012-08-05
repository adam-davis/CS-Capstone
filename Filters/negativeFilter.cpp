#include "NegativeFilter.h"



void  NegativeFilter::apply(QImage* currentImage)
{
    int width = currentImage->width();
	int height = currentImage->height();
	QRgb color;
	int red, green, blue;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			color = currentImage->pixel(i, j);
			QColor edit(color);
			red = 255 - edit.red();
			blue = 255 - edit.blue();
			green = 255 - edit.green();
			color = qRgb(red, green, blue);

			currentImage->setPixel(i, j, color);
		}
	}



}


void NegativeFilter::negative()
{
}