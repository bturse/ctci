#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdbool.h>

struct Node {
	int data;
	size_t cap, used;
	struct Node **nodes;
	bool visited, in_path;
};

struct Graph {
	struct Node **nodes;
	bool is_cyclic;
	size_t cap, used;
};

struct Node *make_node(int data, size_t init_cap, struct Graph *graph);
void free_node(struct Node *node);
struct Graph *make_graph(size_t init_cap);
void free_graph(struct Graph *graph);
void rel_nton(struct Node *l_node, struct Node *r_node);
void rel_ntog(struct Node *node, struct Graph *graph);
void print_graph(struct Graph *graph);
void print_node(struct Node *node);

#endif

