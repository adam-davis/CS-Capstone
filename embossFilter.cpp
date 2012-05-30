#include "embossFilter.h"
#include "gaussianFilter.h"

void EmbossFilter::emboss()
{
}

void EmbossFilter::apply(QImage* currentImage)
{
	GaussianFilter gauss;
	int height = currentImage->height();
	int width = currentImage->width();
	static QImage newImage = *currentImage;
	
	QList<int> blur;
	blur 
	<< 0 << 0 << 0 << 0 << 0 
	<< 0 << -2 << -1 << 0 << 0 
	<< 0 << -1 << 1 << 1 << 0 
	<< 0 << 0 << 1 << 2 << 0 
	<< 0 << 0 << 0 << 0 << 0; 

	for(int r=2;r<height-2;r++){ 
		for(int c=2;c<width-2;c++){ 
			newImage.setPixel(c, r, gauss.convolute(blur, *currentImage, c, r)); 
		} 
	} 

	*currentImage = newImage;

}