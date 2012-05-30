#include "sepiaFilter.h"


SepiaFilter::SepiaFilter(void)
{
}


SepiaFilter::~SepiaFilter(void)
{
}

void SepiaFilter::apply(QImage* currentImage)
{
    int width = currentImage->width();
        int height = currentImage->height();
        QRgb color;
        int red, green, blue, gray;

        for (int i = 0; i < width; i++)
        {
                for (int j = 0; j < height; j++)
                {
                        color = currentImage->pixel(i, j);
                        gray = qGray(color);
                        red = gray;
                        green = gray * .71;
                        blue = gray * .41;
                        color = qRgb(red, green, blue);

                        currentImage->setPixel(i, j, color);
                }
        }

}

void SepiaFilter::sepia()
{
}