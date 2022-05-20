#include <stdio.h>
#include <stdlib.h>

struct Node {
        int val;
        struct Node *next;
};

struct LinkedList {
        struct Node *head;
        struct Node *tail;
        size_t length;
};

struct Node *make_node(int v)
{
        struct Node *new_node = malloc(sizeof(struct Node));
        if (!new_node)
                exit(1);
        new_node->val = v;
        return new_node;
}

struct LinkedList *make_linked_list()
{
        struct LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
        if (!new_linked_list)
                exit(1);
        new_linked_list->length = 0;
        new_linked_list->head = NULL;
        new_linked_list->tail = NULL;
        return new_linked_list;
}

void free_node(struct Node *n)
{
        n = NULL;
        free(n);
}

void free_linked_list(struct LinkedList *l)
{
        struct Node *temp;
        while (l->head) {
                temp = l->head;
                l->head = l->head->next;
                free_node(temp);
        }
        l->head = NULL;
        l->tail = NULL;
        l->length = 0;
        free(l);
}

void push(struct LinkedList *l, struct Node *n)
{
        if (!l->head)
                l->tail = n;
        n->next = l->head;
        l->head = n;
        l->length++;
}

void print_list(struct LinkedList *l)
{
        struct Node *current_node = l->head;
        while(current_node) {
                printf("%d->", current_node->val);
                current_node = current_node->next;
        }
        puts("");
}

void partition_list(struct LinkedList *l, int n)
{
        struct LinkedList *partitioned_list = make_linked_list();
        struct LinkedList *less_list = make_linked_list();
        struct LinkedList *more_list = make_linked_list();
        struct LinkedList *same_list = make_linked_list();
        struct Node *current_node = l->head;
        while (current_node) {
                struct Node *temp_next = current_node->next;
                if (current_node->val < n) {
                        push(less_list, current_node);
                } else if (current_node->val > n) {
                        push(more_list, current_node);
                } else {
                        push(same_list, current_node);
                }
                current_node = temp_next;
        }
        if (more_list->head)
                l->head = more_list->head;
        else if (same_list->head)
                l->head = same_list->head;
        else if (less_list->head)
                l->head = less_list->head;

        if (more_list->head && same_list->head)
                more_list->tail->next = same_list->head;
        if (same_list->head && less_list->head)
                same_list->tail->next = less_list->head;
        if (!same_list->head && more_list->head && less_list->head)
                more_list->tail->next = less_list->head;

        l->length = less_list->length + same_list->length + more_list->length; 
        free_linked_list(less_list);
        free_linked_list(same_list);
        free_linked_list(more_list);
}


int main() {
        int part_i = 2;
        struct LinkedList *list = make_linked_list();
        for (int i = 0; i < 3; i++) {
                struct Node *new_node = make_node(i);
                push(list, new_node);
        }
        for (int i = 1; i < 4; i++) {
                struct Node *new_node = make_node(i);
                push(list, new_node);
        }
        printf("partition by: %d\n", part_i);
        printf("before partition: ");
        print_list(list);
        partition_list(list, part_i);

        printf("after partition:  ");
        print_list(list);
        return 0;
}
