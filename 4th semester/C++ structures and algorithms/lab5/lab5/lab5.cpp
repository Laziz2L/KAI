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
	int next;
};

struct List {
	int len;
	ListElement *arr;
	int count;

	List(int length) {
		len = length;
		arr = new ListElement[length + 1];
		count = 0;
		arr[0].next = 1;
		arr[0].value = 0;
		for (int i = 1; i <= len; i++) {
			arr[i].next = -1;
			arr[i].value = 0;
		}
	}

	int search_ind() {
		if (count == 0) {
			cout << "\nThe list is empty!\n";
			return -1;
		}
		int val;
		input(&val);
		int cur = arr[0].next;
		int i = 0;
		while (cur != 0 && i < count) {
			if (arr[cur].value == val)
				return cur;
			cur = arr[cur].next;
			++i;
		}
		return 0;
	}

	void push_first() {
		int val;
		cout << "\nThe list is empty yet. Enter the first element\n";
		input(&val);
		arr[arr[0].next].next = 0;
		arr[arr[0].next].value = val;
		++count;
	}

	int get_free_ind() {
		int cur = 1;
		while (arr[cur].next != -1) {
			++cur;
		}
		return cur;
	}

	void push_after() {
		if (count == len) {
			cout << "\nThe list is full\n";
			return;
		}
		else if (count == 0) {
			push_first();
			return;
		}
		int after_this;
		cout << "\nEnter the element after which there will be an addition\n";
		after_this = search_ind();
		if (after_this == 0) {
			cout << "\nThere is no such element\n";
			return;
		}
		int val;
		cout << "\nEnter new element\n";
		input(&val);
		int cur = get_free_ind();
		arr[cur].value = val;
		arr[cur].next = arr[after_this].next;
		arr[after_this].next = cur;
		++count;
	}

	void push_before() {
		if (count == len) {
			cout << "\nThe list is full\n";
			return;
		}
		else if (count == 0) {
			push_first();
			return;
		}
		int before_this;
		cout << "\nEnter the element before which there will be an addition\n";
		before_this = search_ind();
		if (before_this == 0) {
			cout << "\nThere is no such element\n";
			return;
		}
		int val;
		cout << "\nEnter new element\n";
		input(&val);
		int cur = get_free_ind();
		for (int after_this = 0; after_this <= len; after_this++)
			if (arr[after_this].next == before_this) {
				arr[cur].value = val;
				arr[cur].next = arr[after_this].next;
				arr[after_this].next = cur;
				++count;
				return;
			}
	}

	void pop() {
		cout << "\nEnter the element to delete\n";
		int del = search_ind();
		if (del == -1) {
			return;
		}
		if (del == 0) {
			cout << "\nThere is no such element\n";
			return;
		}
		for(int prev = 0; prev <= len; prev++)
			if (arr[prev].next == del) {
				arr[prev].next = arr[del].next;
				arr[del].next = -1;
				--count;
				return;
			}
	}

	void show() {
		if (count == 0) {
			cout << "\nThe list is empty!\n";
			return;
		}
		int cur = arr[0].next;
		cout << "\nList :\n";
		while (cur) {
			cout << arr[cur].value << endl;
			cur = arr[cur].next;
		}
	}

	void search() {
		if (count == 0) {
			cout << "\nThe list is empty!\n";
			return;
		}
		int val;
		cout << "\nEnter the element to search\n";
		input(&val);
		int cur = arr[0].next;
		int i = 1;
		while (cur != 0 && i <= count) {
			if (arr[cur].value == val) {
				cout << "\nThe number in list of element " << val << " is " << i << endl;
				return;
			}
			cur = arr[cur].next;
			++i;
		}
		cout << "\nThere is no such element\n";
	}
};

int main() {
	int flag;
	int n;
	cout << "Enter the length of list" << endl;
	input(&n);
	List list = List(n);
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show the list" << endl;
			cout << "2 - Add new element after some" << endl;
			cout << "3 - Add new element before some" << endl;
			cout << "4 - Delete element" << endl;
			cout << "5 - Search element" << endl;
			cout << "6 - Terminate the program" << endl;
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
			list.pop();
			break;
		case 5:
			list.search();
			break;
		case 6:
			return 0;
			break;
		}
	}
}