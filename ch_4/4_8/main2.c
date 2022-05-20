#include <stdlib.h>
#include <stdio.h> 
struct Node {
	int data;
	size_t level;
	struct Node *left, *right, *parent;
};

struct Node *make_node(int data)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->data = data;
	n->left = n->right = NULL;
	n->parent = NULL;
	n->level = 0;
	return n;
}

void set_level_parent(struct Node *root)
{
	if (root->left) {
		root->left->parent = root;
		root->left->level = root->level + 1;
	}
	if (root->right) {
		root->right->parent = root;
		root->right->level = root->level + 1;
	}
}

struct Node *get_lca(struct Node *n1, struct Node *n2)
{
	struct Node *above = n1->level < n2->level ? n1 : n2;
	struct Node *below = n1->level < n2->level ? n2 : n1;
	size_t delta = below->level - above->level;
	while (delta) {
		below = below->parent;
		delta--;
	}
	while (above != below) {
		above = above->parent;
		below = below->parent;
	}
	return above;
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
	
	for (int j = 0; j < 8; j++)
		set_level_parent(graph[j]);

	struct Node *lca = get_lca(graph[7], graph[5]);
	printf("%d\n", lca->data);

	return 0;
}

