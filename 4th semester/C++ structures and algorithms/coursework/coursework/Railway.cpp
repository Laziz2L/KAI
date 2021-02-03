#include <string>
#include <iostream>
#include "Depot.cpp"
#include <fstream>
using namespace std;

const int railway_len = 10; //длина ЖД (массива депо)

inline bool issp(char sym) {
	if (sym == ' ' || sym == '\t' || sym == '\n' || sym == '\v' || sym == '\f' || sym == '\r') {
		return true;
	}
	else return false;
}

inline void string_input(string *in) {
	getline(cin, *in);
	if (*in == "") {
		cout << "Ошибка! Введена пустая строка, попробуйте еще раз.\n";
		string_input(in);
	}
	else if (issp((*in)[0])) {
		cout << "Ошибка! Строка начинается с пробельного символа, попробуйте еще раз.";
		cout << endl;
		string_input(in);
	}
}

//статический стек - железная дорога
class Railway {
private:
	Depot *d_arr; //массив депо
	int count;	//текущее количество депо 
	int len;	//длина массива депо
	string name;//название депо
public:

	string GetName() {
		return name;
	}

	int GetCount() {
		return count;
	}

	Depot* GetDarr() {
		return d_arr;
	}
	Depot* GetDarr(int i) {
		return &d_arr[i];
	}
	Railway() {
		len = railway_len;
		d_arr = new Depot[railway_len];
		count = 0;
		name = "";
	}

	Railway(string name) {
		len = railway_len;
		d_arr = new Depot[railway_len];
		count = 0;
		this->name = name;
	}

	~Railway() {
		delete[] d_arr;
		d_arr = nullptr;
	}

	//добавление депо
	void push_depot() { 
		if (count == len) { //проверка заполненности массива
			cout << "\nЖелезная дорога заполнена!\n";
			return;
		}
		int d_num;
		cout << "\nВведите номер депо\n"; 
		int_input(&d_num); //принимаем от пользователя номер нового депо		
		d_arr[count].SetNum(d_num); //вводим новое депо в первую свободную ячейку
		++count;
	}

	//добавление депо с уже данным аргументом - номером депо, планировал использовать при вводе с файла
	void push_depot(int num) {
		d_arr[count].SetNum(num);
		++count;
	}

	//удаление депо 
	void pop_depot() {
		if (count == 0) { //проверка на пустоту
			cout << "\nЖелезная дорога пустая!\n";
			return;
		}
		--count; //просто уменьшаем количество депо, так у нас не будет обрабатываться в других функциях последняя ячейка
	}

	//добавление электровоза
	void push_train() {
		if (count == 0) { //проверка на пустоту (есть ли хоть одно депо, куда можно засунуть электровоз)
			cout << "\nЖелезная дорога пустая!\n";
			return;
		}
		int d_num;
		cout << "\nВведите номер депо, в который хотите добавить электровоз\n";
		int_input(&d_num); //принимаем номер депо, в который нужно засунуть электровоз
		for (int i = 0; i < count; i++) { //проходим по массиву депо
			if (d_arr[i].GetDnum() == d_num) { //если нашли нужное депо по номеру
				int reg_num;
				string mark;
				cout << "Введите регистрационный номер электровоза\n";
				int_input(&reg_num); //принимаем регистрационный номер электровоза
				cout << "Введите марку электровоза\n";
				//cin >> mark;		//принимаем марку электровоза
				//getline(cin, mark);
				string_input(&mark);
				d_arr[i].push(reg_num, mark); //добавляем электровоз в нужную ячейку массива депо
				return; //выходим из функции
			}
		}
		cout << "Такого депо нет!\n"; //если дошли сюда, то запрошенное депо не было найдено, пишем об этом
	}

	//добавление электровоза с уже данными аргументами - номером депо, рег номером и маркой, планировал использовать при вводе с файла
	void push_train(int depot, int num, string mark) {
		for (int i = 0; i < count; i++) {
			if (d_arr[i].GetDnum() == depot) {
				d_arr[i].push(num, mark);
				return;
			}
		}
	}

	//удаление электровоза; проверка на пустоту и поиск депо такие же как в добавлении
	void pop_train() {
		if (count == 0) {
			cout << "\nЖелезная дорога пустая!\n";
			return;
		}
		int d_num;
		cout << "\nВведите номер депо, в котором хотите удалить электровоз\n";
		int_input(&d_num);
		for (int i = 0; i < count; i++) {
			if (d_arr[i].GetDnum() == d_num) {
				/*int reg_num;*/
				d_arr[i].pop();
				return;
			}
		}
		cout << "Такого депо нет!\n";
	}

	//поиск электровоза, идет по всей структуре, не спрашивая про депо
	void search_train() {
		if (count == 0) { //проверка на пустоту
			cout << "\nЖелезная дорога пустая!\n";
			return;
		}
		int reg_num;
		cout << "\nВведите регистрационный номер электровоза, который нужно найти\n";
		int_input(&reg_num); //принимаем рег номер электровоза, который нужно найти
		int cur = 0;
		for (int i = 0;i < count; i++) { //идем по всем депо
			cur = d_arr[i].search(reg_num); //записываем в cur результат поиска (индекс в массиве электровозов, либо 0 если не найден)
			if (cur != 0) { //если нашелся в текущем (i-ом) депо, пишем информацию
				cout << "электровоз с регистрационным номером " << reg_num;
				cout << " расположен в депо под номером " << d_arr[i].GetDnum();
				cout << " на позиции " << cur;
				cout << ", его марка - " << d_arr[i].GetTarr()[cur - 1].GetMark() << endl;
				return;		//и выходим из функции
			}
		}
		cout << "Такого электровоза нет!\n"; //если не нашелся ни в одном депо, пишем об этом 
	}

	//вывод структуры в консоль
	void show() {
		cout << endl << name << ":\n"; //пишем название ЖД
		if (count == 0) { //проверяем на пустоту
			cout << "\tЖелезная дорога пустая!\n";
			return;
		}
		for (int i = 0; i < count; i++) { //идем по всем депо
			cout << "\tДепо с номером " << d_arr[i].GetDnum() << ":\n"; //пишем номер текущего депо
			d_arr[i].show(); //выводим текущее депо
		}
	}

	//вывод структуры в файл
	void Write() {		
			ofstream fout;		//обьявляется поток записи в файл
			string path = "file.txt";
			try { fout.open(path, ios::trunc); }		//Открывается файл (или создается) по указанному пути
			catch (const ofstream::failure) {
				cerr << "Не удалось открыть файл" << endl;
			}
			fout << "Железная дорога" << endl << GetName() << endl;
			if (GetCount() == 0) {
				cout << "Стек пуст. Записано только название железной дороги." << endl;
				return;
			}
			for (int i = 0; i < GetCount(); i++) {
				fout << "Депо" << endl << GetDarr(i)->GetDnum() << endl;
				for (int j = 0; j < GetDarr(i)->GetCount(); j++) {
					fout << GetDarr(i)->GetTarr(j)->GetMark() << " - " << GetDarr(i)->GetTarr(j)->GetNum() << endl;
				}
				fout << "/Депо" << endl;
			}
			fout << "/Железная дорога";
			fout.close();	
	}
};