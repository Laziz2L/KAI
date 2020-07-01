#include <string>
#include <iostream>
#include "Train.cpp"
using namespace std;

inline void int_input(int *in) {	//функция защищенного ввода int значений, обновляет поток cin и просит ввести число, пока не примет такое, которое можно записать в int 
	int flag = 1;			//принимает указатель на переменную, и записывает туда введенное значение
	while (flag) {
		cout << "Введите число\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

const int depot_len = 10; //длина депо (массива электровозов)

//статический упорядоченный список - депо
class Depot {
private:
	Train *t_arr;	//массив электровозов
	int len;		//длина массива электровозов
	int count;		//текущее количество электровозов в депо
	int d_num;		//номер депо
public:
	int GetDnum() {
		return d_num;
	}
	void SetNum(int num) {
		this->d_num = num;
	}

	Train* GetTarr() {
		return t_arr;
	}

	//Ф-я возвращает i-й элемент массива электровозов
	Train* GetTarr(int i) {
		return &t_arr[i];
	}

	int GetCount() {
		return count;
	}

	Depot() {
		len = depot_len;
		t_arr = new Train[depot_len];
		count = 0;
		d_num = -1;
	}

	//Depot(int d_num) {
	//	len = depot_len;
	//	t_arr = new Train[depot_len];
	//	count = 0;
	//	this->d_num = d_num;
	//}

	~Depot() {
		delete[] t_arr;
		t_arr = nullptr;
	}

	//добавление нового электровоза в депо
	void push(int reg_num, string mark) { //принимает регистрационный номер электровоза и марку электровоза
		if (count == len) { //проверка заполненности депо
			cout << "Не добавлено, т.к. это депо заполнено.\n";
			return;
		}
		if (count == 0) { //случай, когда электровоз добавляется в пустое депо
			t_arr[0].SetNum(reg_num);
			t_arr[0].SetMark(mark);
			++count;
			return;
		}
		//далее общий случай добавления электровоза в непустое депо
		int cur = 0; //сюда запишем индекс подходящей ячейки для нового электровоза
		while (t_arr[cur].GetNum() <= reg_num && cur < count) { //находим индекс подходящей ячейки для нового электровоза, сравнивая рег номера
			++cur;
		}
		for (int i = count; i > cur; i--) { //сдвигаем все ячейки, после нужной нам для ввода нового электровоза, вправо
			t_arr[i].SetNum(t_arr[i - 1].GetNum());
			t_arr[i].SetMark(t_arr[i - 1].GetMark());
		}
		t_arr[cur].SetNum(reg_num); //добавляем новый электровоз
		t_arr[cur].SetMark(mark);
		++count;
	}

	//поиск электровоза в депо
	int search(int reg_num) { //принимает регистрационный номер
		for (int i = 0; i < count; i++) {
			if (t_arr[i].GetNum() == reg_num) { //проходит по депо и сравнивает рег номер
				return i + 1;					//если находит, то возвращает индекс в массиве + 1
			}
		}
		return 0; //если прошел по депо и не нашел электровоз с заданным рег номером, возвращает 0
	}
	
	//удаление электровоза
	void pop() { //принимает рег номер электровоза, который нужно удалить
		if (count == 0) { //проверка на пустоту
			cout << "\nЭто депо пустое!\n";
			return;
		}
		cout << "Введите регистрационный номер электровоза, который нужно удалить\n";
		int reg_num;
		int_input(&reg_num); //приняли номер электровоза который нужно удалить
		int ind = search(reg_num) - 1; //ищем электровоз по рег номеру и передаем в ind индекс (-1 здесь т.к. search возвращает номер элемента считая с 1 а не с 0) 
		if (ind < 0) { 
			cout << "В этом депо нет такого электровоза\n"; //т.к в ind передается результат поиска -1, то если электровоз не был найден в депо, передается 0-1, т.е. ind = -1 < 0
			return;
		}
		for (int i = ind;i < count - 1; i++) { //сдвигаем влево все ячейки с ind+1 до конца
			t_arr[i].SetNum(t_arr[i + 1].GetNum());
			t_arr[i].SetMark(t_arr[i + 1].GetMark());
		}
		--count; //уменьшаем количество электровозов на 1
	}

	//вывод электровозов этого депо в консоль
	void show() {
		if (count == 0) { //проверка на пустоту
			cout << "\t\tЭто депо пустое\n";
			return;
		}
		for (int i = 0; i < count; i++) { //идем по всем электровозам и выводим информацию
			cout << "\t\tРегистрационный номер: " << t_arr[i].GetNum();
			cout << "\tМарка: " << t_arr[i].GetMark() << endl;
		}
	}
};