#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;				// 스택 원소(element)의 자료형을 int로 정의

element stack[STACK_SIZE];			// 1차원 배열 스택 선언
int top = -1;						// top 초기화

// 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// 스택이 포화 상태인지 확인하는 연산
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	if (isFull()) {					// 스택이 포화 상태인 경우
		printf("\n\n STACK is FULL ! \n");
		return;
	}
	else stack[++top] = item;		// top를 증가시킨 후 현재 top에 원소 삽입
	// top = top +1
	// stack[top] = item;
	// 위에 두줄이 stack[++top] = item; 한줄로 되어있는것.

	// a = ++top
	// a = top++ 서로 다름
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	if (isEmpty()) {				// 스택이 공백 상태인 경우
		printf("\n\n STACK IS EMPTY !\n");
		return 0; // 다르게 해줘야 정확히 됨
	}
	else return stack[top--];		// 현재 top의 원소를 삭제한 후 top 감소
	// top = top - 1;
	// return stack[top + 1];
	// 위의 두줄이 stack[top--] 한줄로 되어있는것.
}

//스택의 top 원소를 검색하는 연산
element peek() {
	if (isEmpty()) {				// 스택이 공백 상태인 경우
		printf("\n\n STACK IS EMPTY !\n");
		exit(1);
	}
	else return stack[top];			// 현재 top의 원소 확인
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d", stack[i]);
	printf("] ");
}

void main() {
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1); printStack();			// 1 삽입
	push(2); printStack();			// 2 삽입
	push(3); printStack();			// 3 삽입

	item = peek(); printStack();	// 현재 top의 원소 출력
	printf("peek => %d", item);

	item = pop(); printStack();		// 삭제
	printf("\t pop => %d", item);

	item = pop(); printStack();		// 삭제
	printf("\t pop => %d", item);

	item = pop(); printStack();		// 삭제
	printf("\t pop => %d", item);

	getchar();
}