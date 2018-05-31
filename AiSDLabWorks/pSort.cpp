#include <fstream>
#include <iostream>
#include "pSort.h"

using namespace std;

pSort::pSort() {
	MAS = new int[100];
	nMas = 0;
}

pSort::~pSort() {
	delete[] MAS;
}

void pSort::Open() {
	ifstream myif("TEXT.txt");
	myif >> nMas;
	for (int i = 0; i < nMas; i++)
		myif >> MAS[i];
	myif.close();
}

void pSort::Close() {
	ofstream myof("TEXT.txt");
	myof << nMas << endl;
	for (int i = 0; i < nMas; i++)
		myof << MAS[i] << endl;
	myof.close();
}

void pSort::Clear() {
	for (int i = 0; i < 100; i++)
		MAS[i] = 0;
	nMas = 0;
}

void pSort::Read() {
	system("CLS");
	cout << "Enter number of values";
	cin >> nMas;
	for (int i = 0; i < nMas; i++)
		cin >> MAS[i];
}

void pSort::Print() {
	system("CLS");
	for (int i = 0; i < nMas; i++)
		cout << MAS[i] << " ";
	_getwch();
}

void pSort::SortExchange() {
	for (int i = 0; i < nMas - 1; i++)
		for (int j = 0; j < nMas - i - 1; j++)
			if (MAS[j] > MAS[j + 1]) {
				int tmp = MAS[j];
				MAS[j] = MAS[j + 1];
				MAS[j + 1] = tmp;
			}
}


void pSort::SortShaker() {
	for (int Left = 0, Right = nMas - 1; Left < Right; ) {
		for (int i = Left; i < Right; i++) {
			if (MAS[i] > MAS[i + 1]) {
				int tmp = MAS[i];
				MAS[i] = MAS[i + 1];
				MAS[i + 1] = tmp;
			}
		}
		Right--;
		for (int i = Right; i >Left; i--) {
			if (MAS[i - 1] > MAS[i]) {
				int tmp = MAS[i - 1];
				MAS[i - 1] = MAS[i];
				MAS[i] = tmp;
			}
		}
		Left++;
	}
}

void pSort::SortQuick() {
	QuickSort(MAS, 0, nMas - 1);
}

void QuickSort(int mas[], int left, int right) {
	int l = left, r = right;
	int mid = mas[(l + r) / 2];
	while (l <= r) {
		while ((mas[l] < mid) && (l <= right))
			l++;
		while ((mas[r] > mid) && (r >= left))
			r--;
		if (l <= r) {
			int tmp;
			tmp = mas[l];
			mas[l] = mas[r];
			mas[r] = tmp;
			l++;
			r--;
		}
	}
	if (r > left)
		QuickSort(mas, left, r);
	if (l < right)
		QuickSort(mas, l, right);
	return;
}


int Fibonachi(int x) {
	int F, H;
	if (x == 0 || x == 1)
		return x;
	if (x >= 2) {
		F = Fibonachi(x - 1);
		H = Fibonachi(x - 2);
		return F + H;
	}
	return -1;
}

int pSort::SearchFibonachi(int S) {
	int j, Mid;
	int result;
	int F, H;
	bool Fin;
	j = 1;
	while (Fibonachi(j) < nMas + 1)
		j++;
	Mid = nMas - Fibonachi(j - 2) + 1;
	F = Fibonachi(j - 2);
	H = Fibonachi(j - 3);
	Fin = false;
	while (S != MAS[Mid] && !Fin) {
		if (Mid <= 0 || S > MAS[Mid])
			if (F == 1)
				Fin = true;
			else {
				Mid = Mid + H;
				F = F - H;
				H = H - F;
			}
		else
			if (H == 0)
				Fin = true;
			else {
				Mid = Mid - H;
				int tmp = F - H;
				F = H;
				H = tmp;
			}
			Fin ? result = 0 : result = Mid + 1;
	}
	return result;
}


int pSort::SearchPosl(int S) {
	for (int i = 0; i < nMas; i++)
		if (MAS[i] == S)
			return i + 1;
	return 0;
}

int BinarySearch(int mas[], int key, int left, int right) {
	if (left > right)
		return -1;
	int mid = (left + right) >> 1;
	if (mas[mid] < key)
		return BinarySearch(mas, key, mid + 1, right);
	if (mas[mid] > key)
		return BinarySearch(mas, key, left, mid - 1);
	return mid;
}

int pSort::SearchBinary(int S) {
	int t = BinarySearch(MAS, S, 0, nMas - 1);
	if (t == -1)
		return 0;
	else
		return t + 1;
}
