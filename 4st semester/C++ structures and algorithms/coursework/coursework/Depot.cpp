#include <string>
#include <iostream>
#include "Train.cpp"
using namespace std;

inline void int_input(int *in) {	//������� ����������� ����� int ��������, ��������� ����� cin � ������ ������ �����, ���� �� ������ �����, ������� ����� �������� � int 
	int flag = 1;			//��������� ��������� �� ����������, � ���������� ���� ��������� ��������
	while (flag) {
		cout << "������� �����\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

const int depot_len = 10; //����� ���� (������� ������������)

//����������� ������������� ������ - ����
class Depot {
private:
	Train *t_arr;	//������ ������������
	int len;		//����� ������� ������������
	int count;		//������� ���������� ������������ � ����
	int d_num;		//����� ����
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

	//�-� ���������� i-� ������� ������� ������������
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

	//���������� ������ ����������� � ����
	void push(int reg_num, string mark) { //��������� ��������������� ����� ����������� � ����� �����������
		if (count == len) { //�������� ������������� ����
			cout << "�� ���������, �.�. ��� ���� ���������.\n";
			return;
		}
		if (count == 0) { //������, ����� ���������� ����������� � ������ ����
			t_arr[0].SetNum(reg_num);
			t_arr[0].SetMark(mark);
			++count;
			return;
		}
		//����� ����� ������ ���������� ����������� � �������� ����
		int cur = 0; //���� ������� ������ ���������� ������ ��� ������ �����������
		while (t_arr[cur].GetNum() <= reg_num && cur < count) { //������� ������ ���������� ������ ��� ������ �����������, ��������� ��� ������
			++cur;
		}
		for (int i = count; i > cur; i--) { //�������� ��� ������, ����� ������ ��� ��� ����� ������ �����������, ������
			t_arr[i].SetNum(t_arr[i - 1].GetNum());
			t_arr[i].SetMark(t_arr[i - 1].GetMark());
		}
		t_arr[cur].SetNum(reg_num); //��������� ����� ����������
		t_arr[cur].SetMark(mark);
		++count;
	}

	//����� ����������� � ����
	int search(int reg_num) { //��������� ��������������� �����
		for (int i = 0; i < count; i++) {
			if (t_arr[i].GetNum() == reg_num) { //�������� �� ���� � ���������� ��� �����
				return i + 1;					//���� �������, �� ���������� ������ � ������� + 1
			}
		}
		return 0; //���� ������ �� ���� � �� ����� ���������� � �������� ��� �������, ���������� 0
	}
	
	//�������� �����������
	void pop() { //��������� ��� ����� �����������, ������� ����� �������
		if (count == 0) { //�������� �� �������
			cout << "\n��� ���� ������!\n";
			return;
		}
		cout << "������� ��������������� ����� �����������, ������� ����� �������\n";
		int reg_num;
		int_input(&reg_num); //������� ����� ����������� ������� ����� �������
		int ind = search(reg_num) - 1; //���� ���������� �� ��� ������ � �������� � ind ������ (-1 ����� �.�. search ���������� ����� �������� ������ � 1 � �� � 0) 
		if (ind < 0) { 
			cout << "� ���� ���� ��� ������ �����������\n"; //�.� � ind ���������� ��������� ������ -1, �� ���� ���������� �� ��� ������ � ����, ���������� 0-1, �.�. ind = -1 < 0
			return;
		}
		for (int i = ind;i < count - 1; i++) { //�������� ����� ��� ������ � ind+1 �� �����
			t_arr[i].SetNum(t_arr[i + 1].GetNum());
			t_arr[i].SetMark(t_arr[i + 1].GetMark());
		}
		--count; //��������� ���������� ������������ �� 1
	}

	//����� ������������ ����� ���� � �������
	void show() {
		if (count == 0) { //�������� �� �������
			cout << "\t\t��� ���� ������\n";
			return;
		}
		for (int i = 0; i < count; i++) { //���� �� ���� ������������ � ������� ����������
			cout << "\t\t��������������� �����: " << t_arr[i].GetNum();
			cout << "\t�����: " << t_arr[i].GetMark() << endl;
		}
	}
};