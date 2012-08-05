#ifndef UNDOSTACK_H_
#define UNDOSTACK_H_
#include <vector>
#include <QImage>
class UndoStack 
{
public:
	UndoStack(){undoPointer = -1;};
	~UndoStack();
	void undo(QImage& theImage);
	void redo(QImage& theImage);
	void saveUndoState(QImage& theImage);
	void cleanUndoStack();
	int size(){return undoVector.size() -1;};
	int getUndoPointer() const {return undoPointer;}

private:
	int undoPointer;
	std::vector<QImage*> undoVector;

};


#endif