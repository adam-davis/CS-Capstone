#pragma once
#include "filter.h"

class SepiaFilter :     public Filter
{
public:
        SepiaFilter(void);
        ~SepiaFilter(void);

        virtual void apply(QImage* image);
        void setName(std::string newName){name = newName;}

        public slots:
                void sepia();

private:
        std::string name;
};
