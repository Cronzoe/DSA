#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* prev;
};

class DoublyList {
	
public:node* head;
	DoublyList() {
		head = NULL;
	}
	void inbeg(int newdata) {
		node* newnode = new node;
		newnode->data = newdata;
		newnode->prev = NULL;
		newnode->next = head;
		if (head != NULL)
			head->prev = newnode;
		head = newnode;
	}
	void inend(int newdata) {
		node* new_node = new node;
		node* last = head;
		new_node->data = newdata;
		new_node->next = NULL;
		if (head == NULL) {
			new_node->prev = NULL;
			head = new_node;
			return;
		}
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	void inany(int x, int p) {
		node *temp = new node;
		temp->data = x;
		temp->next = NULL;
		if (p == 1) {
			temp->next = head;
			head = temp;
			return;
		}
		node *temp2 = head;
		for (int i = 0; i < p - 2; i++) {
			temp2 = temp2->next;
		}
		temp->next = temp2->next;
		temp2->next = temp;
	}
	void delbeg() {
		if (head == NULL)
			return;
		else if (head->next == NULL)
			head = NULL;
		else {
			node* n = head->next;
			node* d = n->prev;
			n->prev = NULL;
			head = n;
			delete d;
		}
	}
	void delend() {
		node* n = head;
		if (head == NULL) {
			cout << "Linked List is Empty.";
			return;
		}
		else if (head->next == NULL) {
			head = NULL;
			free(head);
		}
		while (n->next != NULL)
			n = n->next;
		if(n->next == NULL) {
			n->prev->next = NULL;
			free(n);
		}
	}
	void print() {
		node* ptr = head;
		if (ptr != NULL) {
			while (ptr != NULL) {
				cout << ptr->data << " -> ";
				ptr = ptr->next;
			}
			cout << "NULL";
		}
		else
			cout << "Linked List is Empty.";
	}
};

int main() {
	DoublyList l;
	l.inbeg(1); l.inbeg(2);
	cout << "Insertion in Beg: "; l.print();
	l.inend(4); l.inend(5);
	cout << "\nInsertion in End: "; l.print();
	l.delbeg();
	cout << "\nDelete from Beg: "; l.print();
	l.delend();
	cout << "\nDelete from End: "; l.print();
}