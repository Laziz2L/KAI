#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void int_input(int *in) {
	int flag = 1;
	while (flag) {
		cout << "Enter the number\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

int depot_len = 3;

struct Train {
	int reg_num;
	string mark;
};

struct Depot {
	Train* t_arr;
	int len;
	int count;
	int d_num;
	
	Depot() {
		t_arr = new Train[depot_len];
		len = depot_len;
		count = 0;
	}

	Depot(int d_num) {
		t_arr = new Train[depot_len];
		len = depot_len;
		count = 0;
		this->d_num = d_num;
	}

	void push(int reg_num, string mark) {
		if (count == len) {
			cout << "Wasn't pushed. This depot is full\n";
			return;
		}
		if (count == 0) {
			t_arr[0].reg_num = reg_num;
			t_arr[0].mark = mark;
			++count;
			return;
		}
		int cur = 0;
		while (t_arr[cur].reg_num <= reg_num && cur < count) {
			++cur;
		}
		for (int i = count; i > cur; i--) {
			t_arr[i] = t_arr[i - 1];
		}
		t_arr[cur].reg_num = reg_num;
		t_arr[cur].mark = mark;
		++count;
	}

	int search(int reg_num) {
		for (int i = 0; i < count; i++) {
			if (t_arr[i].reg_num == reg_num) {
				return i+1;
			}
		}
		return 0;
	}

	void pop(int ind) {
		if (ind < 0) {
			cout << "There is no such train\n";
			return;
		}
		for (int i = ind;i < count - 1; i++) {
			t_arr[i] = t_arr[i + 1];
		}
		--count;
	}

	void show() {
		if (count == 0) {
			cout << "\t\tThis depot is empty\n";
			return;
		}
		for (int i = 0; i < count; i++) {
			cout << "\t\tRegistration number: " << t_arr[i].reg_num;
			cout << "\tMark: " << t_arr[i].mark << endl;
		}
	}
};

struct Railway {
	Depot* d_arr;
	int count;
	int len;
	string name;

	Railway(int len, string name) {
		d_arr = new Depot[len];
		this->len = len;
		count = 0;
		this->name = name;
	}

	void push_depot() {
		if (count == len) {
			cout << "\nRailway is full!\n";
			return;
		}
		int d_num;
		cout << "\nEnter the depot number\n";
		int_input(&d_num);
		Depot add = Depot(d_num);
		d_arr[count] = add;
		++count;
	}

	void pop_depot() {
		if (count == 0) {
			cout << "\nRailway is empty!\n";
			return;
		}
		--count;
		d_arr[count] = Depot();
	}

	void push_train() {
		if (count == 0) {
			cout << "\nRailway is empty!\n";
			return;
		}
		int d_num;
		cout << "\nEnter the depot number to which you want to add the train\n";
		int_input(&d_num);
		for (int i = 0; i < count; i++) {
			if (d_arr[i].d_num == d_num) {
				int reg_num;
				string mark;
				cout << "Enter the registration number of new train\n";
				int_input(&reg_num);
				cout << "Enter the mark of new train\n";
				cin >> mark;
				d_arr[i].push(reg_num, mark);
				return;
			}
		}
		cout << "There is no such depot in the railway\n";
	}

	void pop_train() {
		if (count == 0) {
			cout << "\nRailway is empty!\n";
			return;
		}
		int d_num;
		cout << "\nEnter the depot number in which you want to delete the train\n";
		int_input(&d_num);
		for (int i = 0; i < count; i++) {
			if (d_arr[i].d_num == d_num) {
				int reg_num;
				cout << "Enter the registration number of train that you want to delete\n";
				int_input(&reg_num);
				d_arr[i].pop(d_arr[i].search(reg_num) - 1);
				return;
			}
		}
		cout << "There is no such depot in the railway\n";
	}

	void search_train() {
		if (count == 0) {
			cout << "\nRailway is empty!\n";
			return;
		}
		int reg_num;
		cout << "\nEnter registration number which you want to search\n";
		int_input(&reg_num);
		int cur = 0;
		for (int i = 0;i < count; i++) {
			cur = d_arr[i].search(reg_num);
			if (cur != 0) {
				cout << "Train with registration number " << reg_num;
				cout << " is located in depot with number " << d_arr[i].d_num;
				cout << " on position" << cur;
				cout << ", his mark is " << d_arr[i].t_arr[cur - 1].mark << endl;
				return;
			}
		}
		cout << "There is no such train\n";
	}

	void show() {
		cout << endl << name << ":\n";
		if (count == 0) {
			cout<< "\tRailway is empty!\n";
			return;
		}
		for (int i = 0; i < count; i++) {
			cout << "\tDepot with number " << d_arr[i].d_num << ":\n";
			d_arr[i].show();
		}
	}
};

int main() {
	string name;
	int length;
	cout << "Enter the name of your railway\n";
	cin >> name;
	cout << "How many depots does your railway can hold? ";
	int_input(&length);
	Railway rway = Railway(length, name);
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show" << endl;
			cout << "2 - Search train" << endl;
			cout << "3 - Add new depot" << endl;
			cout << "4 - Delete depot" << endl;
			cout << "5 - Add new train" << endl;
			cout << "6 - Delete train" << endl;
			cout << "7 - Terminate the program" << endl;
			int_input(&n);
			if (n >= 1 && n <= 7) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			rway.show();
			break;
		case 2:
			rway.search_train();
			break;
		case 3:
			rway.push_depot();
			break;
		case 4:
			rway.pop_depot();
			break;
		case 5:
			rway.push_train();
			break;
		case 6:
			rway.pop_train();
			break;
		case 7:
			return 0;
			break;
		}
	}
}