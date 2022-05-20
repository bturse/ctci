#include "test_graph.h"

int main(int argc, char *argv[]) {
	struct Graph *g = init_graph();
	test_graph(g);
	return 0;
}
