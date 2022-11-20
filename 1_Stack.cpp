#include<iostream>
using namespace std;

class stack {
	int *arr;
	int size;
	int Top;
public:
	stack(int size) {
		arr = new int[size];
		this->size = size;
		Top = -1;
	}
	bool empty() {
		if (Top == -1)
			return true;
		return false;
	}
	bool full() {
		if (Top == size - 1)
			return true;
		return false;
	}
	void push(int x) {
		if (!full())
			arr[++Top] = x;
		else
			cout << "Stack Over-Flow";
	}
	int pop() {
		if (!empty())
			return arr[Top--];
		else
			cout << "Stack Under-Flow";
		return 0;
	}
	int top() {
		if (!empty())
			return arr[Top];
		else
			cout << "Stack empty";
	}
	void display() {
		if (!empty())
			for (int i = Top; i >= 0; i--)
				cout << arr[i] << " ";
		else
			cout << "Stack Empty";
	}
};
