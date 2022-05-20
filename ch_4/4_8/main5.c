#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *make_node(int data)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

struct Node *get_lca(struct Node *root, struct Node *n1, struct Node *n2)
{
	
}

int main() {
	struct Node **graph;
	for (int i = 0; i < 8; i++)
		graph[i] = make_node(i);

	graph[0]->left = graph[1];
	graph[0]->right = graph[2];
	graph[1]->left = graph[3];
	graph[2]->left = graph[4];
	graph[4]->left = graph[5];
	graph[4]->right = graph[6];
	graph[5]->left = graph[7];
	
	struct Node *lca = get_lca(graph[0], graph[6], graph[7]);
	printf("%d\n", lca->data);
	return 0;
}

