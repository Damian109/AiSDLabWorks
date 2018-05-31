#ifndef STACK_H

#define STACK_H

#define MAX_COUNT 50 

class Stack {
private:
	int *sStack;
	int nCount;

public:
	Stack();
	~Stack();
	int Push(int c);
	int Pop();
	int StackTop();
	void Clear();
	int FindMax();
	void Print();
};

#endif