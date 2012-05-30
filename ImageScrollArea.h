#ifndef _PAINT_IMAGE_H_
#define _PAINT_IMAGE_H_

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include "Filter.h"
#include <QScrollArea>
#include <map>
#include <vector>
#include "PaintArea.h"

class ImageScrollArea : public QScrollArea
 {
     Q_OBJECT

 public:
	 void undo();
	 void redo();


	 ImageScrollArea(QWidget *parent = 0);
     bool addPaintArea(PaintArea *paintArea);



 };



#endif