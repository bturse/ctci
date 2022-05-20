#ifndef DEQUE_H
#define DEQUE_H

#include "../graph/graph.h"

struct Deque {
	struct Node **nodes;
	int front, rear, cap, used;
};

struct Deque *make_deque(int init_cap);
void free_deque(struct Deque *q);
void push_front(struct Deque *q, struct Node *n);
void push_rear(struct Deque *q, struct Node *n);
struct Node *pop_front(struct Deque *q);
struct Node *pop_rear(struct Deque *q);
bool is_empty(struct Deque *q);

#endif
