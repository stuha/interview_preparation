/*
 * Implementation of singly Linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct list {
	struct node *head;
	int size;
};

typedef enum {
	true,
	false
} bool;

struct list *init()
{
	struct list *ltmp;

	ltmp = malloc(sizeof(struct list));
	memset(ltmp, 0, sizeof(struct list));

	ltmp->head = NULL;
	ltmp->size = 0;
}

int size(struct list *l)
{
	return l->size;
}

bool is_empty(struct list *l)
{
	if (l->size == 0)
		return true;
	else
		return false;
}

int value_at(struct list *l, int index)
{
	struct node *ltmp;

	if (l->head == NULL) {
		printf("no value in list\n");
		exit(1);
	}

	if (index > l->size - 1) {
		printf("out of range!\n");
		exit(2);
	}

	/* Now, ltmp is at index 0 */
	ltmp = l->head;
	for (int i = 0; i < index; i++)
		ltmp = ltmp->next;

	return ltmp->data;
}

int push_front(struct list *l, int value)
{
	struct node *n;

	n = malloc(sizeof(struct node));
	memset(n, 0, sizeof(struct node));

	n->data = value;
	n->next = l->head;

	l->head = n;
	l->size++;

	return 0;
}

int pop_front(struct list *l)
{
	int dtmp;

	dtmp = l->head->data;

	struct node *ntmp = l->head;
	l->head = l->head->next;

	free(ntmp);
	l->size--;

	return dtmp;
}

int push_back(struct list *l, int value)
{
	struct node *n;

	n = malloc(sizeof(struct node));
	memset(n, 0, sizeof(struct node));

	n->data = value;
	n->next = NULL;

	struct node *ntmp = l->head;
	while (ntmp->next != NULL)
		ntmp = ntmp->next;

	ntmp->next = n;
	l->size++;

	return 0;
}

int pop_back(struct list *l)
{
	struct node *ntmp = l->head;

	for (int i = 1; i < l->size - 1; i++)
		ntmp = ntmp->next;

	int dtmp = ntmp->next->data;
	free(ntmp->next);
	ntmp->next = NULL;

	l->size--;

	return dtmp;
}

int main(void)
{
	struct list *testl;
	testl = init();
	//int a = value_at(testl, 0);

	push_front(testl, 5);
	push_front(testl, 10);
	int b = value_at(testl, 0);
	printf("b: %d\n", b);
	printf("size: %d\n", size(testl));

	printf("pop: %d\n", pop_front(testl));
	printf("size: %d\n", size(testl));
	push_back(testl, 20);
	push_back(testl, 30);

	printf("pop back: %d\n", pop_back(testl));

	int c = value_at(testl, 1);
	printf("c: %d\n", c);
	int d = value_at(testl, 2);
	printf("d: %d\n", d);

	//int c = value_at(testl, 1);
}
