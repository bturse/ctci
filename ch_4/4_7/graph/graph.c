#include "graph.h"
#include <stdlib.h>

struct Node *make_node(int data, size_t init_cap, struct Graph *graph)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->nodes = malloc(sizeof *n->nodes * (n->cap = init_cap));
	if (!n->nodes) exit(1);
	n->used = 0;
	n->data = data;
	rel_ntog(n, graph);
	n->visited = n->in_path = false;
	return n;
}

void free_node(struct Node *node)
{
	free(node->nodes);
	free(node);
}

struct Graph *make_graph(size_t init_cap)
{
	struct Graph *g = malloc(sizeof *g);
	if (!g) exit(1);
	g->nodes = malloc(sizeof *g->nodes * (g->cap = init_cap));
	if (!g->nodes) exit(1);
	g->used = 0;
	g->is_cyclic = false;
	return g;
}

void free_graph(struct Graph *graph)
{
	free(graph->nodes);
	free(graph);
}

void rel_ntog(struct Node *node, struct Graph *graph)
{
	if (graph->used >= graph->cap) {
		graph->cap *= 2;
		struct Node **temp = realloc(graph->nodes, sizeof *temp * graph->cap);
		if (!temp) exit(1);
		graph->nodes = temp;
	}
	graph->nodes[graph->used++] = node;
}

void print_node(struct Node *node)
{
	for (int i = 0; i < node->used; i++)
		printf("%d%s", node->nodes[i]->data, i == node->used - 1 ? "" : ", ");
}

void print_graph(struct Graph *graph)
{
	for (int i = 0; i < graph->used; i++) {
		printf("%d%s", graph->nodes[i]->data, i < graph->used - 1 ? ", " : "");
	}

}

void rel_nton(struct Node *l_node, struct Node *r_node)
{
	if (l_node->used >= l_node->cap) {
		l_node->cap *= 2;
		struct Node **temp = realloc(l_node->nodes, sizeof *temp * l_node->cap);
		if (!temp) exit(1);
		l_node->nodes = temp;
	}
	l_node->nodes[l_node->used++] = r_node;
}

bool is_graph_asc(struct Graph *graph)
{
	for (int i = 0; i < graph->used - 1; i++) {
		if (&graph->nodes[i] > &graph->nodes[i + 1])
			return false;
	}
	return true;
}

