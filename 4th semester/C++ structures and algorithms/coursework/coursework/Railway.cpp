#include <string>
#include <iostream>
#include "Depot.cpp"
#include <fstream>
using namespace std;

const int railway_len = 10; //����� �� (������� ����)

inline bool issp(char sym) {
	if (sym == ' ' || sym == '\t' || sym == '\n' || sym == '\v' || sym == '\f' || sym == '\r') {
		return true;
	}
	else return false;
}

inline void string_input(string *in) {
	getline(cin, *in);
	if (*in == "") {
		cout << "������! ������� ������ ������, ���������� ��� ���.\n";
		string_input(in);
	}
	else if (issp((*in)[0])) {
		cout << "������! ������ ���������� � ����������� �������, ���������� ��� ���.";
		cout << endl;
		string_input(in);
	}
}

//����������� ���� - �������� ������
class Railway {
private:
	Depot *d_arr; //������ ����
	int count;	//������� ���������� ���� 
	int len;	//����� ������� ����
	string name;//�������� ����
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

	//���������� ����
	void push_depot() { 
		if (count == len) { //�������� ������������� �������
			cout << "\n�������� ������ ���������!\n";
			return;
		}
		int d_num;
		cout << "\n������� ����� ����\n"; 
		int_input(&d_num); //��������� �� ������������ ����� ������ ����		
		d_arr[count].SetNum(d_num); //������ ����� ���� � ������ ��������� ������
		++count;
	}

	//���������� ���� � ��� ������ ���������� - ������� ����, ���������� ������������ ��� ����� � �����
	void push_depot(int num) {
		d_arr[count].SetNum(num);
		++count;
	}

	//�������� ���� 
	void pop_depot() {
		if (count == 0) { //�������� �� �������
			cout << "\n�������� ������ ������!\n";
			return;
		}
		--count; //������ ��������� ���������� ����, ��� � ��� �� ����� �������������� � ������ �������� ��������� ������
	}

	//���������� �����������
	void push_train() {
		if (count == 0) { //�������� �� ������� (���� �� ���� ���� ����, ���� ����� �������� ����������)
			cout << "\n�������� ������ ������!\n";
			return;
		}
		int d_num;
		cout << "\n������� ����� ����, � ������� ������ �������� ����������\n";
		int_input(&d_num); //��������� ����� ����, � ������� ����� �������� ����������
		for (int i = 0; i < count; i++) { //�������� �� ������� ����
			if (d_arr[i].GetDnum() == d_num) { //���� ����� ������ ���� �� ������
				int reg_num;
				string mark;
				cout << "������� ��������������� ����� �����������\n";
				int_input(&reg_num); //��������� ��������������� ����� �����������
				cout << "������� ����� �����������\n";
				//cin >> mark;		//��������� ����� �����������
				//getline(cin, mark);
				string_input(&mark);
				d_arr[i].push(reg_num, mark); //��������� ���������� � ������ ������ ������� ����
				return; //������� �� �������
			}
		}
		cout << "������ ���� ���!\n"; //���� ����� ����, �� ����������� ���� �� ���� �������, ����� �� ����
	}

	//���������� ����������� � ��� ������� ����������� - ������� ����, ��� ������� � ������, ���������� ������������ ��� ����� � �����
	void push_train(int depot, int num, string mark) {
		for (int i = 0; i < count; i++) {
			if (d_arr[i].GetDnum() == depot) {
				d_arr[i].push(num, mark);
				return;
			}
		}
	}

	//�������� �����������; �������� �� ������� � ����� ���� ����� �� ��� � ����������
	void pop_train() {
		if (count == 0) {
			cout << "\n�������� ������ ������!\n";
			return;
		}
		int d_num;
		cout << "\n������� ����� ����, � ������� ������ ������� ����������\n";
		int_input(&d_num);
		for (int i = 0; i < count; i++) {
			if (d_arr[i].GetDnum() == d_num) {
				/*int reg_num;*/
				d_arr[i].pop();
				return;
			}
		}
		cout << "������ ���� ���!\n";
	}

	//����� �����������, ���� �� ���� ���������, �� ��������� ��� ����
	void search_train() {
		if (count == 0) { //�������� �� �������
			cout << "\n�������� ������ ������!\n";
			return;
		}
		int reg_num;
		cout << "\n������� ��������������� ����� �����������, ������� ����� �����\n";
		int_input(&reg_num); //��������� ��� ����� �����������, ������� ����� �����
		int cur = 0;
		for (int i = 0;i < count; i++) { //���� �� ���� ����
			cur = d_arr[i].search(reg_num); //���������� � cur ��������� ������ (������ � ������� ������������, ���� 0 ���� �� ������)
			if (cur != 0) { //���� ������� � ������� (i-��) ����, ����� ����������
				cout << "���������� � ��������������� ������� " << reg_num;
				cout << " ���������� � ���� ��� ������� " << d_arr[i].GetDnum();
				cout << " �� ������� " << cur;
				cout << ", ��� ����� - " << d_arr[i].GetTarr()[cur - 1].GetMark() << endl;
				return;		//� ������� �� �������
			}
		}
		cout << "������ ����������� ���!\n"; //���� �� ������� �� � ����� ����, ����� �� ���� 
	}

	//����� ��������� � �������
	void show() {
		cout << endl << name << ":\n"; //����� �������� ��
		if (count == 0) { //��������� �� �������
			cout << "\t�������� ������ ������!\n";
			return;
		}
		for (int i = 0; i < count; i++) { //���� �� ���� ����
			cout << "\t���� � ������� " << d_arr[i].GetDnum() << ":\n"; //����� ����� �������� ����
			d_arr[i].show(); //������� ������� ����
		}
	}

	//����� ��������� � ����
	void Write() {		
			ofstream fout;		//����������� ����� ������ � ����
			string path = "file.txt";
			try { fout.open(path, ios::trunc); }		//����������� ���� (��� ���������) �� ���������� ����
			catch (const ofstream::failure) {
				cerr << "�� ������� ������� ����" << endl;
			}
			fout << "�������� ������" << endl << GetName() << endl;
			if (GetCount() == 0) {
				cout << "���� ����. �������� ������ �������� �������� ������." << endl;
				return;
			}
			for (int i = 0; i < GetCount(); i++) {
				fout << "����" << endl << GetDarr(i)->GetDnum() << endl;
				for (int j = 0; j < GetDarr(i)->GetCount(); j++) {
					fout << GetDarr(i)->GetTarr(j)->GetMark() << " - " << GetDarr(i)->GetTarr(j)->GetNum() << endl;
				}
				fout << "/����" << endl;
			}
			fout << "/�������� ������";
			fout.close();	
	}
};