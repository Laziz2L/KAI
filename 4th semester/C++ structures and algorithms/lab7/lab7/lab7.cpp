#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

void input(int *in) {
	int flag = 1;
	while (flag) {
		cout << "Enter the number\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

struct ListElement {
	int value;
	ListElement *next;
	ListElement *prev;
};

struct List {
	ListElement *head;

	List() {
		head = new ListElement();
		head->next = NULL;
		head->prev = NULL;
	}

	void show() {
		if (head->next == NULL || head->next == head) {
			cout << "\nThe list is empty!\n";
			return;
		}
		ListElement *cur = head->next;
		cout << "\nList :\n";
		while (cur != head) {
			cout << cur->value << endl;
			cur = cur->next;
		}
	}

	void show_rev() {
		if (head->next == NULL || head->next == head) {
			cout << "\nThe list is empty!\n";
			return;
		}
		ListElement *cur = head->prev;
		cout << "\nList :\n";
		while (cur != head) {
			cout << cur->value << endl;
			cur = cur->prev;
		}
	}

	ListElement* search_ptr() {
		int val;
		input(&val);
		ListElement *cur = head->next;
		while (cur != head) {
			if (cur->value == val) {
				return cur;
			}
			cur = cur->next;
		}
		return NULL;
	}

	void push_first() {
		cout << "\nThe list is empty yet. Add first element:\n";
		int val;
		input(&val);
		ListElement *add = new ListElement();
		add->value = val;
		add->next = head;
		add->prev = head;
		head->next = add;
		head->prev = add;
	}

	void push_after() {
		if (head->next == NULL || head->next == head) {
			push_first();
			return;
		}
		ListElement *after_this;
		cout << "\nEnter the element after which there will be an addition\n";
		after_this = search_ptr();
		if (after_this == NULL) {
			cout << "\nThere is no such element\n";
			return;
		}
		cout << "\nEnter new element\n";
		int val;
		input(&val);
		ListElement *add = new ListElement();
		add->value = val;
		add->next = after_this->next;
		add->prev = after_this;
		add->prev->next = add;
		add->next->prev = add;
	}

	void push_before() {
		if (head->next == NULL || head->next == head) {
			push_first();
			return;
		}
		ListElement *before_this;
		cout << "\nEnter the element before which there will be an addition\n";
		before_this = search_ptr();
		if (before_this == NULL) {
			cout << "\nThere is no such element\n";
			return;
		}
		int val;
		cout << "\nEnter new element\n";
		input(&val);
		ListElement *add = new ListElement();
		add->value = val;
		add->next = before_this;
		add->prev = before_this->prev;
		add->prev->next = add;
		add->next->prev = add;
	}

	void search() {
		if (head->next == NULL || head->next == head) {
			cout << "\nThe list is empty!\n";
			return;
		}
		int val;
		cout << "\nEnter the element to search\n";
		input(&val);
		ListElement *cur = head->next;
		int i = 1;
		while (cur != head) {
			if (cur->value == val) {
				cout << "\nThe number in list of element " << val << " is " << i << endl;
				return;
			}
			cur = cur->next;
			++i;
		}
		cout << "\nThere is no such element\n";
	}

	void search_rev() {
		if (head->next == NULL || head->next == head) {
			cout << "\nThe list is empty!\n";
			return;
		}
		int val;
		cout << "\nEnter the element to search\n";
		input(&val);
		ListElement *cur = head->next;
		int i = 0;
		while (cur != head) {
			cur = cur->next;
			++i;
		}
		cur = head->prev;
		while (cur != head) {
			if (cur->value == val) {
				cout << "\nThe number in list of element " << val << " is " << i << endl;
				return;
			}
			cur = cur->prev;
			--i;
		}
		cout << "\nThere is no such element\n";
	}

	void pop() {
		if (head->next == NULL || head->next == head) {
			cout << "\nThe list is empty!\n";
			return;
		}
		cout << "\nEnter the element to delete\n";
		ListElement *del = search_ptr();
		if (del == NULL) {
			cout << "\nThere is no such element\n";
			return;
		}
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
	}
};

int main() {
	List list;
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show the list" << endl;
			cout << "2 - Show the list in reverse" << endl;
			cout << "3 - Add new element after some" << endl;
			cout << "4 - Add new element before some" << endl;
			cout << "5 - Delete element" << endl;
			cout << "6 - Search element" << endl;
			cout << "7 - Search element in reverse" << endl;
			cout << "8 - Terminate the program" << endl;
			input(&n);
			if (n >= 1 && n <= 8) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			list.show();
			break;
		case 2:
			list.show_rev();
			break;
		case 3:
			list.push_after();
			break;
		case 4:
			list.push_before();
			break;
		case 5:
			list.pop();
			break;
		case 6:
			list.search();
			break;
		case 7:
			list.search_rev();
			break;
		case 8:
			return 0;
			break;
		}
	}
}