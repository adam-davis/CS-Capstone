#include "PaintBrushOptions.h"
#include <QLabel>
#include <QSlider > 
#include "PaintBrush.h"
#include <QRegExpValidator>

void PaintBrushOptions::updateSizeText()
{
		char *buffer = new char[4];
		itoa(PaintBrush::brushSize,buffer, 10);
		paintBrushSize->setText(buffer);
}

PaintBrushOptions::PaintBrushOptions(QWidget* parent = 0) : QWidget(parent)
{
        font.setPointSize(10);
		QRegExp expr("[0-9]{1,2}");
		QRegExpValidator *v = new QRegExpValidator(expr, 0);
		paintBrushSize = new NumericInput(this);
        paintBrushSize->setObjectName(QString::fromUtf8("paintBrushSize"));
        paintBrushSize->setGeometry(QRect(50, 10, 30, 20));
		paintBrushSize->setValidator(v);
		char *buffer = new char[4];
		itoa(PaintBrush::brushSize,buffer, 10);
		paintBrushSize->setText(buffer);
        QLabel* sPixel_2 = new QLabel(this);
        sPixel_2->setObjectName(QString::fromUtf8("sPixel_2"));
        sPixel_2->setGeometry(QRect(83, 10, 21, 20));
		sPixel_2->setFont(font);
		sPixel_2->setText("px");
        QLabel* stroke_2 = new QLabel(this);
		stroke_2->setText("Size");
		
        stroke_2->setObjectName(QString::fromUtf8("stroke_2"));
        stroke_2->setGeometry(QRect(12, 10, 41, 20));
        stroke_2->setMinimumSize(QSize(0, 20));
        stroke_2->setMaximumSize(QSize(16777215, 20));

        brushSizeSlider = new QSlider(this);
        brushSizeSlider->setObjectName(QString::fromUtf8("brushSizeSlider"));
        brushSizeSlider->setGeometry(QRect(10, 40, 91, 16));
        brushSizeSlider->setValue(12);
        brushSizeSlider->setOrientation(Qt::Horizontal);
		connect(paintBrushSize, SIGNAL(textChanged(const QString&)), this, SLOT(updateSlider()));
		connect(brushSizeSlider, SIGNAL(sliderReleased()), this, SLOT(resizeBrush()));
}

void PaintBrushOptions::updateSlider()
{
	PaintBrush::brushSize = paintBrushSize->text().toInt();
	brushSizeSlider->setValue(PaintBrush::brushSize);
}

void PaintBrushOptions::resizeBrush()
{


	PaintBrush::setBrushSize(brushSizeSlider->value());
	updateSizeText();


}