#pragma once
#include "filter.h"

class SharpenFilter :  public Filter
{
public:
	~SharpenFilter(){};

	virtual void apply(QImage* image);
	//QRgb convolute(const QList<int> &kernal, const QImage &image, int x, int y); 


	private slots:
		void sharpen();
	
};

