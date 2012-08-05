#ifndef IMAGEROTATOR_H_
#define IMAGEROTATOR_H_
#include <QImage>
#include "PaintArea.h"
#include "NumericInput.h"

class ImageRotator 
{
public:
	QImage originalImage;
	ImageRotator(){};
	~ImageRotator(){};
	void setImage();
	 static void rotateImage(PaintArea* imageToRotate, double angle);

};


#endif