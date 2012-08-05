 #ifndef PAINTAREA_H
 #define PAINTAREA_H

 #include <QColor>
 #include <QImage>
 #include <QPainterPath>
#include <QPainter>
 #include <QWidget>
#include <QMouseEvent>
#include <QRubberBand>
#include <QRect>
#include "UndoStack.h"


 class PaintArea : public QWidget
 {
     Q_OBJECT

 public:
	 ~PaintArea(){delete undoStack;};
		PaintArea(QWidget *parent = 0);
		void rotateImage(int angle);
		bool openImage(const QString &fileName);
		void openImage(QImage& sourceImage){theImage = sourceImage;update();};
		bool saveImage(const QString &fileName, const char *fileFormat);
		void setImage(const QImage &image);
		void insertShape(const QPainterPath &path);
		QImage* getImage()  { return &theImage; }
		void updateImageArea(QSize);
		void resizeImage(QSize);
		QPoint getLastPoint() const {return lastPoint; }
		void setLastPoint(QPoint newPoint) {lastPoint = newPoint;}
		void setScribbling(bool value){scribbling = value;}
		QSize sizeHint() const;
		void incrementZoomLevel(){++currentZoomLevel;}
		int getZoomLevel() const {return currentZoomLevel;}
		bool isNew(){return newFile;};
		void setRubberGeo(QRect);
		void setSelection();
		QRect getSelection() {return selection;};

		//Handled by UndoStack Proxy class
		int getUndoPointer(){return undoStack->getUndoPointer();};
		void saveUndoState(){undoStack->saveUndoState(theImage);};
		void redo(){undoStack->redo(theImage);resize(theImage.width(), theImage.height());};
		void undo(){undoStack->undo(theImage);resize(theImage.width(), theImage.height());};

 protected:
     void paintEvent(QPaintEvent *);
     void mousePressEvent(QMouseEvent *);
     void mouseMoveEvent(QMouseEvent *);
     void mouseReleaseEvent(QMouseEvent *);
	 
 private:
	 int currentZoomLevel;

     bool modified;
     bool scribbling;
	 bool newFile;
     QImage theImage;
     QPoint lastPoint;
	 UndoStack* undoStack;
	 QRect selection;
	 QRubberBand *rubberBand;
 };

 #endif