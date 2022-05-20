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

bool covers(struct Node *n1, struct Node *n2)
{
	if (n1 == NULL) return false;
	if (n1 == n2) return true;
	return covers(n1->left, n2) || covers(n1->right, n2);
}

struct Node *get_lca(struct Node *root, struct Node *n1, struct Node *n2)
{
	if (!covers(root, n1) || !covers(root, n2)) return NULL;
	if (root == NULL || root == n1 || root == n2) return root;
	bool n1_on_l = covers(root->left, n1);
	bool n2_on_l = covers(root->left, n2);
	if (n1_on_l != n2_on_l) return root;
	struct Node *child_path = n1_on_l ? root->left : root->right;
	return get_lca(child_path, n1, n2);
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

