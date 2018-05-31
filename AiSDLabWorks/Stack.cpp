#include <iostream>
#include"Stack.h"

using namespace std;

Stack::Stack() {
	sStack = new int[MAX_COUNT];
	nCount = 0;
}

Stack::~Stack() {
	delete[] sStack;
}

int Stack::Push(int c) {
	if (nCount >= MAX_COUNT - 1)
		return -1;
	sStack[nCount++] = c;
	return 0;
}

int Stack::Pop() {
	if (nCount == 0)
		return -1;
	nCount--;
	return sStack[nCount];
}

int Stack::StackTop() {
	if (nCount == 0)
		return -1;
	return sStack[nCount - 1];
}

void Stack::Clear() {
	for (int i = 0; i < MAX_COUNT; i++)
		sStack[i] = 0;
	nCount = 0;
}

int Stack::FindMax() {
	if (nCount == 0)
		return -1;
	int N = nCount;
	int Max = sStack[0];
	int cMax = 0;
	Stack *St = new Stack();
	for (int i = nCount - 1; i >= 0; i--) {
		if (Max < sStack[i])
			Max = sStack[i];
		St->Push(this->Pop());
	}
	this->nCount = 0;
	for (int i = 0; i < N; i++)
		if (Max != St->StackTop()) {
			this->Push(St->Pop());
		}
		else {
			St->Pop();
		}
		return Max;
}

void Stack::Print() {
	for (int i = nCount - 1; i >= 0; i--)
		cout << sStack[i] << " ";
	cout << endl;
}