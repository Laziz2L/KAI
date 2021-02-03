#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
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
};

void create(Tree **cur, int n) {
	int n_left;
	int n_right;
	if (n == 0) {
		*cur = NULL;
	}
	else {
		Tree *temp = new Tree;
		temp->val = rand() % 100;
		n_left = n / 2;
		n_right = n - n_left - 1;
		create(&temp->left, n_left);
		create(&temp->right, n_right);
		*cur = temp;
	}
}

void forward(Tree *cur, int lvl) {
	if (cur != NULL) {
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << cur->val << endl;
		forward(cur->left, lvl + 1);
		forward(cur->right, lvl + 1);
	}
}

void symmetric(Tree *cur, int lvl) {
	if (cur != NULL) {
		symmetric(cur->left, lvl + 1);
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << cur->val << endl;
		symmetric(cur->right, lvl + 1);
	}
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

int main() {
	Tree *root;
	int flag;
	int n;
	cout << "Enter the number of tree vertices" << endl;
	int_input(&n);
	create(&root, n);
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Forward" << endl;
			cout << "2 - Symmetric" << endl;
			cout << "3 - Reverse symmetric" << endl;
			cout << "4 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 4) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			forward(root, 0);
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			symmetric(root, 0);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			rev_symmetric(root, 0);
			cout << "\n";
			break;
		case 4:
			return 0;
			break;
		}
	}
}