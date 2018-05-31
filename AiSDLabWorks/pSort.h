#pragma once

class pSort {
	int* MAS;
	int nMas;
public:
	pSort();
	~pSort();
	void Open();
	void Close();
	void Clear();
	void Read();
	void Print();
	void SortExchange();
	void SortShaker();
	void SortQuick();
	int SearchFibonachi(int S);
	int SearchPosl(int S);
	int SearchBinary(int S);
};

void QuickSort(int[], int, int);