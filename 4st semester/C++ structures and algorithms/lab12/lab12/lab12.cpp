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
	int count;
};
Tree *root = NULL;

int search(int val) {
	Tree *cur = root;
	bool stop = false;
	while (cur != NULL && !stop) {
		if (cur->val < val) cur = cur->right;
		else if (cur->val > val) cur = cur->left;
		else stop = true;
	}
	if (cur == NULL) return 0;
	return cur->count;
}

void rec_push(Tree *&cur, int val) {
	if (cur == NULL) {
		cur = new Tree;
		cur->val = val;
		cur->right = NULL;
		cur->left = NULL;
		cur->count = 1;
		return;
	}
	if (cur->val < val) {
		rec_push(cur->right, val);
	}
	else if (cur->val > val) {
		rec_push(cur->left, val);
	}
	else {
		cur->count++;
	}
}

void push(int val) {
	if (root == NULL)
	{
		root = new Tree;
		root->val = val;
		root->right = NULL;
		root->left = NULL;
		root->count = 1;
		return;
	}
	Tree *parent = root;
	Tree *current = root;
	while (current != NULL)
	{
		parent = current;
		if (val > current->val) {
			current = current->right;
		}
		else if (val < current->val) {
			current = current->left;
		}
		else {
			current->count++;
			current = NULL;
		}
	}
	if (val > parent->val)
	{
		parent->right = new Tree;
		parent->right->val = val;
		parent->right->count = 1;
		parent->right->left = NULL;
		parent->right->right = NULL;
	}
	else if (val < parent->val)
	{
		parent->left = new Tree;
		parent->left->val = val;
		parent->left->count = 1;
		parent->left->left = NULL;
		parent->left->right = NULL;
	}
}

void rev_symmetric(Tree *cur, int lvl) {
	if (cur != NULL) {
		rev_symmetric(cur->right, lvl + 1);
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << cur->val << "(" << cur->count << ") " << endl;
		rev_symmetric(cur->left, lvl + 1);
	}
}

void show(Tree *cur) {
	if (cur != NULL) {
		show(cur->left);
		cout << cur->val << "(" << cur->count << ") ";
		show(cur->right);
	}
}

void changer(Tree *&cur, Tree *&temp) {
	if (cur->right != NULL) {
		changer(cur->right, temp);
	}
	else {
		temp->val = cur->val;
		temp = cur;
		cur = cur->left;
	}
}

void pop(Tree *&vertex, int val) {
	if (vertex != NULL) {
		if (val > vertex->val) pop(vertex->right, val);
		else if (val < vertex->val) pop(vertex->left, val);
		else {
			Tree *temp = vertex;
			if (vertex->right == NULL) vertex = vertex->left;
			else if (vertex->left == NULL) vertex = vertex->right;
			else changer(vertex->left, temp);
			delete temp;
		}
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
			cout << "1 - Create tree" << endl;
			cout << "2 - Add new vertex (recursive)" << endl;
			cout << "3 - Add new vertex (non-recursive)" << endl;
			cout << "4 - Search" << endl;
			cout << "5 - Show (reverse symmetric)" << endl;
			cout << "6 - Show orderly in line" << endl;
			cout << "7 - Delete vertex" << endl;
			cout << "8 - Delete tree" << endl;
			cout << "9 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 9) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			cout << "Enter the number of vertices\n";
			int_input(&n);
			while (n > 0) {
				rec_push(root, rand() % 100);
				--n;
			}
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			cout << "Enter the value\n";
			int_input(&n);
			rec_push(root, n);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			cout << "Enter the value\n";
			int_input(&n);
			push(n);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			cout << "Enter the value to search\n";
			int_input(&n);
			n = search(n);
			if (n == 0) {
				cout << "Was not found!\n";
			}
			else {
				cout << "Was found! Count = " << n << endl;
			}
			cout << "\n";
			break;
		case 5:
			cout << "\n";
			rev_symmetric(root, 0);
			cout << "\n";
			break;
		case 6:
			cout << "\n";
			show(root);
			cout << "\n";
			break;
		case 7:
			cout << "\n";
			cout << "Enter the value\n";
			int_input(&n);
			pop(root, n);
			cout << "\n";
			break;
		case 8:
			cout << "\n";
			delete_tree(root);
			cout << "\n";
			break;
		case 9:
			return 0;
			break;
		}
	}
}