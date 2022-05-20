#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *left, *right, *parent;
};

struct Node *make_node(int data)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->data = data;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void set_parent(struct Node *root)
{
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
}

bool covers(struct Node *n1, struct Node *n2)
{
	if (n1 == NULL) return false;
	if (n1 == n2) return true;
	return covers(n1->left, n2) || covers(n1->right, n2);
}

struct Node *get_sibling(struct Node *node)
{
	if (!node->parent || !node) return NULL;
	return node->parent->left = node ? node->parent->right : node->parent->left;
}

struct Node *get_lca(struct Node *root, struct Node *n1, struct Node *n2)
{
	if (!covers(root, n1) || !covers(root, n2)) return NULL;
	if (covers(n1, n2)) return n1;
	if (covers(n2, n1)) return n2;
	struct Node *sibling = get_sibling(n1);
	struct Node *parent = n1->parent;
	while (!covers(sibling, n2)) {
		sibling = get_sibling(parent);
		parent = parent->parent;
	}
	return parent;
}

//bool covers(struct Node *root, struct Node *node)
//{
//	if (root == node) return true;
//	if (root == NULL) return false;
//	return covers(root->left, node) || covers(root->right, node);
//}
//
//struct Node *get_sibling(struct Node *node)
//{
//	if (!node->parent || !node) return NULL;
//	return node->parent->left == node ? node->parent->right : node->parent->left;
//}
//
//struct Node *get_lca(struct Node *root, struct Node *n1, struct Node *n2)
//{
//	if (!covers(root, n1) || !covers(root, n2)) return NULL;
//	if (covers(n1, n2)) return n1;
//	if (covers(n2, n1)) return n2;
//	struct Node *sibling = get_sibling(n1);
//	struct Node *parent = n1->parent;
//	while (!covers(sibling, n2)) {
//		sibling = get_sibling(parent);
//		parent = parent->parent;
//	}
//	return parent;
//}

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
		set_parent(graph[j]);

	struct Node *lca = get_lca(graph[0], graph[7], graph[6]);
	printf("%d\n", lca->data);
	return 0;
}


