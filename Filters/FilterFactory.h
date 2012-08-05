#ifndef _FILTERFACTORY_H_
#define _FILTERFACTORY_H_


#include "Filter.h"

class FilterFactory{

public:
	FilterFactory(){};
	~FilterFactory(){};
	Filter* createFilter(std::string);

};


#endif