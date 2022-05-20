#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *make_node(int data)
{
	struct Node *node = malloc(sizeof *node);
	if (!node) exit(1);
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void print_array(struct Node *node, int ltor_order)
{
	if (!node) return;
	printf("%d", node->data);
	if (ltor_order) {
		print_array(node->left, 0);
		print_array(node->right, 1);
	} else {
		print_array(node->right, 0);
		print_array(node->left, 1);
	}
}


int main() {
	struct Node **graph;
	for (int i = 0; i < 9; i++)
		graph[i] = make_node(i);

	graph[5]->left = graph[3];
	graph[5]->right = graph[7];
	graph[3]->left = graph[2];
	graph[3]->right = graph[4];
	graph[2]->left = graph[1];
	graph[7]->left = graph[6];
	graph[7]->right = graph[8];
	for (int lr_ord = 0; lr_ord < 2; lr_ord++) {
		print_array(graph[5], lr_ord);
		puts("");
	}
	return 0;
}
