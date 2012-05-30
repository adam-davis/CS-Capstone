#include "grayscaleFilter.h"

void GrayscaleFilter::apply(QImage* currentImage)
{

	int height = currentImage->height();

	int width = currentImage->width();

	QRgb currentColor;

	int currentGray = 0;

	

	for (int i=0; i<width ; ++i)

	{

        for (int j=0; j<height ; ++j)

        {

            currentColor = currentImage->pixel(i, j );
			
            currentGray = qGray(currentColor);

            currentImage->setPixel(i, j , qRgb(currentGray , currentGray , currentGray));

        }

    }



	

	//QPixmap newPixmap = currentPixmap->fromImage(currentImage);

	//imageTabs->currentWidget()->findChild<QLabel *>()->setPixmap(newPixmap);

	//imageTabs->currentWidget()->findChild<QLabel *>()->show();
}

void GrayscaleFilter::grayscale()
{
}
