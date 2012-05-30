#ifndef TYPETOOLINPUT_H_
#define TYPETOOLINPUT_H_
#include <QTextEdit>
#include <QKeyEvent>
#include "PaintArea.h"

class TypeToolInput : public QTextEdit
{
	Q_OBJECT
public:
	TypeToolInput();
	TypeToolInput(QWidget*);
	~TypeToolInput();

	void adjustWidth();
	void keyPressEvent(QKeyEvent*);
	PaintArea* targetPaintArea;
	QPoint point;
	void setPoint(const QPoint& point){this->point = point;};
	void setPaintArea(PaintArea* sourcePaintArea){targetPaintArea = sourcePaintArea;};
    int fontSize;
	bool finished;
	public slots:
		void changeTextFont(const QString&);





};


#endif