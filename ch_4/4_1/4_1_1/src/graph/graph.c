#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void add_n_to_g(struct Node *n, struct Graph *g)
{
	if (g->used >= g->cap) {
		struct Node **temp = realloc(g->nodes, sizeof (*temp) * g->cap * 2);
		if (!temp) exit(1);
		g->nodes = temp;
		g->cap *= 2;
	}
	g->nodes[g->used++] = n;
}

struct Node *make_node(size_t init_cap, int data, struct Graph *g)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->nodes = malloc(sizeof *n->nodes * (n->cap = init_cap));
	if (!n->nodes) exit(1);
	n->used = 0;
	n->graph = g;
	n->data = data;
	add_n_to_g(n, g);
	n->marked = false;
	return n;
}

struct Graph *make_graph(size_t init_cap)
{
	struct Graph *g = malloc(sizeof *g);
	if (!g) exit(1);
	g->nodes = malloc(sizeof g->nodes * (g->cap = init_cap));
	if (!g->nodes) exit(1);
	g->used = 0;
	return g;
}

void free_node(struct Node *n)
{
	n->data = 0;
	n->cap = n->used = 0;
	n->graph->used--;
	n->graph = NULL;
	free(n);
}

void free_graph(struct Graph *g)
{
	size_t temp = g->used;
	for (size_t i = 0; i < temp; i++)
		free_node(g->nodes[i]);
	g->cap = g->used = 0;
	free(g);
}

void append_node(struct Node *lnode, struct Node *rnode)
{
	if (lnode->cap >= lnode->used) {
		struct Node **temp = realloc(lnode->nodes, sizeof (*temp) * lnode->cap * 2);
		if (!temp) exit(1);
		lnode->cap *= 2;
		lnode->nodes = temp;
	}
	lnode->nodes[lnode->used++] = rnode;
}

void print_nodes_n(struct Node *n)
{
	for (int i = 0; i < n->used; i++)
		printf("%d, ", n->nodes[i]->data);
}

void print_nodes_g(struct Graph *g)
{
	for (size_t i = 0; i < g->used; i++)
		printf("%d, ", g->nodes[i]->data);
}

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

