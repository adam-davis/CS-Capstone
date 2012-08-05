#pragma once
#include "filter.h"

class EmbossFilter :  public Filter
{
public:
	~EmbossFilter(){};

	virtual void apply(QImage* image);
	//QRgb convolute(const QList<int> &kernal, const QImage &image, int x, int y); 


	private slots:
		void emboss();
	
};

