/*
 * implement a queue by using fixed-sized array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 16

typedef int queue_type;

struct queue {
	queue_type data[MAX_QUEUE_SIZE];
	int front;
	int count;
};

typedef enum {true, false} bool;

enum {
	ERROR_ALLOC = 1,
	ERROR_QUEUE_MAX,
	ERROR_QUEUE_MIN
};

struct queue *init()
{
	struct queue *initq;
	initq = malloc(sizeof(struct queue));

	/* copy from https://www.cs.bu.edu/teaching/c/queue/array/download/queue.c */
	if (initq == NULL) {
		fprintf(stderr, "Insufficient Memory for new Queue.\n");
		exit(ERROR_ALLOC);  /* Exit program, returning error code. */
	}

	memset(initq, 0, sizeof(struct queue));

	initq->front = 0;
	initq->count = 0;

	return initq;
}


bool enqueue(struct queue *q, int value)
{
	if (q->count >= MAX_QUEUE_SIZE)
		exit(ERROR_QUEUE_MAX);

	int index = (q->front + q->count) % MAX_QUEUE_SIZE;
	q->data[index] = value;
	q->count++;

	return true;
}

queue_type dequeue(struct queue *q)
{
	queue_type etmp;

	if (q->count <= 0)
		exit(ERROR_QUEUE_MIN);

	etmp = q->data[q->front];
#if 0
	if (q->front == MAX_QUEUE_SIZE)
		q->front = 0;
	else
		q->front++;
#endif
	q->front++;
	q->front %= MAX_QUEUE_SIZE;

	q->count--;

	return etmp;
}

bool is_empty(struct queue *q)
{
	if (q->count == 0)
		return true;
	else
		return false;
}

bool is_full(struct queue *q)
{
	if (q->count == MAX_QUEUE_SIZE)
		return true;
	else
		return false;
}



/* Testing */
void show_all(struct queue *q)
{
	for (int i = q->front; i < (q->front + q->count); i++) {
		printf("q[%d]: %d  ", i, q->data[i]);
	}
	printf("\n");
}

int main(void)
{
	struct queue *testq;
	testq = init();

	enqueue(testq, 5);
	enqueue(testq, 10);
	show_all(testq);

	printf("front is %d\n", testq->front);
	printf("count is %d\n", testq->count);

	printf("what dequeued is %d\n", dequeue(testq));
	show_all(testq);

	printf("front is %d\n", testq->front);
	printf("count is %d\n", testq->count);

	free(testq);
	return 0;
}
