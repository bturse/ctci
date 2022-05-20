#include "bfs.h"
#include "../deque/deque.h"
#include <stdbool.h>
#include <stdio.h>


bool bfs(struct Node *node, struct Node *target)
{
	struct Node *n1, *n2;
	struct Deque *q = make_deque(node->graph->used / 2);
	node->marked = true;
	push_rear(q, node);
	while (!is_empty(q)) {
		n1 = pop_front(q);
		if (n1 == taget) {
			free_deque(q);
			return true;
		}
		for (int i = 0; i < n1->used; i++) {
			n2 = n1->nodes[i];
			if (!n2->marked) {
				n2->marked = true;
				push_rear(q, n2;)
			}
		}
	}
	free_deque(q);
	return false;
}

//bool bfs(struct Node *node, struct Node *target)
//{
//	struct Node *n1, *n2;
//	struct Deque *q = make_deque(node->graph->used / 2);
//	node->marked = true;
//	push_rear(q, node);
//	while (!is_empty(q)) {
//		n1 = pop_front(q);
//		if (n1 == target) {
//			free_deque(q);
//			return true;
//		}
//		for (int i = 0; i < n1->used; i++) {
//			n2 = n1->nodes[i];
//			if (!n2->marked) {
//				n2->marked = true;
//				push_rear(q, n2);
//			}
//		}
//	}
//	free_deque(q);
//	return false;
//}

