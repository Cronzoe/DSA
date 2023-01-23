#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node * left, *right;
	Node() {
		left = right = NULL;
	}
	Node(int item) {
		data = item;
		left = right = NULL;
	}
};

class BinarySearchTree {
	Node* root;
public:
	BinarySearchTree() {
		root = NULL;
	}
	bool Empty() {
		return root == NULL;
	}
	void Insert(Node *root, int num) {
		if (root == NULL) {
			Node* root = new Node;
			root->data = num;
			root->left = NULL;
			root->right = NULL;
		}
		else if (num < root->data)
			Insert(root->left, num);
		else
			Insert(root->right, num);
	}
	bool Search(Node *temp, int num) {
		if (root == NULL)
			return false;
		else if (num == root->data)
			return true;
		else if (num > root->data)
			Search(temp->right, num);
		else
			Search(temp->left, num);
	}
	Node* getParent(Node* curr, int num) {
		if ((curr->left->data == num) || (curr->right->data == num))
			return curr;
		else if (num < curr->data)
			return getParent(curr->left, num);
		else if (num > curr->data)
			return getParent(curr->right, num);
	}
	Node* FindMin(Node* curr) {
		if (curr->left == NULL)
			return curr;
		else
			return FindMin(curr->left);
	}
	void Preorder(Node* root) {
		if (root != NULL) {
			cout << root->data << " ";
			Preorder(root->left);
			Preorder(root->right);
		}
		else return;
	}
	void Postorder(Node* root) {
		if (root != NULL) {
			Postorder(root->left);
			Postorder(root->right);
			cout << root->data << " ";
		}
		else return;
	}
	void Inorder(Node* root) {
		if (root != NULL) {
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
		else return;
	}
	int countleafnodes(Node *ptr) {
		if (ptr == NULL)
			return 0;
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;
		else
			return countleafnodes(ptr->left) + countleafnodes(ptr->right);
	}
};
