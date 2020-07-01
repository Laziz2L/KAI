#include <string>
using namespace std;

class Train {
private:
	int *reg_num; //регистрационный номер электровоза
	string *mark; //марка электровоза
public:
	int GetNum() {
		return *reg_num;
	}
	void SetNum(int num) {
		*reg_num = num;
	}

	string GetMark() {
		return *mark;
	}
	void SetMark(string m) {
		*mark = m;
	}

	Train() {
		reg_num = new int();
		mark = new string();
	}

	~Train() {
		delete reg_num;
		reg_num = nullptr;
		delete mark;
		mark = nullptr;
	}
};