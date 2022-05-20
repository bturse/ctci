#include "test_deque.h"
#include "../../src/graph/graph.h"
#include "../../src/deque/deque.h"
#include <stdio.h>

void print_deque(struct Deque *q);
void print_q_members(struct Deque *q);
void test_switch(struct Deque *q, struct Graph *g, int case_n);
void stress_test(struct Deque *q, struct Graph *g, int n);
void test_deque();

void print_deque(struct Deque *q)
{
	printf("%s\n", __func__);
	for (int i = 0; i < q->cap; i++) {
		if (q->nodes[i] == NULL) 
			printf("_");
		else
			printf("%d", q->nodes[i]->data);

	}
	puts("");
}

void print_q_members(struct Deque *q)
{
	printf("q->front: %d\n", q->front);
	printf("q->rear: %d\n", q->rear);
	printf("q->cap: %d\n", q->cap);
	printf("q->used: %d\n", q->used);
}

void test_switch(struct Deque *q, struct Graph *g, int case_n)
{
	struct Node *n;
	switch(case_n) {
		case 0: 
			puts("push_front");
			n = make_node(2, 1, g);
			push_front(q, n);
			print_q_members(q);
			print_deque(q);
			break;
		case 1: 
			puts("push_rear");
			n = make_node(2, 2, g);
			push_rear(q, n);
			print_q_members(q);
			print_deque(q);
			break;
		case 2: 
			puts("pop_front");
			n = pop_front(q);
			print_q_members(q);
			print_deque(q);
			break;
		case 3: 
			puts("pop_rear");
			n = pop_rear(q);
			print_q_members(q);
			print_deque(q);
			break;
		default: printf("default reached");
			 exit(1);
	}
}

void stress_test(struct Deque *q, struct Graph *g, int n)
{
	for(int i = 0; i < n; i++) {
		int rn = rand() % 4;
		test_switch(q, g, rn);
	}
}

void test_deque()
{
	struct Graph *g = make_graph(5);
	struct Deque *q = make_deque(2);
	stress_test(q, g, 50);
	free_deque(q);
	free_graph(g);
}
