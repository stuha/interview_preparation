/*
 * implement a queue by using linked-list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef int qm_type;

struct member {
	qm_type data;
	struct member *next;
};

struct queue {
	struct member *front;
	/* I don't want to always go on the rear */
	struct member *rear;
};

enum {
	ERROR_ALLOC = 1,
	ERROR_QUEUE
};


struct queue *init()
{
	struct queue *initq = malloc(sizeof(struct queue));
	if (!initq)
		exit(ERROR_ALLOC);

	memset(initq, 0, sizeof(struct queue));

	initq->front = NULL;
	initq->rear = NULL;

	return initq;
}

void enqueue(struct queue *q, qm_type value)
{
	struct member *qm = malloc(sizeof(struct member));
	if (!qm)
		exit(ERROR_ALLOC);
	memset(qm, 0, sizeof(struct member));

	qm->data = value;
	if (q->rear == NULL) {
		q->front = qm;
		q->rear = qm;
	} else {
		q->rear->next = qm;
		q->rear = qm;
	}
	qm->next = NULL;
}

qm_type dequeue(struct queue *q)
{
	struct member *mtmp = q->front;
	qm_type qm_data = mtmp->data;

	q->front = q->front->next;
	free(mtmp);
	mtmp = NULL;

	return qm_data;
}

bool is_empty(struct queue *q)
{
	if (q->rear == NULL)
		return true;
	else
		return false;
}

void destroy(struct queue *q)
{
	struct member *mtmp = q->front;
	while (q->front != NULL) {
		q->front = q->front->next;
		free(mtmp);
		mtmp = q->front;
	}
	free(q);
	q = NULL;
}


/* Test case */
void show_all(struct queue *q)
{
	struct member *mtmp = q->front;

	printf("\n");
	while (mtmp != NULL) {
		int i = 0;
		printf("%d: %d  ", i, mtmp->data);
		mtmp = mtmp->next;
		i++;
	}
	printf("\n");
}

int main(int argc, char const* argv[])
{
	struct queue *testq;
	testq = init();

	enqueue(testq, 5);
	enqueue(testq, 6);
	enqueue(testq, 7);
	show_all(testq);

	dequeue(testq);
	show_all(testq);
	dequeue(testq);
	show_all(testq);

	destroy(testq);
	show_all(testq);
	return 0;
}
