#include "deque.h"
#include "../graph/graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_full(struct Deque *q);
bool has_one(struct Deque *q);

struct Deque *make_deque(int init_cap)
{
	struct Deque *q = malloc(sizeof *q);
	if (!q) exit(1);
	q->nodes = malloc(sizeof *q->nodes * (q->cap = init_cap));
	if (!q->nodes) exit(1);
	q->used = 0;
	q->front = q->rear = -1;
	return q;
}

void free_deque(struct Deque *q)
{
	q->cap = q->used = 0;
	q->front = q->rear = 0;
	for (int i = 0; i < q->used; i++)
		q->nodes[i] = NULL;
	free(q);
}

bool is_full(struct Deque *q)
{
	return q->cap == q->used;
}

bool is_empty(struct Deque *q)
{
	return q->used == 0;
}

bool has_one(struct Deque *q)
{
	return q->front == q->rear;
}

void expand_deque(struct Deque *q)
{
	printf("%s\n", __func__);
	int old_cap = q->cap;
	q->cap *= 2;
	struct Node **temp = malloc(sizeof *temp * q->cap);
	if (!temp) exit(1);
	int i = q->front, j = 0;
	while (i != q->rear) {
		temp[j++] = q->nodes[i];
		i = (i + 1) % old_cap;
	}
	temp[j] = q->nodes[i];
	q->nodes = temp;
	q->front = 0;
	q->rear = q->used - 1;
}

void push_front(struct Deque *q, struct Node *n)
{
	if (is_full(q)) expand_deque(q);
	q->front = is_empty(q) ? q->rear = 0 : (q->front - 1 + q->cap) % q->cap;
	q->nodes[q->front] = n;
	q->used++;
}

void push_rear(struct Deque *q, struct Node *n)
{
	if (is_full(q)) expand_deque(q);
	q->rear = is_empty(q) ? q->front = 0 : (q->rear + 1) % q->cap;
	q->nodes[q->rear] = n;
	q->used++;
}

struct Node *pop_front(struct Deque *q)
{
	struct Node *temp = is_empty(q) ? NULL : q->nodes[q->front];
	q->nodes[q->front] = NULL;
	q->front = has_one(q) ? q->rear = -1 : (q->front + 1) % q->cap;
	q->used = is_empty(q) ? 0 : q->used - 1;
	return temp;
}

struct Node *pop_rear(struct Deque *q)
{
	struct Node *temp = is_empty(q) ? NULL : q->nodes[q->rear];
	q->nodes[q->rear] = NULL;
	q->rear = has_one(q) ? q->front = -1 : (q->rear - 1 + q->cap) % q->cap;
	q->used = is_empty(q) ? 0 : q->used - 1;
	return temp;
}

