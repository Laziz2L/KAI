#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct List {
	string *arr;
	string len;

	List(int length) {
		len = to_string(length);
		arr = new string[length + 1];
		arr[0] = '0';
	}

	void push() {
		if (arr[0] == len) {
			cout << "\nThe list is full!" << endl;
			return;
		}
		string input;
		cout << "\nEnter the element :" << endl;
		cin >> input;
		if (arr[0] == "0") {
			arr[1] = input;
			arr[0] = to_string(stoi(arr[0]) + 1);
			return;
		}
		for (int i = 1; i <= stoi(arr[0]); i++) {
			while (input.length() > arr[i].length()) {
				++i;
			}
			if ((arr[i].length() == input.length() && arr[i] > input) ||
				(arr[i].length() > input.length())) {
				for (int j = stoi(arr[0]); j >= i; j--){
					arr[j + 1] = arr[j];
				}
				arr[i] = input;
				arr[0] = to_string(stoi(arr[0]) + 1);
				return;
			}
		}
		arr[stoi(arr[0]) + 1] = input;
		arr[0] = to_string(stoi(arr[0]) + 1);
	}

	void show() {
		if (arr[0] == "0") {
			cout << "\nThe list is empty!" << endl;
			return;
		}
		cout << "\nList :" << endl;
		for (int i = 1; i <= stoi(arr[0]); i++)
			cout << arr[i] << endl;
	}

	int search(string el) {
		if (arr[0] == "0") {
			cout << "\nThe list is empty!" << endl;
			return -1;
		}
		for (int i = 1; i <= stoi(arr[0]); i++) {
			if (arr[i] == el) {
				return (i);
			}
		}
		cout << "\nThere is no such element in the list" << endl;
		return 0;
	}

	void pop() {
		int ind;
		string el;
		cout << "\nEnter the element to delete :" << endl;
		cin >> el;
		ind = search(el);
		if (ind <= 0)
			return;
		for (int i = ind; i < stoi(arr[0]); i++) {
			arr[i] = arr[i + 1];
		}
		arr[0] = to_string(stoi(arr[0]) - 1);
	}
};

int main() {
	int flag = 1;
	int n;
	string el;
	while (flag) {
		cout << "Enter the length of list" << endl;
		if (cin >> n)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	List list = List(n);
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show the list" << endl;
			cout << "2 - Add new element" << endl;
			cout << "3 - Delete element" << endl;
			cout << "4 - Search element" << endl;
			cout << "5 - Terminate the program" << endl;
			if (cin >> n && n >= 1 && n <= 5)
				flag = 0;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		switch (n) {
		case 1:
			list.show();
			break;
		case 2:
			list.push();
			break;
		case 3:
			list.pop();
			break;
		case 4:
			cout << "\nEnter the element to search :" << endl;
			cin >> el;
			n = list.search(el);
			if (n > 0)
				cout << "\nThe element " << el << " is located at number " << n << endl;
			break;
		case 5:
			return 0;
			break;
		}
	}
}