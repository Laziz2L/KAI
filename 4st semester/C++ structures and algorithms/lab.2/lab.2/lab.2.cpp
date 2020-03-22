#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Fifo {
	int First;
	int Last;
	int count;
	int *arr;
	int len;

	Fifo(int length) {
		len = length;
		count = 0;
		First = 0;
		Last = 0;
		arr = new int[len];
	}

	void push() {
		if (count == len) {
			printf("There is no space to push!\n");
			return;
		}
		int v;
		printf("Enter the number\n");
		while (!scanf("%d", &v))
		{
			while (getchar() != '\n')
				printf("Enter the number.\n");
		}
		arr[Last] = v;
		++count;
		++Last;
		Last = (Last == len) ? 0 : Last;
	}

	void show() {
		if (count == 0) {
			printf("Queue is empty!\n");
			return;
		}
		int cur = First;
		for (int i = 0; i < count; i++) {
			printf("%d\n", arr[cur]);
			++cur;
			cur = (cur == len) ? 0 : cur;
		}
	}

	void pop() {
		if (count == 0) {
			printf("Queue is empty!\n");
			return;
		}
		arr[First] = NULL;
		--count;
		++First;
		First = (First == len) ? 0 : First;
	}
};


int main() {
	int flag;
	int val;
	printf("Enter the length of queue\n");
	while (!scanf("%d", &val))
	{
		while (getchar() != '\n')
			printf("Enter the number.\n");
	}
	Fifo queue = Fifo(val);
	while (true)
	{
		printf("\nChoose the action and enter its number:\n");
		printf("1 - Add new element\n");
		printf("2 - Delete element\n");
		printf("3 - Show queue\n");
		printf("4 - Shut down the program\n");
		while (!scanf("%d", &flag))
		{
			while (getchar() != '\n')
				printf("Enter the number.\n");
		}
		switch (flag)
		{
		case 1:
			queue.push();
			break;
		case 2:
			queue.pop();
			break;
		case 3:
			queue.show();
			break;
		case 4:
			return 0;
			break;
		default:
			printf("Error, try again\n");
			break;
		}
	}
}