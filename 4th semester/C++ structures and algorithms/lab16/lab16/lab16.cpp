#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>
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
		sum += word[i];
	return sum % 10;
}

void Add(string arr[], string word) {
	int hash;
	hash = Hash(word);
	if (arr[hash] == "empty") {
		arr[hash] = word;
	}
	else {
		cout << "Ошибка со словом " << word << endl;
	}
}

void Show(string mass[]) {
	for (int i = 0; i < 10; i++) {
		cout << "[" << i << "]" << mass[i] << " ";
	}
}

void Search(string arr[]) {
	int hash;
	string str;
	cout << "Введите ключевое слово для поиска\n";
	cin >> str;
	hash = Hash(str);
	if (arr[hash] == str) {
		cout << "Элемент " << str << " найден, его индекс - [" << hash << "]" << endl;
	}
	else {
		cout << "Элемент " << str << " не найден" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	string words[] = { "var", "with", "until", "Char", "program", "Begin", "end", "if", "false", "true" };
	string table[10];
	for (int i = 0; i < 10; i++)
	{
		table[i] = "empty";
	}
	for (int i = 0; i < 10; i++)
	{
		Add(table, words[i]);
	}
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nВыберите действие и введите номер" << endl;
			cout << "1 - Показать таблицу" << endl;
			cout << "2 - Поиск" << endl;
			cout << "3 - Выход" << endl;
			int_input(&n);
			if (n >= 1 && n <= 3) {
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
			Search(table);
			cout << "\n";
			break;
		case 3:
			return 0;
			break;
		}
	}
}