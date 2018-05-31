#ifndef QUEUE_H

#define QUEUE_H

#define MAX_COUNT 50 

class Queue {
private:
	int *sQueue;
	int nCount;

public:
	Queue();
	~Queue();
	int Insert(int c);
	int Delete();
	void Clear();
	int DeleteElemsOne();
	void Print();
};

#endif