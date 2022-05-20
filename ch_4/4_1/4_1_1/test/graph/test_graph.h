#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H
#include "../../src/graph/graph.h"
struct Graph *init_graph();
void print_graph(struct Graph *g);
void print_node_rels(struct Node *n);
void test_graph(struct Graph *g);
struct Graph *init_graph();

#endif
