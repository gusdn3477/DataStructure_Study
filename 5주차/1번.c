#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node *prev;
	char elem;
	struct Node *next;
}Node;

typedef struct List {
	Node *header;
	Node *curr;
	Node *trailer;
}List;

void add(List *list, int position, char item);
void delete(List *list, int position);
void get_entry(List *list, int position);
void print(List *list);
void initList(List **list);

int main(void) {

	int N;
	int len;
	char str[51] = { '\0' };
	char *p = NULL;
	int a;
	char b;
	List *list = NULL;
	Node *node = NULL;

	initList(&list);
	list->curr = list->header;

	scanf("%d", &N);
	getchar();
	
	for (int i = 0; i < N; i++) {
		gets(str);
		//len = strlen(str);

		if (str[0] == 'P')
			print(list);

		else if (str[0] == 'A') {
			a = str[2] - '0';
			b = str[4];
			add(list, a, b);
		}

		else if (str[0] == 'D') {
			a = str[2] - '0';
			delete(list, a);
		}

		else if (str[0] == 'G') {
			a = str[2] - '0';
			get_entry(list, a);
		}
	}

	while (list->curr != NULL) {
		node = list->curr;
		list->curr = list->curr->next;
		free(node);
	}

	free(list);
	return 0;
}

void add(List *list, int position, char item) {

	int c = 0;
	Node *a = (Node *)malloc(sizeof(Node));
	list->curr = list->header;
	a->elem = item;

	while (c < position - 1) {
		list->curr = list->curr->next;
		c++;
		if (list->curr == list->trailer)
			break;
	}

	if (list->curr == list->trailer)
		printf("invalid position\n");

	else {
		a->prev = list->curr->next->prev;
		list->curr->next->prev = a;
		a->next = list->curr->next;
		list->curr->next = a;
	}
}

void delete(List *list, int position) {

	int c = 0;
	list->curr = list->header;

	while (c < position) {
		list->curr = list->curr->next;
		c++;
		if (list->curr == list->trailer)
			break;
	}

	if (list->curr == list->trailer)
		printf("invalid position\n");

	else {
		list->curr->prev->next = list->curr->next;
		list->curr->next->prev = list->curr->prev;
		free(list->curr);
	}
}

void get_entry(List *list, int position) {

	int c = 0;
	list->curr = list->header;
	while (c < position) {
		list->curr = list->curr->next;
		c++;
		if (list->curr == list->trailer) 
			break;
		
	}

	if (list->curr == list->trailer) {
		printf("invalid position\n");
	}
	else
		printf("%c\n", list->curr->elem);
}

void print(List *list) {

	list->curr = list->header->next;

	while (list->curr != list->trailer) {
		printf("%c", list->curr->elem);
		list->curr = list->curr->next;
	}
	printf("\n");
}

void initList(List **list) {

	Node *a = (Node *)malloc(sizeof(Node));
	Node *b = (Node *)malloc(sizeof(Node));

	(*list) = (List *)malloc(sizeof(List));
	(*list)->header = a;
	(*list)->trailer = b;

	a->prev = NULL;
	a->next = b;
	b->prev = a;
	b->next = NULL;

}