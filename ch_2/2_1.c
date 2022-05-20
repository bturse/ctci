#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
        size_t val;
        struct Node *last;
        struct Node *next;
};

struct LinkedList {
        size_t size;
        struct Node *list;
};

struct Node *make_node(size_t v)
{
        struct Node *new_node = malloc(sizeof(struct Node));
        if(! new_node)
                exit(1);
        new_node->val = v;
        new_node->next = NULL;
        return new_node;
}

struct LinkedList *make_linked_list()
{
        struct LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
        if (!new_linked_list)
                exit(1);
        new_linked_list->list = NULL;
        return new_linked_list;
}

void push(struct LinkedList *l, struct Node *n)
{
        n->next = l->list;
        n->last = NULL;
        if (n->next)
                n->next->last = n;
        l->list = n;
        l->size++;
}

void delete_node(struct Node *n)
{
        n->last->next = n->next;
        free(n);
}

void print_list(struct LinkedList *l)
{
        struct Node *current_node = l->list;
        while (current_node->next) {
                printf("%zu->", current_node->val);
                current_node = current_node->next;
        }
        printf("_");
}

void dedupe_list(struct LinkedList *l)
{
        int ht_int[100] = { 0 };
        struct Node *current_node = l->list;
        while (current_node->next) {
                int val_ct = ht_int[current_node->val]++;
                if (val_ct > 0)
                        delete_node(current_node);
                current_node = current_node->next;
        }
}

int main() {
        struct LinkedList *list = make_linked_list();
        for (int i = 0; i < 5; i++) {
                struct Node *node = make_node(i);
                push(list, node);
        }
        struct Node *node = make_node(3);
        push(list, node);
        print_list(list);
        dedupe_list(list);
        puts("");
        print_list(list);
}
