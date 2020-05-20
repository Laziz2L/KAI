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

void bubble(int a[], int length, bool show) {
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

	cout << "\nBubble sort:\n";
	if (show) {
		for (int i = 0; i <= length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << compares << endl;
	cout << "Swaps - " << swaps << endl;
}

void insertion(int a[], int length, bool show) {
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

	cout << "\nInsertion sort:\n";
	if (show) {
		for (int i = 0; i <= length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << compares << endl;
	cout << "Swaps - " << swaps << endl;
}

void selection(int a[], int length, bool show) {
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

	cout << "\nSelection sort:\n";
	if (show) {
		for (int i = 0; i <= length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << compares << endl;
	cout << "Swaps - " << swaps << endl;
}

void shell(int a[], int length, bool show) {
	int steps = round(log2f(length + 1)) - 1;

	int compares = 0;
	int swaps = 0;

	int *arr = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		arr[i] = a[i];
	}

	int temp;
	int j;
	int k;
	for (int m = 1; m <= steps; m++) {
		k = pow(2, m) - 1;
		for (int i = k; i <= length; i++) {
			temp = arr[i];
			j = i - k;
			while (j >= 0 && temp < arr[j]) {
				++compares;
				++swaps;
				arr[j + k] = arr[j];
				j = j - k;
			}
			++compares;
			arr[j + k] = temp;
		}

	}

	cout << "\nShell sort:\n";
	if (show) {
		for (int i = 0; i <= length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << compares << endl;
	cout << "Swaps - " << swaps << endl;
}


int quick_compares = 0;
int quick_swaps = 0;

void quicksort(int arr[], int left, int right) {
	int i, j, sred, temp;
	i = left;
	j = right;
	sred = arr[(left + right) / 2];
	do {
		while (arr[i] < sred) {
			++quick_compares;
			++i;
		}
		while (arr[j] > sred) {
			++quick_compares;
			--j;
		}
		if (i <= j) {
			++quick_swaps;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}
	} while (i <= j);
	if (left < j) {
		quicksort(arr, left, j);
	}
	if (i < right) {
		quicksort(arr, i, right);
	}
}

void quick(int a[], int length, bool show) {
	quick_compares = 0;
	quick_swaps = 0;

	int *arr = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		arr[i] = a[i];
	}

	quicksort(arr, 0, length);

	cout << "\nQuick sort:\n";
	if (show) {
		for (int i = 0; i <= length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << quick_compares << endl;
	cout << "Swaps - " << quick_swaps << endl;
}

int pyr_compares = 0;
int pyr_swaps = 0;
void sito(int arr[], int al, int ar) {
	int i, j, x;
	i = al;
	j = 2 * al;
	x = arr[al];
	++pyr_compares;
	if (j < ar && arr[j + 1] > arr[j]) {
		++j;
	}
	++pyr_compares;
	while (j <= ar && arr[j] > x) {
		++pyr_swaps;
		arr[i] = arr[j];
		i = j;
		j = 2 * j;
		++pyr_compares;
		if (j < ar && arr[j + 1] > arr[j]) {
			++pyr_compares;
			++j;
		}
	}
	arr[i] = x;
}

void pyramid(int a[], int length, bool show) {
	pyr_compares = 0;
	pyr_swaps = 0;

	int *arr = new int[length + 2];
	arr[0] = NULL;
	for (int i = 0; i <= length; i++) {
		arr[i+1] = a[i];
	}

	int left = length / 2 + 1;
	int right = length + 1;
	while (left > 1) {
		--left;
		sito(arr, left, right);
	}
	int temp;
	while (right > 1) {
		++pyr_swaps;
		temp = arr[1];
		arr[1] = arr[right];
		arr[right] = temp;
		--right;
		sito(arr, left, right);
	}

	cout << "\nPyramidal(heap) sort:\n";
	if (show) {
		for (int i = 1; i <= length + 1; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "Compares - " << pyr_compares << endl;
	cout << "Swaps - " << pyr_swaps << endl;
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
	const int len4 = 10000;
	int arr1[len1];
	int arr2[len2];
	int arr3[len3];
	int arr4[len4];
	fill(arr1, len1);
	fill(arr2, len2);
	fill(arr3, len3);
	fill(arr4, len4);

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
			cout << "5 - Shell sort" << endl;
			cout << "6 - Quick sort" << endl;
			cout << "7 - Pyramidal(heap) sort" << endl;
			cout << "8 - Analysis" << endl;
			cout << "9 - Terminate the programm" << endl;
			int_input(&n);
			if (n >= 1 && n <= 9) {
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
				cout << "4 - Choose array with 10000 elements" << endl;
				int_input(&n);
				if (n >= 1 && n <= 4) {
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
			else if (n == 3) {
				arr = arr3;
				len = len3 - 1;
			}
			else {
				arr = arr4;
				len = len4 - 1;
			}
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			bubble(arr, len, true);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			insertion(arr, len, true);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			selection(arr, len, true);
			cout << "\n";
			break;
		case 5:
			cout << "\n";
			shell(arr, len, true);
			cout << "\n";
			break;
		case 6:
			cout << "\n";
			quick(arr, len, true);
			cout << "\n";
			break;
		case 7:
			cout << "\n";
			pyramid(arr, len, true);
			cout << "\n";
			break;
		case 8:
			cout << "\n";
			bubble(arr, len, false);
			insertion(arr, len, false);
			selection(arr, len, false);
			shell(arr, len, false);
			quick(arr, len, false);
			pyramid(arr, len, false);
			cout << "\n";
			break;
		case 9:
			return 0;
			break;
		}
	}
}