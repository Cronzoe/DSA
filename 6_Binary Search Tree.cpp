#include <iostream>
using namespace std;
class tree_node {
public:
	tree_node *left;
	tree_node *right;
	int data;
};
class bst {
	tree_node *root;
	tree_node* Search(tree_node *temp, int value) {
		if (temp == NULL || temp->data == value)
			return temp;
		if (temp->data < value)
			return Search(temp->right, value);
		return Search(temp->left, value);
	}
	int getHeight(tree_node* temp) {
		if (temp == NULL)
			return -1;
		int left = getHeight(temp->left);
		int right = getHeight(temp->right);
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
public:
	bst() {
		root = NULL;
	}
	int isempty() {
		return(root == NULL);
	}
	void insert(int item) {
		tree_node *p = new tree_node;
		tree_node *parent;
		p->data = item;
		p->left = NULL;
		p->right = NULL;
		parent = NULL;
		if (isempty())
			root = p;
		else {
				tree_node *ptr;
			ptr = root;
			while (ptr != NULL) {
				parent = ptr;
				if (item > ptr->data)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			if (item < parent->data)
				parent->left = p;
			else
				parent->right = p;
		}
	}
	void Search(int value) {
		if (Search(root, value))
			cout << endl << value << " is Founded\n";
		else
			cout << endl << value << " is Not Founded\n";
	}
	void inordertrav() {
		inorder(root);
	}
	void inorder(tree_node *ptr) {
		if (ptr != NULL) {
			inorder(ptr->left);
			cout << " " << ptr->data << " ";
			inorder(ptr->right);
		}
	}
	void postordertrav() {
		postorder(root);
	}
	void postorder(tree_node *ptr) {
		if (ptr != NULL) {
			postorder(ptr->left);
			postorder(ptr->right);
			cout << " " << ptr->data << " ";
		}
	}
	void preordertrav() {
		preorder(root);
	}
	void preorder(tree_node *ptr) {
		if (ptr != NULL) {
			cout << " " << ptr->data << " ";
			preorder(ptr->left);
			preorder(ptr->right);
		}
	}
	int countleaf() {
		return leaf(root);
	}
	int leaf(tree_node *ptr) {
		if (ptr == NULL)
			return 0;
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;
		else
			return leaf(ptr->left) + leaf(ptr->right);
	}
	int minElement() {
		tree_node* current = root;
		while (current->left != NULL)
			current = current->left;
		  return(current->data);
	}
	int maxElement() {
		tree_node* current = root;
		while (current->right != NULL)
			current = current->right;
		return(current->data);
	}
	void getHeight() {
		cout << "\nHeight of Tree\t: " << getHeight(root) ;
	}
};

int main() {
	bst b;
	b.insert(52);
	b.insert(25);
	b.insert(50);
	b.insert(15);
	b.insert(40);
	b.insert(45);
	b.insert(20);
	b.Search(20);
	b.Search(30);
	cout << "\n-----------------------------------------------";
	cout << "\nIn-Order\t: ";
	b.inordertrav();
	cout << endl << "\nPost-Order\t: ";
	b.postordertrav();
	cout << endl << "\nPre-Order\t: ";
	b.preordertrav();
	cout << "\n-----------------------------------------------\n";
	b.getHeight();
	cout << "\nLeaf Count\t: " << b.countleaf();
	cout << "\nMinimum Node\t: " << b.minElement();
	cout << "\nMaximum Node\t: " << b.maxElement() << "\n\n";
	system("pause");
}