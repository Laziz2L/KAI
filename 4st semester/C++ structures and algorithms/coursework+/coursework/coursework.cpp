#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
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

const int depot_len = 10;
const int railway_len = 10;

struct Train {
	int reg_num;
	string mark;
};

struct Depot {
	Train t_arr[depot_len];
	int len;
	int count;
	int d_num;
	
	Depot() {
		len = depot_len;
		count = 0;
	}

	Depot(int d_num) {
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
	Depot d_arr[railway_len];
	int count;
	int len;
	string name;

	Railway() {
		len = railway_len;
		count = 0;
		name = "";
	}

	Railway(string name) {
		len = railway_len;
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
	string path = "file.txt";
	Railway rway;
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Load structure from file" << endl;
			cout << "2 - Create new" << endl;
			int_input(&n);
			if (n >= 1 && n <= 2) {
				flag = 0;
			}
		}
		if (n == 1) {
			ifstream fin;
			fin.open(path);
			if (!fin.is_open()) {
				cout << "\nError! Unable to open file, create new structure" << endl;
				fin.close();
			}
			else {
				fin.read((char*)&rway, sizeof(Railway));
				fin.close();
				break;
			}
		}
		else if (n == 2) {
			string name;
			cout << "\nEnter the name of your railway\n";
			cin >> name;
			rway = Railway(name);
			break;
		}
	}
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
			cout << "7 - Write in file" << endl;
			cout << "8 - Terminate the program" << endl;
			int_input(&n);
			if (n >= 1 && n <= 8) {
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
		case 8:
			return 0;
			break;
		}
		if (n == 7) {
			size_t sz = sizeof(rway);
			ofstream fout;
			fout.open(path);
			fout.close();
			fout.open(path, ofstream::app);
			if (!fout.is_open()) {
				cout << "Error!" << endl;
			}
			else {
				cout << "Opened!" << endl;
				fout.write((char*)&rway, sz);
			}
			fout.close();
		}
	}
}