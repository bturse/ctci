#include "main.h"
#include <stdlib.h>
#include <stdio.h>

struct Node *make_node(int n)
{
	struct Node *new_node = malloc(sizeof *new_node);
	if (!new_node) exit(1);
	new_node->data = n;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void free_node(struct Node *n)
{
	n->data = 0;
	n->left = n->right = NULL;
	free(n);
}

struct List *make_list()
{
	struct List *l = malloc(sizeof *l);
	if (!l) exit(1);
	l->head = l->tail = NULL;
	return l;
}

void free_list(struct List *l)
{
	l->head = l->tail = NULL;
	free(l);
}

struct Array *make_array(int init_cap)
{
	struct Array *a = malloc(sizeof *a);
	if (!a) exit(1);
	a->array = malloc(sizeof a->array * (a->cap = init_cap));
	if (!a->array) exit(1);
	a->used = 0;
	return a;
}

void free_array(struct Array *a)
{
	for (int i = 0; i < a->cap; i++)
		free_list(a->array[i]);
	free(a);
}

struct Array *expand_array(struct Array *a)
{
	int old_cap = a->cap;
	a->cap = 2 * a->used;
	struct List **temp = realloc(*a->array, sizeof *temp * a->cap);
	if (!temp) exit(1);
	a->array = temp;
	return a;
}

void tree_to_array(struct Node *tree, int depth, struct Array *a)
{
	if (tree == NULL) return;
	tree_to_array(tree->left, ++depth, a);
	tree_to_array(tree->right, depth, a);
	depth--;
	visit(tree, depth, a);
}

void visit(struct Node *node, int depth, struct Array *a)
{
	if (depth >= a->used)
		a->used = depth + 1;
	if (a->used >= a->cap)
		expand_array(a);
	struct List **l = &a->array[depth];
	if(!(*l)) {
		*l = make_list();
		(*l)->head = (*l)->tail = node;
		(*l)->tail->right = NULL;
	} else {
		(*l)->tail->right = node; 
		(*l)->tail = node;
	}
}

void print_list(struct List *l)
{
	struct Node *n = l->head;
	while (n) {
		printf("%d->", n->data);
		n = n->right;
	}
}

void print_array(struct Array *a)
{
	printf("[");
	for (int i = 0; i < a->used; i++) {
		print_list(a->array[i]);
		if (i != a->used - 1) 
			printf(", ");
	}
	printf("]");
}

int main() {
	struct Array *a = make_array(1);
	struct Node *n0 = make_node(0);
	struct Node *n1 = make_node(1);
	struct Node *n2 = make_node(2);
	struct Node *n3 = make_node(3);
	n0->left = n1;
	n0->right = n2;
	n1->left = n3;
	tree_to_array(n0, 0, a);
	print_array(a);
	return 0;
}
