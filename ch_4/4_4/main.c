#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
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

void free_node(struct Node *node)
{
	node->data = 0;
	node->left = node->right = NULL;
	free(node);
}

int get_max(int a, int b)
{
	return a > b ? a : b;
}

int get_height(struct Node *root, bool *is_bal)
{
	if (!root) return 0;
	if (*is_bal) {
		int left = get_height(root->left, is_bal) + 1;
		int right = get_height(root->right, is_bal) + 1;

		if (abs(right - left) > 1)
			*is_bal = false;

		return get_max(left, right);
	} else {
		return 0;
	}
}

bool is_bal(struct Node *root)
{
	bool is_bal = true;
	get_height(root, &is_bal);
	return is_bal;
}

int main(int argc, char *argv[]) {
	
	struct Node *n0 = make_node(0);
	struct Node *n1 = make_node(1);
	struct Node *n2 = make_node(2);
	struct Node *n3 = make_node(3);
	struct Node *n4 = make_node(4);
	struct Node *n5 = make_node(5);
	struct Node *n6 = make_node(6);
	n0->left = n1;
	n1->left = n2;
	n2->left = n3;
	printf("is_bal: %d", is_bal(n0));
	return 0;
}


