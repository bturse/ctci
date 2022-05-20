#include "test_bfs.h"
#include "../graph/test_graph.h"
#include "../../src/bfs/bfs.h"
#include <stdio.h>

void test_bfs()
{
	int i;
	struct Node *n, *target;
	struct Graph *g = make_graph(5);
	for (i = 0; i < 10; i++)
		make_node(1, i, g);
	for (i = 1; i < 9; i++)
		append_node(g->nodes[i - 1], g->nodes[i]);
	print_graph(g);
	n = g->nodes[0];
	target = g->nodes[9];
	printf("nodes are: %s\n", 
			bfs(n, target) ? "connected" : "not connected");

}
