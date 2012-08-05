#include "ImageRotator.h"
#include <QImage>
#include <QColor>
#include <cmath>
#include <QPainter>
#include "PaintArea.h"
# define M_PI 3.1415926535897932384626433832795029L


double round(double);
/*Mad Love to 
http://polymathprogrammer.com/2010/04/05/image-rotation-with-bilinear-interpolation-and-no-clipping/
*/
void ImageRotator::rotateImage(PaintArea* pa, double angle)
{
	QImage* imageToRotate = pa->getImage();
	const int cnSizeBuffer = 20;
// 30 deg = PI/6 rad
// rotating clockwise, so it's negative relative to Cartesian quadrants

	double temp = (angle / 180);
	temp = temp * M_PI;
		
//const double cnAngle = -0.52359877559829887307710723054658;
	const double cnAngle = angle < 180 ? (double)(angle / 180) * M_PI * -1 : (angle / 180) * M_PI;

// use whatever image you fancy

// general iterators
int i, j;
// calculated indices in Cartesian coordinates
int x, y;
double fDistance, fPolarAngle;
// for use in neighbouring indices in Cartesian coordinates
int iFloorX, iCeilingX, iFloorY, iCeilingY;
// calculated indices in Cartesian coordinates with trailing decimals
double fTrueX, fTrueY;
// for interpolation
double fDeltaX, fDeltaY;
// pixel colours
QColor clrTopLeft, clrTopRight, clrBottomLeft, clrBottomRight;
// interpolated "top" pixels
double fTopRed, fTopGreen, fTopBlue;
// interpolated "bottom" pixels
double fBottomRed, fBottomGreen, fBottomBlue;
// final interpolated colour components
int iRed, iGreen, iBlue;
int iCentreX, iCentreY;
int iDestCentre;
int iWidth, iHeight;
int iDiagonal;
iWidth = imageToRotate->width();
iHeight = imageToRotate->height();
iDiagonal = (int)(std::ceil(std::sqrt((double)(imageToRotate->width() * imageToRotate->width() + imageToRotate->height() * imageToRotate->height())))) + cnSizeBuffer;

iCentreX = iWidth / 2;
iCentreY = iHeight / 2;
iDestCentre = iDiagonal / 2;

QImage rotatedImage(iDiagonal, iDiagonal, QImage::Format_ARGB32);

for (i = 0; i < iDiagonal; ++i)
{
	for (j = 0; j < iDiagonal; ++j)
	{
		rotatedImage.setPixel(QPoint(j, i), qRgb(255,255,255));
	}
}


// assigning pixels of destination image from source image
// with bilinear interpolation
for (i = 0; i < iDiagonal; ++i)
{
	for (j = 0; j < iDiagonal; ++j)
	{
		// convert raster to Cartesian
		x = j - iDestCentre;
		y = iDestCentre - i;

		// convert Cartesian to polar
		fDistance = std::sqrt(double(x * x + y * y));
		fPolarAngle = 0.0;
		if (x == 0)
		{
			if (y == 0)
			{
				// centre of image, no rotation needed
				rotatedImage.setPixel(j, i, imageToRotate->pixel(iCentreX, iCentreY));
				continue;
			}
			else if (y < 0)
			{
				fPolarAngle = 1.5 * M_PI;
			}
			else
			{
				fPolarAngle = 0.5 * M_PI;
			}
		}
		else
		{
			fPolarAngle = std::atan2((double)y, (double)x);
		}

		// the crucial rotation part
		// "reverse" rotate, so minus instead of plus
		fPolarAngle -= cnAngle;

		// convert polar to Cartesian
		fTrueX = fDistance * std::cos(fPolarAngle);
		fTrueY = fDistance * std::sin(fPolarAngle);

		// convert Cartesian to raster
		fTrueX = fTrueX + (double)iCentreX;
		fTrueY = (double)iCentreY - fTrueY;

		iFloorX = (int)(std::floor(fTrueX));
		iFloorY = (int)(std::floor(fTrueY));
		iCeilingX = (int)(std::ceil(fTrueX));
		iCeilingY = (int)(std::ceil(fTrueY));

		// check bounds
		if (iFloorX < 0 || iCeilingX < 0 || iFloorX >= iWidth || iCeilingX >= iWidth || iFloorY < 0 || iCeilingY < 0 || iFloorY >= iHeight || iCeilingY >= iHeight) continue;

		fDeltaX = fTrueX - (double)iFloorX;
		fDeltaY = fTrueY - (double)iFloorY;

		clrTopLeft = imageToRotate->pixel(iFloorX, iFloorY);
		clrTopRight = imageToRotate->pixel(iCeilingX, iFloorY);
		clrBottomLeft = imageToRotate->pixel(iFloorX, iCeilingY);
		clrBottomRight = imageToRotate->pixel(iCeilingX, iCeilingY);

		// linearly interpolate horizontally between top neighbours
		fTopRed = (1 - fDeltaX) * clrTopLeft.red() + fDeltaX * clrTopRight.red();
		fTopGreen = (1 - fDeltaX) * clrTopLeft.green() + fDeltaX * clrTopRight.green();
		fTopBlue = (1 - fDeltaX) * clrTopLeft.blue() + fDeltaX * clrTopRight.blue();

		// linearly interpolate horizontally between bottom neighbours
		fBottomRed = (1 - fDeltaX) * clrBottomLeft.red() + fDeltaX * clrBottomRight.red();
		fBottomGreen = (1 - fDeltaX) * clrBottomLeft.green() + fDeltaX * clrBottomRight.green();
		fBottomBlue = (1 - fDeltaX) * clrBottomLeft.blue() + fDeltaX * clrBottomRight.blue();

		// linearly interpolate vertically between top and bottom interpolated results
		iRed = (int)(round((1 - fDeltaY) * fTopRed + fDeltaY * fBottomRed));
		iGreen = (int)(round((1 - fDeltaY) * fTopGreen + fDeltaY * fBottomGreen));
		iBlue = (int)(round((1 - fDeltaY) * fTopBlue + fDeltaY * fBottomBlue));

		// make sure colour values are valid
		if (iRed < 0) iRed = 0;
		if (iRed > 255) iRed = 255;
		if (iGreen < 0) iGreen = 0;
		if (iGreen > 255) iGreen = 255;
		if (iBlue < 0) iBlue = 0;
		if (iBlue > 255) iBlue = 255;

		rotatedImage.setPixel(j, i, qRgb(iRed, iGreen, iBlue));
	}
}

		QImage newImage(iDiagonal, iDiagonal, QImage::Format_RGB32);
		QPainter myQPainter(&newImage);
		pa->resize(iDiagonal, iDiagonal);
		myQPainter.drawImage(0,0, rotatedImage);
		pa->setImage(newImage);
		pa->update();

}


double round(double r) {
    return (r > 0.0) ? std::floor(r + 0.5) : std::ceil(r - 0.5);
}
