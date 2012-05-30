#include "FilterFactory.h"
#include "negativeFilter.h"
#include "grayscaleFilter.h"
#include "Filter.h"
#include "negativeFilter.h"
#include "grayscaleFilter.h"
#include "pixelationFilter.h"
#include "gaussianFilter.h"
#include "sepiaFilter.h"
#include "edgeDetectFilter.h"
#include "embossFilter.h"
#include "sharpenFilter.h"

Filter* FilterFactory::createFilter(std::string filterType)
{
		if(filterType == "negative")
			return new NegativeFilter();
		else if(filterType == "grayscale")
			return new GrayscaleFilter();
		else if(filterType == "sharpen")
			return new SharpenFilter();
		else if(filterType == "pixelation")
			return new PixelationFilter();
		else if(filterType == "sepia")
			return new SepiaFilter();
		else if(filterType == "gaussian")
			return new GaussianFilter();
		else if(filterType == "emboss")
			return new EmbossFilter();
		else if (filterType == "edgeDetect")
			return new edgeDetectFilter();

}