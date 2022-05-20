#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
	int val;
	struct TreeNode *left, *right;
};

struct TreeNode *make_node(int data)
{
	struct TreeNode *n = malloc(sizeof *n);
	if (!n) exit(1);
	n->val = data;
	n->left = n->right = NULL;
	return n;
}

void in_order(struct TreeNode *node, int **temp, bool *is_bst)
{
	if (!node) return;
	if (*is_bst) {
		in_order(node->left, temp, is_bst);
		if (!(*temp) || node->val > **temp)
			*temp = &node->val;
		else 
			*is_bst = false;
		in_order(node->right, temp, is_bst);
	}
}

bool isValidBST(struct TreeNode* root){
	int *temp = NULL;
	bool is_bst = true;
	int prev = root->val;
	in_order(root, &temp, &is_bst);
	return is_bst;
}

int main() {
	struct TreeNode *n1  = make_node(-2147483648);
	struct TreeNode *n2  = make_node(2147483647);
	n1->right = n1;
	printf("%d\n", isValidBST(n1));
	return 0;
}
