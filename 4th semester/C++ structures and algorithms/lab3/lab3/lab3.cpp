#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

struct El {
	char value;
	El *next;
};

struct Fifo {
	El *sp;

	Fifo() { sp = NULL; }
	void push(char v);
	void show();
	void pop();
	
};

void Fifo::push(char v) {
	El *temp = new El;
	temp->value = v;
	temp->next = NULL;
	if (sp == NULL)
		sp = temp;
	else {
		El *cur = sp;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = temp;
	}
}

void Fifo::show() {
	cout << endl << "Queue :" << endl;
	if (sp == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	El *pCurrent = sp;
	while (pCurrent != NULL) {
		cout << pCurrent->value << endl;
		pCurrent = pCurrent->next;
	}
}

void Fifo::pop() {
	if (sp == NULL) {
		cout << "Queue is empty! That isn't possible." << endl;
		return;
	}
	El *temp = sp;
	sp = sp->next;
	delete temp;
}

int main() {
	Fifo queue;
	time_t t;
	char exit = 27;
	int action;
	int count;
	char letter;
	string el_s;
	while (!(_kbhit() && _getch() == exit)) {
		action = 1 + (rand() % 100);
		count = 1 + (rand() % 3);
		el_s = (count == 1) ? "element" : "elements";
		if (action % 2 == 0)
		{
			cout << endl << "Adding " << count << " " << el_s << endl;
			for (int i = 0; i < count; i++) {
				letter = 65 + (rand() % 26);
				queue.push(letter);
			}
		}
		else {
			cout << endl << "Deleting " << count << " " << el_s << endl;
			for (int i = 0; i < count; i++) {
				queue.pop();
			}
		}
		queue.show();
		t = time(NULL);
		while (time(NULL) - t < 5) {
			if (_kbhit()) {
				if (_getch() == exit)
					return 0;
				else
					break;
			}
		}
	}
	return 0;
}