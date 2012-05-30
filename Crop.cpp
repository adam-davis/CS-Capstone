#include "Crop.h"


Crop::Crop(PaintArea* image)
{
	QImage copy = image->getImage()->copy(image->getSelection());
	QSize newSize = copy.size().expandedTo(image->size());
	image->setImage(copy);
	image->updateImageArea(newSize);
	image->update();
}


Crop::~Crop(void)
{
}
