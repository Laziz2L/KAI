#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <clocale>
#include <Windows.h>
using namespace std;

const int M = 10;

struct El {
	string val;
	El *next;
};
El *table;

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

int Push(El* el, string val)
{
	int compares = 1;
	while (el->next != NULL) {
		if (el->next->val == val) {
			return compares * (-1);
		}
		compares++;
		el = el->next;
	}
	el->next = new El();
	el->next->val = val;
	el->next->next = NULL;
	return compares;
}

void Add() {
	string word;
	cout << "\nВведите ключевое слово, которое хотите добавить\n";
	cin >> word;
	int hash;
	hash = Hash(word);
	int compares = Push(&table[hash], word);
	if (compares < 0) {
		cout << "\nНе добавлено, т.к. такое слово уже есть в таблице! Количество сравнений - " << compares * (-1) << endl;
	}
	else {
		cout << "\nДобавлено! Количество сравнений - " << compares << endl;
	}
}

void Show_list(El *el) {
	while (el->next != NULL) {
		cout << el->next->val << " ";
		el = el->next;
	}
}

void Show() {
	cout << "\nТаблица:\n";
	for (int i = 0; i < M; i++) {
		cout << "[" << i << "] ";
		if (table[i].next == NULL) {
			cout << "пусто\n";
		}
		else {
			Show_list(&table[i]);
			cout << endl;
		}
	}
}

int Search_list(El *el, string val) {
	int compares = 1;
	while (el->next != NULL) {
		if (el->next->val == val) {
			return compares * (-1);
		}
		compares++;
		el = el->next;
	}
	return compares;
}

void Search() {
	int hash;
	string word;
	cout << "\nВведите ключевое слово для поиска\n";
	cin >> word;
	hash = Hash(word);
	int compares = Search_list(&table[hash], word);
	if (compares < 0) {
		cout << "\nНайдено! Количество сравнений - " << compares*(-1) << endl;
	}
	else {
		cout << "\nНе найдено! Количество сравнений - " << compares << endl;
	}
}

int Pop_list(El *el, string val) {
	int compares = 1;
	while (el->next != NULL) {
		if (el->next->val == val) {
			break;
		}
		compares++;
		el = el->next;
	}
	if (el->next == NULL) {
		return compares * (-1);
	}
	El *tmp = el->next;
	el->next = el->next->next;
	delete tmp;
	return compares;
}

void Pop() {
	int hash;
	string word;
	cout << "\nВведите ключевое слово, которое хотите удалить\n";
	cin >> word;
	hash = Hash(word);
	int compares = Pop_list(&table[hash], word);
	if (compares < 0) {
		cout << "\nНе найдено! Количество сравнений - " << compares*(-1) << endl;
	}
	else {
		cout << "\nУдалено! Количество сравнений - " << compares << endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	table = new El[M];
	for (int i = 0; i < M; i++)
	{
		table[i].next = NULL;
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
			cout << "4 - Удаление" << endl;
			cout << "5 - Выход" << endl;
			int_input(&n);
			if (n >= 1 && n <= 5) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			cout << "\n";
			Show();
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			Add();
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			Search();
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			Pop();
			cout << "\n";
			break;
		case 5:
			return 0;
			break;
		}
	}
}