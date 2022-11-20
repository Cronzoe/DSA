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

class node {
public:
	int data;
	node* next;
};

class Linked_stack {
	node* top;
public:
	Linked_stack() {
		top = NULL;
	}
	void push(int x) {
		node* ptr = new node;
		ptr->data = x;
		ptr->next = NULL;
		if (top == NULL)
			ptr->next = NULL;
		else
			ptr->next = top;
		top = ptr;
	}
	int pop() {
		if (top == NULL) {
			cout << "The stack is empty!!!";
			return -1;
		}
		node *temp = top;
		top = top->next;
		int retValue = temp->data;
		delete temp;
		return retValue;
	}
	void display() {
		if (top == NULL)
			cout << "\nStack is Empty.\n";
		node *ptr = top;
		cout << "Stack elements are: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	int Top() {
		return top->data;
	}
};