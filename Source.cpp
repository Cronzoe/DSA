#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *next;
};

node *head = NULL;

void inend(int x){
	node * ptr = new node;
	ptr->data = x;
	ptr->next = NULL;
	if (head == 0) {
		head = ptr;
	}
	else {
		node* temp = head;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = ptr;
	}
}

void inbeg(int x) {
	node *n = new node;
	n->data = x;
	n->next = head;
	head = n;
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
	node *n = head;
	if (head == NULL) {
		cout << "Linked List Empty!!\n";
		return;
	}
	head = head->next;
	delete n;
}

void delend() {
	node *p = head;
	while (p->next->next != NULL)
		p = p->next;
	node*q = p->next ;
	p->next = NULL;
	delete q;
}

void delany(int x) {
	if (head == NULL) {
		cout << "Linked List Empty!!\n";
		return;
	}
	if (head->next == NULL) {
		delbeg();
		return;
	}
	node* temp = head;
	while (temp->next->data != x)
		temp = temp->next;
	node *del = temp->next;
	temp->next = temp->next->next;
}

void print() {
	node *n=head;
	if (n != NULL) {
		cout << "Element of Linked List: ";
		while (n != NULL)
		{
 			cout << n->data << " -> ";
			n = n->next;
		}
		cout << "NULL" << endl;
	}
	else
		cout << "Linked List is Empty...\n";
}

int main() {
	print();
	inend(1);
	inend(2); 
	inend(3);
	inend(4);
	inend(5);
	print();
	delbeg();
	print();
	inbeg(6);
	inbeg(7);
	print();
	inany(8, 4);
	print();
	delend();
	print();
	system("pause");
}