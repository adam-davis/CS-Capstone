#pragma once
#include "filter.h"
#include <QColor>

class PixelationFilter :  public Filter
{
public:
	PixelationFilter();
	~PixelationFilter();

	virtual void apply(QImage* image);
	void setName(std::string newName){name = newName;}



private:
	std::string name;
};

