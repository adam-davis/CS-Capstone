#include "pixelationFilter.h"

 PixelationFilter::~PixelationFilter()
 {


 }

 PixelationFilter::PixelationFilter()
{

}

void PixelationFilter::apply(QImage* currentImage)
{
	int width = currentImage->width();
	int height = currentImage->height();
	QRgb color;
	int red, green, blue, i = 0, j = 0, offset = 0;
	int temp1, temp2 = 0;
	//int dimension;
	//dimension = width * height;
	int size = 10;

	while ((i <= width) && (j <= height)) 
	{
		temp1 = i;
		temp2 = j;

		color = currentImage->pixel(i, j);
		QColor edit(color);

		for (i = temp1; i < (temp1 + size); i++)
		{
			if (i >= width)
				break;

			for (j = temp2; j < (temp2 + size); j++)
			{
				if (j >= height)
					break;

				red = edit.red();
				green = edit.green();
				blue = edit.blue();

				color = qRgb(red, green, blue);

				currentImage->setPixel(i, j, color);
			}
		}

		if (i >= width)
		{
			offset += size;
			i = 0;
		}

		j = offset;
	}

}