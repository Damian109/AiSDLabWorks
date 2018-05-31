#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
	sQueue = new int[MAX_COUNT];
	nCount = 0;
}

Queue::~Queue() {
	delete[] sQueue;
}

int Queue::Insert(int c) {
	if (nCount >= MAX_COUNT)
		return -1;
	sQueue[nCount++] = c;
	return 0;
}

int Queue::Delete() {
	if (nCount == 0)
		return -1;
	for (int i = 0; i < nCount - 1; i++)
		sQueue[i] = sQueue[i + 1];
	nCount--;
	return 0;
}

void Queue::Clear() {
	for (int i = 0; i < MAX_COUNT; i++)
		sQueue[i] = 0;
	nCount = 0;
}

int Queue::DeleteElemsOne() {
	if (nCount == 0)
		return -1;
	int N = sQueue[0];
	for (int i = 0; i < nCount - 1; i++) {
		if (sQueue[i] == N)
			for (int j = i; j < nCount - 1; j++) {
				sQueue[j] = sQueue[j + 1];
				i--;
				nCount--;
			}
	}
	return 0;
}

void Queue::Print() {
	for (int i = 0; i < nCount; i++)
		cout << sQueue[i] << " ";
	cout << endl;
}