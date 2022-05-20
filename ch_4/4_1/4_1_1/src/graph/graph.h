#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdbool.h>
struct Node {
	int data;
	struct Graph *graph;
	struct Node **nodes;
	size_t cap, used;
	bool marked;
};

struct Graph {
	struct Node **nodes;
	size_t cap, used;
};

struct Node *make_node(size_t init_cap, int data, struct Graph *g);
struct Graph *make_graph(size_t init_cap);
void free_node(struct Node *n);
void free_graph(struct Graph *g);
void append_node(struct Node *lnode, struct Node *rnode);
void print_nodes_n(struct Node *n);
void print_nodes_g(struct Graph *g);
void print_graph(struct Graph *g);

#endif
