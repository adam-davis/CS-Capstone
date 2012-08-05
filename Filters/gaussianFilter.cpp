#include "gaussianFilter.h"

QRgb GaussianFilter::convolute(const QList<int> &kernel, const QImage &image, int x, int y){ 
	int kernelsize = sqrt(double(kernel.size())); 
	qreal total = 0; 
	qreal red = 0; 
	qreal green = 0; 
	qreal blue = 0; 
	for(int r = -kernelsize/2 ; r<=kernelsize/2; ++r){ 
		for(int c = -kernelsize/2; c<=kernelsize/2; ++c){ 
			int kerVal = kernel.at((kernelsize/2+r)*kernelsize+(kernelsize/2+c)); 
			total+=kerVal; 
			red += qRed(image.pixel(x+c, y+r))*kerVal; 
			green += qGreen(image.pixel(x+c, y+r))*kerVal; 
			blue += qBlue(image.pixel(x+c, y+r))*kerVal; 
		} 
	} 
	if(total==0) 
		return qRgb(qBound(0, qRound(red), 255), qBound(0, qRound(green), 255), qBound(0, qRound(blue), 255)); 
	return qRgb(qBound(0, qRound(red/total), 255), qBound(0, qRound(green/total), 255), qBound(0, qRound(blue/total), 255)); 
} 

void GaussianFilter::apply(QImage* currentImage)
{
	int height = currentImage->height();
	int width = currentImage->width();
	static QImage newImage = *currentImage;
	
	QList<int> blur;
	blur 
	<< 0 << 0 << 0 << 0 << 0 
	<< 0 << 1 << 1 << 1 << 0 
	<< 0 << 1 << 1 << 1 << 0 
	<< 0 << 1 << 1 << 1 << 0 
	<< 0 << 0 << 0 << 0 << 0; 

	for(int r=2;r<height-2;r++){ 
		for(int c=2;c<width-2;c++){ 
			newImage.setPixel(c, r, convolute(blur, *currentImage, c, r)); 
		} 
	} 

	*currentImage = newImage;

}

void GaussianFilter::gaussian()
{
}
