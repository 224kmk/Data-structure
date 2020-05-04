#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// ������ ��ȭ �������� Ȯ���ϴ� ����
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	if (isFull()) {
		printf("\n\n STACK is FULL ! \n");
		return;
	}
	else stack[++top] = item;
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	if (isEmpty()) {
		printf("\n\n STACK IS EMPTY !\n");
		return 0;
	}
	else return stack[top--];
}

//������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (isEmpty()) {
		printf("\n\n STACK IS EMPTY !\n");
		exit(1);
	}
	else return stack[top];
}

// ������ ���Ҹ� ����ϴ� ����
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d", stack[i]);
	printf("] ");
}

void main() {
	element item;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	getchar();
}