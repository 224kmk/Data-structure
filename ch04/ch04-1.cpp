#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드구조 구조체 정의.
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의.
typedef struct {
	listNode* head;
} linkedList_h;

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// 연결리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// 노드를 pre 뒤에 삽인하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 마지막 노드로 삽인하는 연산
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	// 현재리스트가 공백이 아닌 경우
	temp = L->head;
	while (temp->link != NULL)temp = temp->link; // 현재 리스트의 마지막 노드를 찾음
	temp->link = newNode;
}

int main() {
	linkedList_h* L;
	L = createLinkedList_h(); // 공백 리스트 생성
	printf("(1) 공백 리스트 생성하기! \n");
	printList(L); getchar();

	printf("(2) 리스트에 [수] 노드 삽입하기! \n");
	insertFirstNode(L, (char*)"수");
	printList(L); getchar();

	printf("(3) 리스트에 마지막에 [금] 노드 삽입하기! \n");
	insertLastNode(L, (char*)"금");
	printList(L); getchar();

	printf("(4) 리스트에 첫 번째에 [월] 노드 삽입하기! \n");
	insertFirstNode(L, (char*)"월");
	printList(L); getchar();

	printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList(L);

	getchar();

	return 0;
}