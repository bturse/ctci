#include "is_cyc.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//https://stackoverflow.com/a/27552637
void visit(struct Graph *graph, struct Node *node)
{
	if (node->in_path) {
		graph->is_cyclic = true;
		return;
	} else {
		node->in_path = true;
	}
	for (size_t i = 0; i < node->used; i++) {
		visit(graph, node->nodes[i]);
	}
	node->visited = true;
	node->in_path = false;
}

bool is_cyc(struct Graph *graph)
{
	for (size_t i = 0; i < graph->used; i++)
		visit(graph, graph->nodes[i]);
	return graph->is_cyclic;
}

int main() {
	struct Graph *graph = make_graph(5);
	for (int i = 0; i < 10; i++)
		make_node(i, 1, graph);
	rel_nton(graph->nodes[9], graph->nodes[9]);
//	rel_nton(graph->nodes[1], graph->nodes[2]);
//	rel_nton(graph->nodes[2], graph->nodes[3]);
	printf("is_cyc: %d\n", is_cyc(graph));
	return 0;
}

