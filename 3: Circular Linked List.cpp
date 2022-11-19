#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
};

class CircularList {
	node* head;
public:
	CircularList(){
		head = NULL;
	}
	void print() {
		node *temp = head;
		if (head != NULL) {
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
		}
	}
	void inbeg(int data) {
		node *ptr = new node;
		ptr->data = data;
		ptr->next = NULL;
		if (head == NULL) {
			head = ptr;
			ptr->next = head;
		}
		else {
			node *temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = head;
			head = ptr;
		}
	}
	void inend(int data) {
		node *ptr = new node;
		ptr->data = data;
		ptr->next = NULL;
		if (head == NULL) {
			head = ptr;
			ptr->next = head;
		}
		else {
			node *temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = head;
		}
	}
	void inany(int num, int pos) {
		if (head == NULL)
			cout << "No data found in the List yet.";
		else if (pos == 1)
			inbeg(num);
		else {
			node* newnode = new node;
			newnode->data = num;
			node* curNode = head;
			for (int i = 2; i <= pos - 1; i++)
				curNode = curNode->next;
			newnode->next = curNode->next;
			curNode->next = newnode;
		}
	}
	void delbeg() {
		node *temp = head;
		if (head == NULL) {
			cout << "\nList has no nodes";
			return;
		}
		if (head->next == head) {
			head = NULL;
			delete temp;
			return;
		}
		else {
			node *t = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			head = head->next;
			temp->next = head;
			delete t;
		}
	}
	void delend() {
		node *temp = head;
		if (head == NULL)
			cout << "\nList has no nodes";
		if (head->next == head) {
			head = NULL;
			delete temp;
		}
		else {
			node *prevtemp=head;
			while (temp->next != head) {
				prevtemp = temp;
				temp = temp->next;
			}
			prevtemp->next = temp->next;
			delete temp;
		}
	}
	void delany(int value){
		node *u, *v;
		int del, w = 0;
		del = value - 1;
		u = head;
		v = u;
		while (w != del)
		{
			v = u;
			u = u->next;
			w++;
		}
		v->next = u->next;
		free(u);
	}
};

int main() {
	CircularList l;
	l.inbeg(1); l.inbeg(2); l.inbeg(3);
	cout << "Insertion in Beg: ";l.print();
	l.inend(4); l.inend(5); l.inend(6);
	cout << "\nInsertion in End: "; l.print();
	l.inany(7, 2); l.inany(8, 5); l.inany(9, 8);
	cout << "\nInsertion in Any: "; l.print();
	l.delbeg(); l.delbeg();
	cout << "\n\nDeletion from Beg: "; l.print();
	l.delend(); l.delend();
	cout << "\nDeletion from End: "; l.print();
	l.delany(3); l.delany(2);
	cout << "\nDeletion from Any: "; l.print();
	system("pause");
}
