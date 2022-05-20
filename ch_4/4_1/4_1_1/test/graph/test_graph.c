#include "test_graph.h"
#include "../../src/graph/graph.h"
#include <stdio.h>

void print_node_rels(struct Node *n)
{
	printf("n->data: %d\n", n->data);
	printf("\trels: (");
	for (int i = 0; i < n->used; i++) {
		struct Node *r = n->nodes[i];
		printf("%d%c", r->data, i < n->used - 1 ? ',' : '\0');
	}
	printf(")\n");
}

void print_graph(struct Graph *g)
{
	printf("%s\n", __func__);
	for (int i = 0; i < g->used; i++)
		print_node_rels(g->nodes[i]);
}

struct Graph *init_graph()
{
	printf("%s\n", __func__);
	struct Graph *g = make_graph(1);
	struct Node *l = make_node(1, 1, g);
	struct Node *r;
	for (int i = 0; i < 5; i++) {
		r = make_node(1, i, g);
		append_node(l, r);
	}
	return g;
}

void test_graph(struct Graph *g)
{
	printf("%s\n", __func__);
	print_graph(g);
	free_graph(g);
}
