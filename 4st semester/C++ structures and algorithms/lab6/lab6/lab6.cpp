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
};

struct List {
	ListElement *head;

	List() {
		head = new ListElement();
		head->next = NULL;
	}

	void show() {
		if (head->next == NULL) {
			cout << "\nThe list is empty!\n";
			return;
		}
		ListElement *cur = head->next;
		cout << "\nList :\n";
		while (cur) {
			cout << cur->value << endl;
			cur = cur->next;
		}
	}

	ListElement* search_ptr() {
		int val;
		input(&val);
		ListElement *cur = head;
		while (cur != NULL) {
			if (cur->value == val) {
				return cur;
			}
			cur = cur->next;
		}
		return NULL;
	}

	void push_to_end(int val) {
		ListElement *add;
		add->value = val;
		add->next = NULL;
		ListElement *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = add;
	}

	void push_first() {
		cout << "\nThe list is empty yet. Add first element:\n";
		int val;
		input(&val);
		ListElement *add = new ListElement();
		add->value = val;
		add->next = NULL;
		head->next = add;
	}

	void push_after() {
		if (head->next == NULL) {
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
		after_this->next = add;
	}

	void push_before() {
		if (head->next == NULL) {
			push_first();
			return;
		}
		ListElement *before_this;
		cout << "\nEnter the element before which there will be an addition\n";
		before_this = search_ptr();
		if (before_this == 0) {
			cout << "\nThere is no such element\n";
			return;
		}
		ListElement *after_this = head;
		while (after_this->next != before_this) {
			after_this = after_this->next;
		}
		int val;
		cout << "\nEnter new element\n";
		input(&val);
		ListElement *add = new ListElement();
		add->value = val;
		add->next = after_this->next;
		after_this->next = add;
	}

	void search() {
		if (head->next == NULL) {
			cout << "\nThe list is empty!\n";
			return;
		}
		int val;
		cout << "\nEnter the element to search\n";
		input(&val);
		ListElement *cur = head->next;
		int i = 1;
		while (cur) {
			if (cur->value == val) {
				cout << "\nThe number in list of element " << val << " is " << i << endl;
				return;
			}
			cur = cur->next;
			++i;
		}
		cout << "\nThere is no such element\n";
	}

	ListElement* pop() {
		if (head->next == NULL) {
			cout << "\nThe list is empty!\n";
			return NULL;
		}
		cout << "\nEnter the element to delete\n";
		ListElement *del = search_ptr();
		if (del == NULL) {
			cout << "\nThere is no such element\n";
			return NULL;
		}
		ListElement *del_prev = head;
		while (del_prev->next != del) {
			del_prev = del_prev->next;
		}
		del_prev->next = del->next;
		del->next = NULL;
		return del;
	}
};

void add_to_begin(List *list, ListElement *el) {
	if (el == NULL)
		return;
	el->next = list->head->next;
	list->head->next = el;
}

int main() {
	List list;
	List* rmd = new List();
	ListElement* del;
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show the list" << endl;
			cout << "2 - Add new element after some" << endl;
			cout << "3 - Add new element before some" << endl;
			cout << "4 - Delete element" << endl;
			cout << "5 - Search element" << endl;
			cout << "6 - Show the list (like stack) of deleted elements" << endl;
			cout << "7 - Terminate the program" << endl;
			input(&n);
			if (n >= 1 && n <= 6) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			list.show();
			break;
		case 2:
			list.push_after();
			break;
		case 3:
			list.push_before();
			break;
		case 4:
			del = list.pop();
			add_to_begin(rmd, del);
			break;
		case 5:
			list.search();
			break;
		case 6:
			rmd->show();
			break;
		case 7:
			return 0;
			break;
		}
	}
}