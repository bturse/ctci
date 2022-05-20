#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define COUNT 5

struct Array {
	int *array;
	size_t cap, front, rear, rear2;
};

struct Node {
	int data;
	struct Node *left, *right;
};

struct Array *make_array(int *array, size_t init_cap)
{
	struct Array *a = malloc(sizeof *a * init_cap);
	if (!a) exit(1);
	a->array = array;
	a->front = 0; 
	a->rear = a->rear2 = init_cap - 1;
	a->cap = init_cap;
	return a;
}

struct Node *make_node(int data)
{
	struct Node *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int get_median(int low, int high)
{
	return (int)ceil(((double)high + (double)low) / 2);
}

struct Node *make_bin_tree(int *array, int start, int end)
{
	if (start > end) return NULL;
	int mid = get_median(start, end);
	struct Node *n = make_node(array[mid]);
	n->left = make_bin_tree(array, start, mid - 1);
	n->right = make_bin_tree(array, mid + 1, end);
	return n;
}

void print_bst(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print_bst(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print_bst(root->left, space);
}


void in_order(struct Node *n)
{
	if (!n) return;
	in_order(n->left);
	printf("%d\n", n->data);
	in_order(n->right);
}

int main(int argc, char *argv[])
{
	int array[8] = {0,1,2,3,4,5,6,7};
	size_t arr_size = sizeof array / sizeof array[0];
	struct Node *root = make_bin_tree(array, 0, arr_size - 1);
//	in_order(root);
	print_bst(root, 4);
	return 0;
}
