#include "TypeTool.h"
#include <QDockWidget>

#include "TypeToolOptions.h"


TypeTool::TypeTool(void)
{

    name="TypeTool";
	text = NULL;
   


}
TypeTool::~TypeTool(void)
{
	delete text;
}

void TypeTool::initTextEdit(PaintArea* pa, QPoint point)
{
		text = new TypeToolOptions(pa);
		
		text->text->setPaintArea(pa);
		text->show();
		pa->setScribbling(true);
		pa->setLastPoint(point);  
		QSize derp = text->text->size();
		text->text->setParent(pa);
		text->text->move(point);
		text->text->adjustWidth();
		text->text->setPoint(point);
		text->text->show();

}
void TypeTool::mousePressEvent(QMouseEvent* mouseClick, PaintArea* paintArea)
{	
	if(text == NULL)
	{
		initTextEdit(paintArea, mouseClick->pos());
	}
	else
	{
	
			delete text;
			initTextEdit(paintArea, mouseClick->pos());


	}

}
