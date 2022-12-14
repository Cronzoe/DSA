#include<iostream>
using namespace std;

class queue {
	int* arr;
	int size;
	int rear, front;
public:
	queue(int size) {
		arr = new int[size];
		this->size = size;
		rear = front = -1;
	}
	bool empty() {
		if (rear == -1 && front == -1)
			return true;
		return false;
	}
	bool full() {
		if (rear == size - 1)
			return true;
		return false;
	}
	void enqueue(int data) {
		if (full())
			cout << "\nQueue is Full.\n";
		else if (empty())
			front = rear = 0;
		else
			rear++;
		arr[rear] = data;
	}
	int dequeue() {
		int data;
		if (empty()) {
			cout << "\nQueue is Empty.\n";
			return;
		}
		else if (front == rear) {
			data = arr[front];
			front = rear = -1;
		}
		else {
			data = arr[front];
			front++;
		}
		return data;
	}
	int front() {
		if (empty())
			cout << "\nQueue is Empty.\n";
		else
			return  arr[front];
	}
	void display() {
		if (front == -1)
			cout << "\nQueue is Empty.\n";
		else
			for (int i = front; i <= rear; i++)
				cout << arr[i];
	}
};

class Circular_queue {
	int* arr;
	int size;
	int front, rear;
public:
	Circular_queue(int size) {
		arr = new int[size];
		this->size = size;
		rear = front = -1;
	}
	bool full() {
		if (front == rear + 1)
			return true;
		return false;
	}
	bool empty() {
		if (front == -1)
			return true;
		return false;
	}
	void enqueue(int data) {
		if (full())
			cout << "\nCircular Queue is Full.\n";
		else {
			if (front == -1) 
				front = 0;
			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	int dequeue() {
		int data;
		if (empty()) {
			cout << "\nCircular Queue is Empty\n";
			return;
		}
		else {
			data = arr[front];
			if (front == rear) {
				front = -1;
				rear = -1;
			}
			else
				front = (front + 1) % size;
			return data;
		}
	}
	int front() {
		if (empty())
			cout << "\nQueue is Empty.\n";
		else
			return  arr[front];
	}
	void display() {
		if (empty()) {
			cout << "\nCircular Queue is Empty.\n";
		}
		else
			for (int i = front; i != rear; i = (i + 1) % size)
				cout << arr[i];
	}
};

class node {
public:
	int data;
	node* next;
};

class Linked_queue {
	node* front;
	node* rear;
public:
	Linked_queue() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int data) {
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		if (front == NULL && rear == NULL)
			front = rear = temp;
		else
			rear->next = temp;
		rear = temp;
	}
	int dequeue() {
		node* temp = front;
		if (front == NULL) {
			cout << "\nLinked Queue is Empty.\n"; 
			return;
		}
		else if (front == rear)
			front = rear = NULL;
		else
			front = front->next;
		delete temp;
	}
	int front(){
		if (front == NULL) {
			cout << "\nLinked Queue is empty\n";
			return;
		}
		return front->data;
	}
	void display(){
		node* temp = front;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
