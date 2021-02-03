#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
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

void bubble(int a[], int length) {
	int compares = 0;
	int swaps = 0;

	int *arr = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		arr[i] = a[i];
	}

	int temp;
	for (int i = 1; i <= length; i++) {
		for (int j = length; j >= i; j--) {
			++compares;
			if (arr[j - 1] > arr[j]) {
				++swaps;
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "\nSorted array:\n";
	for (int i = 0; i <= length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - " << compares;
	cout << "\nSwaps - " << swaps << endl;
}

void insertion(int a[], int length) {
	int compares = 0;
	int swaps = 0;

	int *arr = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		arr[i] = a[i];
	}

	int temp;
	int j;
	for (int i = 1; i <= length; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && temp < arr[j]) {
			++compares;
			++swaps;
			arr[j + 1] = arr[j];
			--j;
		}
		++compares;
		arr[j + 1] = temp;
	}

	cout << "\nSorted array:\n";
	for (int i = 0; i <= length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - " << compares;
	cout << "\nSwaps - " << swaps << endl;
}

void selection(int a[], int length) {
	int compares = 0;
	int swaps = 0;

	int *arr = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		arr[i] = a[i];
	}

	int k;
	int temp;
	for (int i = 0; i <= length - 1; i++) {
		k = i;
		temp = arr[i];
		for (int j = i + 1; j <= length; j++) {
			++compares;
			if (arr[j] < temp) {
				k = j;
				temp = arr[j];
			}
		}
		if (arr[i] != temp) {
			++swaps;
		}
		arr[k] = arr[i];
		arr[i] = temp;
	}

	cout << "\nSorted array:\n";
	for (int i = 0; i <= length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nCompares - " << compares;
	cout << "\nSwaps - " << swaps << endl;
}

void fill(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 10000;
	}
}

int main() {

	const int len1 = 10;
	const int len2 = 100;
	const int len3 = 1000;
	int arr1[len1];
	int arr2[len2];
	int arr3[len3];
	fill(arr1, len1);
	fill(arr2, len2);
	fill(arr3, len3);

	int *arr = arr1;
	int len = len1 - 1;
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Choose array" << endl;
			cout << "2 - Bubble sort" << endl;
			cout << "3 - Insertion sort" << endl;
			cout << "4 - Selection sort" << endl;
			cout << "5 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 5) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			flag = 1;
			while (flag) {
				cout << "\nChoose the action and enter its number" << endl;
				cout << "1 - Choose array with 10 elements" << endl;
				cout << "2 - Choose array with 100 elements" << endl;
				cout << "3 - Choose array with 1000 elements" << endl;
				int_input(&n);
				if (n >= 1 && n <= 3) {
					flag = 0;
				}
			}
			if (n == 1) {
				arr = arr1;
				len = len1 - 1;
			}
			else if (n == 2) {
				arr = arr2;
				len = len2 - 1;
			}
			else {
				arr = arr3;
				len = len3 - 1;
			}
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			bubble(arr, len);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			insertion(arr, len);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			selection(arr, len);
			cout << "\n";
			break;
		case 5:
			return 0;
			break;
		}
	}
}