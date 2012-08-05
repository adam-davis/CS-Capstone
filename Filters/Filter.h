#ifndef _FILTER_H_
#define _FILTER_H_
#include <QImage>



class Filter
{
public:
	Filter(void);
	~Filter(void);

	virtual	void  apply(QImage* image){};
};




//Including the other filters here because well
//it certainly cuts down on the include list


#endif

