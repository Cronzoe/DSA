#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int data) {
		this->data = data;
		next = NULL;
	}
};

class LinkedList {
public:
	node* head;
	LinkedList() {
		head = NULL;
	}
	node* reverse(node* n) {
		if (n == NULL)
			return NULL;
		if (n->next == NULL) {
			head = n;
			return n;
		}
		node* node1 = reverse(n->next);
		node1->next = n;
		n->next = NULL;
		return n;
	}
	void print() {
		struct node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void push(int data) {
		node* temp = new node(data);
		temp->next = head;
		head = temp;
	}
};

int main() {
	LinkedList l;
	l.push(20);		l.push(4);		l.push(15);		l.push(85);
	cout << "Given linked list\n";	l.print();
	l.reverse(l.head);
	cout << "\nReversed Linked list \n";	l.print();
	system("pause");
}
