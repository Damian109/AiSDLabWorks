#include <iostream>

#define L1

#ifdef L1
#include"Stack.h"
#endif

#ifdef L2
#include "Queue.h"
#endif

#include "pSort.h"

using namespace std;

void Function1() {
#ifdef L1
	Stack *S = new Stack();
#endif
#ifdef L2
	Queue *Q = new Queue();
#endif
	int T = 10, t;
	while (T) {
		cin >> T;
		switch (T) {
		case 1:
#ifdef L1
			cin >> t;
			S->Push(t);
			cout << "Push " << t << endl;
#endif
#ifdef L2
			cin >> t;
			Q->Insert(t);
#endif
			break;
		case 2:
#ifdef L1
			cout << "Pop " << S->Pop() << endl;
#endif
#ifdef L2
			Q->Delete();
#endif
			break;
		case 3:
#ifdef L1
			cout << "FindMax = " << S->FindMax() << endl;
#endif
#ifdef L2
			Q->DeleteElemsOne();
#endif
			break;
		case 4:
#ifdef L1
			S->Print();
#endif
#ifdef L2
			Q->Print();
#endif
			break;
		case 5:
#ifdef L1
			cout << "StackTop = " << S->StackTop() << endl;
#endif
			break;
		case 0:
			break;
		}
	}
#ifdef L1
	delete S;
#endif
#ifdef L2
	delete Q;
#endif
}

void Function3()
{
	pSort ps;
	while (true) {
		system("CLS");
		cout << "1 - Read, 2 - Print, 3 - Sort, 4 - ReadFile, 5 - PrintFile, 6 - Exit" << endl;
		int t;
		cin >> t;
		switch (t) {
		case 1:
			ps.Clear();
			ps.Read();
			break;
		case 2:
			ps.Print();
			break;
		case 3:
			ps.SortShaker();
			break;
		case 4:
			ps.Clear();
			ps.Open();
			break;
		case 5:
			ps.Close();
			break;
		case 6:
			return;
		}
	}
}

int main() {

	return 0;
}