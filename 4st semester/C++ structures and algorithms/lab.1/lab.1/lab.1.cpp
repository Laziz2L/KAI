#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct El {
	int value;
	El *prev;
};

struct Lifo {
	El *sp;

	Lifo() { sp = NULL;}
	void push(int v);
	void show();
	void pop();
	void randpush();
	El* get_pop_ptr();
	void push_ptr(El *n);
};

void Lifo::push(int v) {
	El *temp = new El;
	temp->value = v;
	temp->prev = sp;
	sp = temp;
}

void Lifo::randpush() {
	int n;
	printf("Введите количество чисел для добавления\n");
	while (!scanf("%d", &n))
	{
		while (getchar() != '\n')
			printf("Введите заново.\n");
	}
	while (n > 0) {
		push(rand());
		--n;
	}
}

void Lifo::show() {
	if (sp == NULL) {
		printf("Стек пуст!\n");
		return;
	}
	printf("\n");
	El *pCurrent = sp;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->value);
		pCurrent = pCurrent->prev;
	}
	printf("\n");
}

void Lifo::pop() {
	if (sp == NULL) {
		printf("Стек пуст!\n");
		return;
	}
	El *temp = sp;
	sp = sp->prev;
	delete temp;
}

El* Lifo::get_pop_ptr() {
	El *temp = sp;
	if (sp != NULL)
		sp = sp->prev;
	return(temp);
}

void Lifo::push_ptr(El *n) {
	if (n == NULL) {
		printf("Стек, из которого берется эелмент, пуст!\n");
		return;
	}
	n->prev = sp;
	sp = n;
}

int main() {
	setlocale(LC_ALL, "rus");
	int flag;
	int val;
	Lifo live;
	Lifo del;
	while (true)
	{
		printf("Что нужно сделать? Введите номер :\n");
		printf("1 - Ввести новый элемент\n");
		printf("2 - Ввести несколько случайных элементов\n");
		printf("3 - Ввести элемент из вспомогательного стека\n");
		printf("4 - Удалить элемент безвозвратно\n");
		printf("5 - Поместить элемент в вспомогательный стек\n");
		printf("6 - Вывести основной стек\n");
		printf("7 - Вывести вспомогательный стек\n");
		printf("8 - Завершить работу\n");
		while (!scanf("%d", &flag))
		{
			while (getchar() != '\n')
				printf("Введите заново.\n");
		}
		switch (flag)
		{
		case 1:
			printf("Введите число :\n");
			while (!scanf("%d", &val))
			{
				while (getchar() != '\n')
					printf("Введите заново.\n");
			}
			live.push(val);
			break;
		case 2:
			live.randpush();
			break;
		case 3:
			live.push_ptr(del.get_pop_ptr());
			break;
		case 4:
			live.pop();
			break;
		case 5:
			del.push_ptr(live.get_pop_ptr());
			break;
		case 6:
			live.show();
			break;
		case 7:
			del.show();
			break;
		case 8:
			return 0;
			break;
		default:
			printf("Произошла ошибка, введите заново\n");
			break;
		}
	}
}
