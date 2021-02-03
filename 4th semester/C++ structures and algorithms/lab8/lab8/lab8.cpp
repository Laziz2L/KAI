#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

void input(int *in) {
	int flag = 1;
	while (flag) {
		cout << "Enter the number\n";
		if (cin >> *in)
			flag = 0;
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

struct ListElement {
	int val;
	ListElement *next;
};

struct List {
	string name;
	ListElement *head;
	List *next_list;
};

struct ListOfLists {
	List *head_list;

	ListOfLists() {
		head_list = new List();
		head_list->name = "header";
		head_list->head = new ListElement();
		head_list->head->val = NULL;
		head_list->head->next = NULL;
		head_list->next_list = NULL;
	}

	void push_first() {
		cout << "\nList of lists is empty. Enter first list name\n";
		string name;
		cin >> name;
		List *add = new List();
		add->name = name;
		add->head = new ListElement();
		add->head->val = NULL;
		add->head->next = NULL;
		add->next_list = NULL;
		head_list->next_list = add;
	}

	void push_after() {
		if (head_list->next_list == NULL) {
			push_first();
		}
		else {
			cout << "\nEnter the name of list after which you want add new\n";
			string name;
			cin >> name;
			List *cur = head_list->next_list;
			while (cur) {
				if (cur->name == name) {
					cout << "\nEnter the name of new list\n";
					cin >> name;
					List *add = new List();
					add->name = name;
					add->head = new ListElement();
					add->head->val = NULL;
					add->head->next = NULL;
					add->next_list = cur->next_list;
					cur->next_list = add;
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void push_before() {
		if (head_list->next_list == NULL) {
			push_first();
		}
		else {
			cout << "\nEnter the name of list before which you want add new\n";
			string name;
			cin >> name;
			List *cur = head_list;
			while (cur->next_list) {
				if (cur->next_list->name == name) {
					cout << "\nEnter the name of new list\n";
					cin >> name;
					List *add = new List();
					add->name = name;
					add->head = new ListElement();
					add->head->val = NULL;
					add->head->next = NULL;
					add->next_list = cur->next_list;
					cur->next_list = add;
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void pop() {
		if (head_list->next_list == NULL) {
			cout << "\nList of lists is empty.\n";
		}
		else {
			cout << "\nEnter the name of list you want to delete\n";
			string name;
			cin >> name;
			List *cur = head_list;
			while (cur->next_list) {
				if (cur->next_list->name == name) {
					List *del = cur->next_list;
					cur->next_list = del->next_list;
					delete del;
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void el_push_first(string name) {
		List *cur = head_list->next_list;
		while (cur) {
			if (cur->name == name) {
				cout << "\nList is empty. Enter the first element\n";
				int val;
				input(&val);
				ListElement *add = new ListElement();
				add->next = NULL;
				add->val = val;
				cur->head->next = add;
				return;
			}
			cur = cur->next_list;
		}
	}

	void el_push_after() {
		if (head_list->next_list == NULL) {
			push_first();
		}
		else {
			cout << "\nEnter the name of list which you want to add new element in\n";
			string name;
			cin >> name;
			List *cur = head_list->next_list;
			while (cur) {
				if (cur->name == name) {
					if (cur->head->next == NULL) {
						el_push_first(name);
						return;
					}
					else {
						cout << "\nEnter the element after which you want to add new\n";
						int val;
						input(&val);
						ListElement *cur_el = cur->head->next;
						while (cur_el) {
							if (cur_el->val == val) {
								cout << "\nEnter new element\n";
								input(&val);
								ListElement *add = new ListElement();
								add->val = val;
								add->next = cur_el->next;
								cur_el->next = add;
								return;
							}
							cur_el = cur_el->next;
						}
					}
					cout << "\nThere is no such element\n";
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void el_push_before() {
		if (head_list->next_list == NULL) {
			push_first();
		}
		else {
			cout << "\nEnter the name of list which you want to add new element in\n";
			string name;
			cin >> name;
			List *cur = head_list->next_list;
			while (cur) {
				if (cur->name == name) {
					if (cur->head->next == NULL) {
						el_push_first(name);
						return;
					}
					else {
						cout << "\nEnter the element before which you want to add new\n";
						int val;
						input(&val);
						ListElement *cur_el = cur->head;
						while (cur_el->next) {
							if (cur_el->next->val == val) {
								cout << "\nEnter new element\n";
								input(&val);
								ListElement *add = new ListElement();
								add->val = val;
								add->next = cur_el->next;
								cur_el->next = add;
								return;
							}
							cur_el = cur_el->next;
						}
					}
					cout << "\nThere is no such element\n";
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void el_pop() {
		if (head_list->next_list == NULL) {
			cout << "\nList of lists is empty.\n";
		}
		else {
			cout << "\nEnter the name of list which you want to delete element in\n";
			string name;
			cin >> name;
			List *cur = head_list->next_list;
			while (cur) {
				if (cur->name == name) {
					if (cur->head->next == NULL) {
						cout << "\nList is empty.\n";
						return;
					}
					else {
						cout << "\nEnter the element which you want to delete\n";
						int val;
						input(&val);
						ListElement *cur_el = cur->head;
						while (cur_el->next) {
							if (cur_el->next->val == val) {
								ListElement *del = cur_el->next;
								cur_el->next = del->next;
								delete del;
								return;
							}
							cur_el = cur_el->next;
						}
					}
					cout << "\nThere is no such element\n";
					return;
				}
				cur = cur->next_list;
			}
			cout << "\nThere is no such list\n";
		}
	}

	void show() {
		if (head_list->next_list == NULL) {
			cout << "\nList of lists is empty.\n";
			return;
		}
		cout << "\nLists :\n";
		List *cur_list = head_list->next_list;
		ListElement *cur_el = new ListElement();
		while (cur_list) {
			cout << endl << cur_list->name << ":\n";
			cur_el = cur_list->head->next;
			if (!cur_el)
				cout << "empty\n";
			while (cur_el) {
				cout << cur_el->val << endl;
				cur_el = cur_el->next;
			}
			cur_list = cur_list->next_list;
		}
	}

	void search() {
		if (head_list->next_list == NULL) {
			cout << "\nList of lists is empty.\n";
		}
		else {
			cout << "\nEnter the element to search\n";
			int val;
			input(&val);
			List *cur_list = head_list->next_list;
			ListElement *cur_el = new ListElement();
			int i;
			while (cur_list) {
				cur_el = cur_list->head->next;
				i = 1;
				while (cur_el) {
					if (cur_el->val == val) {
						cout << "\nThe element " << val << " is located in list named " <<
							cur_list->name << " and its number there is " << i << endl;
						return;
					}
					++i;
					cur_el = cur_el->next;
				}
				cur_list = cur_list->next_list;
			}
			cout << "\nThere is no such element\n";
		}
	}
};

int main() {
	ListOfLists *lol = new ListOfLists();
	int flag;
	int n;
	while (true) {
		flag = 1;
		while (flag) {
			cout << "\nChoose the action and enter its number" << endl;
			cout << "1 - Show" << endl;
			cout << "2 - Search element" << endl;
			cout << "3 - Add new list after some" << endl;
			cout << "4 - Add new list before some" << endl;
			cout << "5 - Delete list" << endl;
			cout << "6 - Add new element after some" << endl;
			cout << "7 - Add new element before some" << endl;
			cout << "8 - Delete element" << endl;
			cout << "9 - Terminate the program" << endl;
			input(&n);
			if (n >= 1 && n <= 9) {
				flag = 0;
			}
		}
		switch (n) {
		case 1:
			lol->show();
			break;
		case 2:
			lol->search();
			break;
		case 3:
			lol->push_after();
			break;
		case 4:
			lol->push_before();
			break;
		case 5:
			lol->pop();
			break;
		case 6:
			lol->el_push_after();
			break;
		case 7:
			lol->el_push_before();
			break;
		case 8:
			lol->el_pop();
			break;
		case 9:
			return 0;
			break;
		}
	}
}