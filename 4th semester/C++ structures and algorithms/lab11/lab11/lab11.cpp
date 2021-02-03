#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void int_input(int *in) {
	int flag;
	if (cin >> *in)
		flag = 0;
	else
		flag = 1;
	cin.clear();
	cin.ignore(32767, '\n');
	while (flag) {
		cout << "Enter the number\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

struct Tree {
	int val;
	Tree *right;
	Tree *left;

	Tree() {
		val = NULL;
		right = NULL;
		left = NULL;
	}
};
Tree *root = NULL;
Tree *parent = NULL;
bool found = false;

void search(Tree *tree, int val) {
	if (found || tree == NULL) {
		return;
	}
	if (tree->val == val) {
		found = true;
		parent = tree;
		return;
	}
	search(tree->left, val);
	search(tree->right, val);
}

void push() {
	int n;
	if (root == NULL) {
		cout << "\nThe root is empty. Creating...\n";
		root = new Tree();
		cout << "Enter value of root\n";
		int_input(&n);
		root->val = n;
		return;
	}
	cout << "\nEnter the value of parent-vertex\n";
	int_input(&n);
	found = false;
	search(root, n);
	if (!found) {
		cout << "There is no such vertex\n";
		return;
	}
	n = 0;
	if (parent->left == NULL) ++n;
	if (parent->right == NULL) ++n;
	if (n == 0) {
		cout << "This vertex already has 2 descedants\n";
		return;
	}
	if (n == 1) {
		if (parent->left == NULL) {
			cout << "Only left descedant is empty. Enter value for it\n";
			int_input(&n);
			parent->left = new Tree();
			parent->left->val = n;
			return;
		}
		cout << "Only right descedant is empty. Enter value for it\n";
		int_input(&n);
		parent->right = new Tree();
		parent->right->val = n;
		return;
	}
	int flag = 1;
	while (flag) {
		cout << "\nChoose the action and enter its number" << endl;
		cout << "1 - Enter left descedant" << endl;
		cout << "2 - Enter right descedant" << endl;
		int_input(&n);
		if (n >= 1 && n <= 2) {
			flag = 0;
		}
	}
	cout << "Enter value\n";
	if (n == 1) {
		int_input(&n);
		parent->left = new Tree();
		parent->left->val = n;
		return;
	}
	int_input(&n);
	parent->right = new Tree();
	parent->right->val = n;
}

void rev_symmetric(Tree *cur, int lvl) {
	if (cur != NULL) {
		rev_symmetric(cur->right, lvl + 1);
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << cur->val << endl;
		rev_symmetric(cur->left, lvl + 1);
	}
}

void delete_tree(Tree *cur) {
	if (cur == NULL) {
		return;
	}
	delete_tree(cur->left);
	delete_tree(cur->right);
	if (cur != root) {
		delete(cur);
	}
	else {
		root = NULL;
	}
}

int main() {
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Add new vertex" << endl;
			cout << "2 - Search" << endl;
			cout << "3 - Show (reverse symmetric)" << endl;
			cout << "4 - Delete" << endl;
			cout << "5 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 5) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			push();
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			found = false;
			cout << "Enter the value to search\n";
			int_input(&n);
			search(root, n);
			if (found) {
				cout << "Was found!\n";
			}
			else {
				cout << "Was not found!\n";
			}
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			rev_symmetric(root, 0);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			delete_tree(root);
			cout << "\n";
			break;
		case 5:
			return 0;
			break;
		}
	}
}