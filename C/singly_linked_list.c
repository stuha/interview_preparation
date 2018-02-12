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
	if (!ltmp)
		exit(1);
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
	if (!n)
		return 1;
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
	if (!n)
		return 1;
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

int front(struct list *l)
{
	value_at(l, 0);
}

int back(struct list *l)
{
	value_at(l, l->size - 1);
}

bool insert(struct list *l, int index, int value)
{
	if (index < 0) {
		printf("Are you kidding me?!\n");
		return false;
	}

	if (index > l->size - 1) {
		printf("Your index is out of range!\n");
		return false;
	}

	if (index == 0)
		push_front(l, value);
	else {
		struct node *nnew = malloc(sizeof(struct node));
		if (!nnew)
			return false;
		memset(nnew, 0, sizeof(struct node));
		nnew->data = value;
		/* ntmp is at index 0 */
		struct node *ntmp = l->head;
		for (int i = 0; i < index - 1; i++)
			ntmp = ntmp->next;

		nnew->next = ntmp->next;
		ntmp->next = nnew;

		l->size++;
	}

	return true;
}

bool erase(struct list *l, int index)
{
	if (index < 0) {
		printf("You are kidding me!\n");
		return false;
	}
	if (index > l->size - 1) {
		printf("Your index is out of range!\n");
		return false;
	}
	if (index == 0) {
		free(l->head);
		l->head = l->head->next;

		l->size--;
	} else {
		struct node *ntmp = l->head;
		/* find the previous of the index item */
		for (int i = 0; i < index - 1; i++)
			ntmp = ntmp->next;
		free(ntmp->next);
		ntmp->next = ntmp->next->next;

		l->size--;
	}
	return true;
}

int value_n_from_end(struct list *l, int npos)
{
	if (npos < 0) {
		printf("Kidding!\n");
		return -1;
	}
	if (npos > l->size - 1) {
		printf("Out of range!\n");
		return -1;
	}

	struct node *ntmp = l->head;
	for (int i = 1; i < l->size - npos; i++)
		ntmp = ntmp->next;

	return ntmp->data;
}

void reverse(struct list *l)
{
	struct node *prev, *cur;
	if (l->head != NULL) {
		prev = l->head;
		cur = l->head->next;
		l->head = l->head->next;

		prev->next = NULL;

		while (l->head != NULL) {
			l->head = l->head->next;
			cur->next = prev;

			prev = cur;
			cur = l->head;
		}

		l->head = prev;
	}
}

int remvoe_value(struct list *l, int value)
{
	if (l->head != NULL) {
		struct node *cur = l->head;
		struct node *prev = l->head;
		if (cur->data == value) {
			free(cur);
			l->head = cur->next;
			l->size--;
			return 1;
		}
		while (cur->next != NULL) {
			prev = cur;
			cur = cur->next;
			if (cur->data == value) {
				free(cur);
				prev->next = cur->next;
				l->size--;
				return 1;
			}
		}
	}

	return 0;
}

bool destroy(struct list *l)
{
	for (int i = 1; i <= l->size; i++)
		if (erase(l, l->size - i) == false)
			return false;

	free(l);

	return true;
}


/* Testing */
void show_all(struct list *l)
{
	struct node *ntmp = l->head;
	int i = 1;

	printf("\nHEAD -> ");
	printf("0: %d -> ", ntmp->data);
	while (ntmp->next != NULL) {
		ntmp = ntmp->next;
		printf("%d: %d -> ", i, ntmp->data);
		i++;
	}
	printf("|||\n");
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
	//int d = value_at(testl, 2); // yes, out of range!
	//printf("d: %d\n", d);

	printf("front: %d\n", front(testl));
	printf("back: %d\n", back(testl));

	insert(testl, 0, 100);
	insert(testl, 1, 200);
	insert(testl, -10, 300);

	show_all(testl);
	erase(testl, 0);
	show_all(testl);
	erase(testl, 2);
	show_all(testl);

	insert(testl, 0, 100);
	insert(testl, 1, 200);
	insert(testl, 3, 300);
	erase(testl, 1);
	insert(testl, 3, 10);
	insert(testl, 4, 20);
	insert(testl, 5, 30);
	show_all(testl);

	printf("n0: %d\n", value_n_from_end(testl, 0));
	printf("n2: %d\n", value_n_from_end(testl, 2));
	printf("n3: %d\n", value_n_from_end(testl, 3));

	reverse(testl);
	show_all(testl);
	push_back(testl, 5);

	remvoe_value(testl, 5);
	show_all(testl);
	remvoe_value(testl, 300);
	show_all(testl);
	remvoe_value(testl, 100);
	show_all(testl);

	destroy(testl);
#if 0
	struct list *testl2 = init();
	push_front(testl2, 100);
	reverse(testl2);
	show_all(testl2);

	destroy(testl2);
	/* Now, segmentation fault */
	//show_all(testl);
#endif
}
