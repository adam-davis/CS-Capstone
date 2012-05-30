#pragma once
#include "Filter.h"
class GrayscaleFilter :	public Filter
{
public:
	~GrayscaleFilter(){};
	GrayscaleFilter(){};
	virtual void apply(QImage* image);

	private slots:
		void grayscale();
};