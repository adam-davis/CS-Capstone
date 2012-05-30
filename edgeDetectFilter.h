#pragma once
#include "filter.h"

class edgeDetectFilter :  public Filter
{
public:
	~edgeDetectFilter(){};

	virtual void apply(QImage* image);
	QRgb convolute(const QList<int> &kernal, const QImage &image, int x, int y); 


	private slots:
		void edgeDetect();
	
};

