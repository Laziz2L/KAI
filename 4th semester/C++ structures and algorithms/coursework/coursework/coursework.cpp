#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Railway.cpp"
using namespace std;

bool Read(Railway*& rway) {

	/*if (rway != nullptr) {
		cout << "База данных будет очищена.\n1 - Продолжить\n2 - Отменить\n";
		int action;
		int_input(&action);
		if (action == 1) {
			delete rway;
			rway = nullptr;
		}
		else {
			return false;
		}
	}*/

	string path = "file.txt";
	ifstream fin;

	try { fin.open(path, ios::in); }
	catch (const ofstream::failure) {
		cerr << "Не удалось открыть файл." << endl;
		return false;
	}
	if (!fin) {
		cout << "Файл не найден." << endl;
		return false;
	}

	string InStr;
	string SDNum;
	string Name;
	string Line;
	string Mark;
	int DNum;
	int RegNum;
	int d_count = 0;
	int t_count = 0;

	getline(fin, InStr);
	while (fin && InStr != "/Железная дорога") {
		if (InStr == "Железная дорога") {
			getline(fin, Name);
			if (!issp(Name[0])) {
				rway = new Railway(Name);
			}
			else {
				cout << "Ошибка при чтении файла. Неверно задано название железной дороги (первый символ пробельный).";
				delete rway;
				rway = nullptr;
				return false;
			}
		}
		else if (InStr == "Депо") {
			if (rway == nullptr) {
				cout << "Ошибка при чтении файла. Не задано название железной дороги" << endl;
				return false;
			}
			getline(fin, SDNum);
			if (SDNum == "") {
				cout << "Ошибка при чтении файла. Не задан номер депо.";
					delete rway;
					rway = nullptr;
					return false;
			}
			for (int i = 0; i < SDNum.length(); i++) {
				if (!isdigit(SDNum[i])) {
					cout << "Ошибка при чтении файла. Неверно задан номер депо.";
					delete rway;
					rway = nullptr;
					return false;
				}
			}
			DNum = stoi(SDNum);
			d_count++;
			if (d_count > railway_len) {
				cout << "Ошибка при чтении файла. Неверное количество депо." << endl;
				delete rway;
				rway = nullptr;
				return false;
			}
			t_count = 0;
			rway->push_depot(DNum);
			getline(fin, Line);
			while (Line == "") getline(fin, Line);
			while (Line != "/Депо" && fin)
			{
				if (Line == "Депо") {
					cout << "Ошибка при чтении файла. Неверно заданы теги." << endl;
					delete rway;
					rway = nullptr;
					return false;
				}
				string buffer;
				for (unsigned int i = 0; i < Line.length(); i++) {
					if (Line[i] != '-') {
						buffer += Line[i];
					}
					else {
						Mark = buffer;
						buffer = "";
						for (unsigned int j = i + 1; j < Line.length(); j++) {
							buffer += Line[j];
						}
						SDNum = buffer;
					}
				}
				/*for (unsigned int i = 0; i < Mark.length(); i++) {
					if (Mark[i] == ' ') {
						Mark.erase(i, 1);
						i--;
					}
				}*/
				while (Mark[0] == ' ') {
					Mark.erase(0, 1);
				}
				/*while (Mark[Mark.length() - 1] == ' ') {
					Mark.erase(Mark.length() - 1, 1);
				}*/
				while (SDNum[0] == ' ')
				{
					SDNum.erase(0, 1);
				}
				if (Mark == "") {
					cout << "Ошибка при чтении марки электровоза." << endl;
					delete rway;
					rway = nullptr;
					return false;
				}
				if (SDNum == "") {
					cout << "Ошибка при чтении регистрационного номера электровоза." << endl;
					delete rway;
					rway = nullptr;
					return false;
				}
				try {
					RegNum = stoi(SDNum);
				}
				catch (...) {
					cout << "Ошибка при чтении файла. Неверно задан регистрационный номер электровоза." << endl;
					delete rway;
					rway = nullptr;
					return false;
				}
				t_count++;
				if (t_count > depot_len) {
					cout << "Ошибка при чтении файла. Неверное количество электровозов в депо с номером " << DNum << endl;
					delete rway;
					rway = nullptr;
					return false;
				}
				if (RegNum == NULL || Mark == "") {
					cout << "Ошибка при чтении файла. Неправильно объявлены теги." << endl;
					if (rway != nullptr) {
						delete rway;
						rway = nullptr;
					}
					return false;
				}
				rway->push_train(DNum, RegNum, Mark);
				RegNum = NULL;
				Mark = "";
				getline(fin, Line);
			}
		}
		else {
			cout << "Ошибка при чтении файла. Неправильно объявлены теги." << endl;
			if (rway != nullptr) {
				delete rway;
				rway = nullptr;
			}
			return false;
		}
		getline(fin, InStr);
	}
	fin.close();
	cout << "Структура успешно загружена." << endl;
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");

	Railway *rway = nullptr;
	bool flag = true;
	int n;	
	
	while (true) {
		flag = 1;
		while (flag) { 
			cout << "\nВыберите действие и введите номер" << endl;
			cout << "1 - Показать структуру" << endl;
			cout << "2 - Поиск электровоза" << endl;
			cout << "3 - Добавить депо" << endl;
			cout << "4 - Удалить депо" << endl;
			cout << "5 - Добавить электровоз" << endl;
			cout << "6 - Удалить электровоз" << endl;
			cout << "7 - Записать структуру в файл" << endl;
			cout << "8 - Новая структура" << endl;
			cout << "9 - Завершение работы" << endl;
			int_input(&n);
			if (n >= 1 && n <= 9) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->show();
			break;
		case 2:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->search_train();
			break;
		case 3:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->push_depot();
			break;
		case 4:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->pop_depot();
			break;
		case 5:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->push_train();
			break;
		case 6:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->pop_train();
			break;
		case 7:
			if (rway == nullptr) {
				cout << "Структура не создана!" << endl;
			}
			else rway->Write();
			break;
		case 8:
			if (rway != nullptr) {
				int action = 0;
				while (action != 1 && action != 2) {
					cout << "\nБаза данных будет очищена.\n1 - Продолжить\n2 - Отменить\n";
					int_input(&action);
				}
				if (action == 1) {
					delete rway;
					rway = nullptr;
				}
				else {
					break;
				}
			}
			while (1) { //просим выбрать метод ввода структуры, пока не введет 1 или 2
				flag = true;
				while (flag) {
					cout << "\nВыберите действие и введите номер" << endl;
					cout << "1 - Загрузить структуру из файла" << endl;
					cout << "2 - Создать новую" << endl;
					int_input(&n); //описание этой функции есть в Railway.cpp
					if (n >= 1 && n <= 2) {
						flag = 0;
					}
				}
				if (n == 1) {
					if (Read(rway)) break;
					else {
						cout << endl;
						break;
					}
				}
				else if (n == 2) { //ввод из консоли
					string name;
					cout << "\nВведите название железной дороги\n";
					//getline(cin, name);
					string_input(&name);
					rway = new Railway(name);
					break;
				}
			}
			break;
		case 9:
			delete rway;
			rway = nullptr;
			exit(1);
			break;
		}
	}
}