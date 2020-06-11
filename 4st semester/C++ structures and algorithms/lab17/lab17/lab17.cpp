#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <clocale>
#include <Windows.h>
using namespace std;

const int N = 10;
const int M = N * 1.2;
int t_count = 0;

void int_input(int *in) {
	int flag;
	if (cin >> *in)
		flag = 0;
	else
		flag = 1;
	cin.clear();
	cin.ignore(32767, '\n');
	while (flag) {
		cout << "Введите числовое значение\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

int Hash(string word) {
	int sum = 0;
	for (unsigned int i = 0; i < word.size(); i++)
		sum += static_cast<unsigned>(static_cast<unsigned char>(word[i]));
	return sum % M;
}

void Add(string arr[]) {
	if (t_count == M) {
		cout << "\nТаблица заполнена!\n";
		return;
	}
	string word;
	cout << "\nВведите ключевое слово, которое хотите добавить\n";
	cin >> word;
	int hash;
	hash = Hash(word);
	int compares = 1;
	if (arr[hash] == "empty") {
		arr[hash] = word;
		cout << "\nДобавлено, количество сравнений - " << compares << endl;
		t_count++;
	}
	else if (arr[hash] == word) {
		cout << "\nНе добавлено, т.к. уже имеется в таблице, количество сравнений - " << compares << endl;
	}
	else {
		for (int i = 1; i < M; i++) {
			hash = (hash + 1) % M;
			compares++;
			if (arr[hash] == "empty") {
				arr[hash] = word;
				cout << "\nДобавлено, количество сравнений - " << compares << endl;
				t_count++;
				break;
			}
			else if (arr[hash] == word) {
				cout << "\nНе добавлено, т.к. уже имеется в таблице, количество сравнений - " << compares << endl;
				break;
			}
		}
	}
}

void Show(string arr[]) {
	if (t_count == 0) {
		cout << "\nТаблица пустая!\n";
		return;
	}
	cout << "\nТаблица:\n";
	for (int i = 0; i < M; i++) {
		cout << "[" << i << "]" << arr[i] << " ";
	}
	cout << endl;
}

void Search(string arr[]) {
	if (t_count == 0) {
		cout << "\nТаблица пустая!\n";
		return;
	}
	int hash;
	string word;
	cout << "\nВведите ключевое слово для поиска\n";
	cin >> word;
	hash = Hash(word);
	int compares = 1;
	if (arr[hash] == "empty") {
		cout << "\nНе найдено, количество сравнений - " << compares << endl;
	}
	else if (arr[hash] == word) {
		cout << "\nНайдено с индексом " << hash << ", количество сравнений - " << compares << endl;
	}
	else {
		for (int i = 1; i < M; i++) {
			hash = (hash + 1) % M;
			compares++;
			if (arr[hash] == "empty" || i == M - 1 && arr[hash] != word ) {
				cout << "\nНе найдено, количество сравнений - " << compares << endl;
				break;
			}
			else if (arr[hash] == word) {
				cout << "\nНайдено с индексом " << hash << ", количество сравнений - " << compares << endl;
				break;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string table[M];
	for (int i = 0; i < M; i++)
	{
		table[i] = "empty";
	}
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nВыберите действие и введите номер" << endl;
			cout << "1 - Показать таблицу" << endl;
			cout << "2 - Добавление" << endl;
			cout << "3 - Поиск" << endl;
			cout << "4 - Выход" << endl;
			int_input(&n);
			if (n >= 1 && n <= 4) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			Show(table);
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			Add(table);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			Search(table);
			cout << "\n";
			break;
		case 4:
			return 0;
			break;
		}
	}
}