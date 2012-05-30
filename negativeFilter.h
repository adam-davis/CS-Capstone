#ifndef _NEGATIVEFILTER_H_
#define _NEGATIVEFILTER_H_
#include "filter.h"
#include <QColor>


class NegativeFilter :	public Filter
{
public:
	~NegativeFilter(){};

	 virtual void apply(QImage* image);

	public slots:
		static void negative();
};

#endif