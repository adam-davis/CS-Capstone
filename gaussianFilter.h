#pragma once
#include "Filter.h"

class GaussianFilter :	public Filter
{
public:
	~GaussianFilter(){};

	virtual void apply(QImage* image);
	QRgb convolute(const QList<int> &kernal, const QImage &image, int x, int y); 


	private slots:
		void gaussian();
};