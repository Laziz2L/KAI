#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <list>
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

void pocket_mas(int len) {
	cout << "\nSimple pocket (bucket) sort with using second array.\n";
	int *arr = (int*)malloc(sizeof(int)*len);
	int r;
	bool was;
	cout << "Array before sorting:\n";
	for (int i = 0; i < len; i++) {
		r = rand() % len;
		was = false;
		for (int j = 0; j < i; j++) {
			if (arr[j] == r) {
				was = true;
			}
		}
		if (!was) {
			arr[i] = r;
			cout << arr[i] << " ";
		}
		else {
			--i;
		}
	}
	int *res = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++) {
		res[arr[i]] = arr[i];
	}
	cout << "\nArray after sorting:\n";
	for (int i = 0; i < len; i++) {
		cout << res[i] << " ";
	}
	cout << "\nCompares - 0";
	cout << "\nSwaps - " << len << endl;
}

void pocket_wo_mas(int len) {
	cout << "\nSimple pocket (bucket) sort without using second array.\n";
	int *arr = (int*)malloc(sizeof(int)*len);
	int r;
	bool was;
	cout << "Array before sorting:\n";
	for (int i = 0; i < len; i++) {
		r = rand() % len;
		was = false;
		for (int j = 0; j < i; j++) {
			if (arr[j] == r) {
				was = true;
			}
		}
		if (!was) {
			arr[i] = r;
			cout << arr[i] << " ";
		}
		else {
			--i;
		}
	}
	int compares = 0;
	int swaps = 0;
	int temp;
	for (int i = 0; i < len; i++) {
		++compares;
		while (arr[i] != i) {
			++compares;
			++swaps;
			temp = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp;
		}
	}
	cout << "\nArray after sorting:\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - " << compares;
	cout << "\nSwaps - " << swaps << endl;
}

struct El {
	int val;
	El *next;
};

struct List {
	El *el;
};

void Add(El* el, int val)
{
	while (el->next != NULL)
		el = el->next;
	el->next = new El();
	el->next->val = val;
	el->next->next = NULL;
}

void ClearList(El* head)
{
	while (head != NULL)
	{
		El* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void pocket(int len) {
	cout << "\nExtended pocket (bucket) sort.\n";
	int *arr = (int*)malloc(sizeof(int)*len);
	cout << "Array before sorting:\n";
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % len;
		cout << arr[i] << " ";
	}

	int compares = 0;
	int swaps = 0;

	List *res = (List*)malloc(sizeof(List)*len);
	for (int i = 0; i < len; i++) {
		res[i].el = NULL;
	}
	for (int i = 0; i < len; i++)
	{
		El *next = res[arr[i]].el;
		res[arr[i]].el = (El*)malloc(sizeof(El));
		res[arr[i]].el->next = next;
		res[arr[i]].el->val = arr[i];
	}
	int i = 0;
	for (int j = 0; j < len; j++)
	{
		compares++;
		while (res[j].el != NULL)
		{
			compares++;
			swaps++;
			arr[i] = res[j].el->val;
			i++;
			res[j].el = res[j].el->next;
		}
	}
	cout << "\nArray after sorting:\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - " << compares;
	cout << "\nSwaps - " << swaps << endl;
}

void radix(int len, int k) {
	int max = (int)pow(10, k);
	cout << "\nRadix sort.\n";
	int *arr = (int*)malloc(sizeof(int)*len);
	cout << "Array before sorting:\n";
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % max;
		cout << arr[i] << " ";
	}

	int swaps = 0;

	El *res = new El[10];
	int temp;
	for (int digit = 1; digit < max; digit = digit * 10) {
		for (int j = 0; j < 10; j++) {
			res[j].next = NULL;
		}
		for (int i = 0; i < len; i++)
		{
			temp = arr[i] % (digit*10) / digit;
			Add(&res[temp], arr[i]);
		}
		for (int j = 0, l = 0; l < len; j++)
		{
			El* tmp = res[j].next;
			while (tmp != NULL)
			{
				arr[l] = tmp->val;
				tmp = tmp->next;
				l++;
				swaps++;
			}
		}
		for (int j = 0; j < 10; j++)
			ClearList(res[j].next);
	}

	cout << "\nArray after sorting:\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - 0";
	cout << "\nSwaps - " << swaps << endl;
}

int main() {
	int len = 10;

	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Set the number of elements" << endl;
			cout << "2 - Simple pocket (bucket) sort with using second array" << endl;
			cout << "3 - Simple pocket (bucket) sort without using second array" << endl;
			cout << "4 - Extended pocket (bucket) sort" << endl;
			cout << "5 - Radix sort" << endl;
			cout << "6 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 6) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			cout << "Enter the number of elements\n";
			int_input(&len);
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			pocket_mas(len);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			pocket_wo_mas(len);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			pocket(len);
			cout << "\n";
			break;
		case 5:
			cout << "\n";
			cout << "K:\n";
			flag = 1;
			while (flag) {
				cout << "Maximum - 6" << endl;
				int_input(&n);
				if (n >= 1 && n <= 6) {
					flag = 0;
				}
			}
			radix(len, n);
			cout << "\n";
			break;
		case 6:
			return 0;
			break;
		}
	}
}