#include "ImageScrollArea.h"
#include <QMainWindow>





 ImageScrollArea::ImageScrollArea(QWidget *parent)
     : QScrollArea(parent)
 {
     setAttribute(Qt::WA_StaticContents);

     
 }




  bool addPaintArea(PaintArea *paintArea);


bool ImageScrollArea::addPaintArea(PaintArea *paintArea)
 {

     PaintArea* derp = paintArea;
     derp->setObjectName(paintArea->objectName());
     this->setWidget(derp);
     update();
     return true;
 }


