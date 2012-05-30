#ifndef PAINTBRUSHOPTION_H_
#define PAINTBRUSHOPTION_H_


#include <QWidget>
#include "NumericInput.h"
#include <QSlider>

class PaintBrushOptions : public QWidget
{
	Q_OBJECT
public:
	PaintBrushOptions(QWidget*);
	~PaintBrushOptions(){};
	NumericInput* paintBrushSize;
	QSlider* brushSizeSlider;
	void updateSizeText();
	QFont font;
	private slots:
		void updateSlider();
		void resizeBrush();




};

#endif