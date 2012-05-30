#include "UndoStack.h"


void UndoStack::saveUndoState(QImage& theImage)
{
	undoVector.push_back(new QImage(theImage));
	undoPointer++;
}

UndoStack::~UndoStack()
{
	for(int i = 0; i < undoVector.size();i++)
		delete undoVector[i];

}
void UndoStack::undo(QImage& theImage)
{
	if(undoPointer >= 0)
	{
		if(undoPointer > 0)
			undoPointer--;
		theImage = *undoVector[undoPointer];
	}


}

void UndoStack::redo(QImage& theImage)
{
	int i = undoVector.size()-1;
	if(undoPointer < i)
	{
		++undoPointer;
		theImage = *undoVector[undoPointer];
	}

}
 void UndoStack::cleanUndoStack()
{

	for(int i = undoVector.size()-1;i > undoPointer;--i)
	{
		 delete undoVector[i];
		 undoVector.pop_back();
	}

}