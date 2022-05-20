struct Node {
	int data;
	struct Node *left, *right;
};

struct List {
	struct Node *head, *tail;
};

struct Array {
	struct List **array;
	int cap, used;
};

struct Node *make_node(int n);
struct List *make_list();
struct Array *make_array(int init_cap);
void free_node(struct Node *n);
void free_list(struct List *l);
void free_array(struct Array *a);

void append_nl(struct Node *n, struct List *l, int depth);
void tree_to_array(struct Node *tree, int depth, struct Array *a);
void visit(struct Node *tree, int depth, struct Array *a);


