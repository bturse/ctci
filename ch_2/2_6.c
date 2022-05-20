#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
        size_t value;
        struct Node *next;
        struct Node *prev;
};

struct LinkedList {
        struct Node *head;
        struct Node *tail;
        size_t length;
};

struct Node *make_node(size_t v)
{
        struct Node *new_node = malloc(sizeof(struct Node));
        if(!new_node)
                exit(1);
        new_node->value = v;
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
}

struct LinkedList *make_linked_list()
{
        struct LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
        if(!new_linked_list)
                exit(1);
        new_linked_list->head = NULL;
        new_linked_list->tail = NULL;
        new_linked_list->length = 0;
        return new_linked_list;
}

void push(struct LinkedList *l, struct Node *n)
{
        if (l->head)
                l->head->prev = n;
        else
                l->tail = n;
        n->next = l->head;
        l->head = n;
        l->length++;
}

void print_linked_list_fw(struct LinkedList *l)
{
        struct Node *current_node = l->head;
        while (current_node) {
                printf("%zu->", current_node->value);
                current_node = current_node->next;
        }
        puts("");
}

void print_linked_list_bw(struct LinkedList *l)
{
        struct Node *current_node = l->tail;
        while (current_node) {
                printf("%zu->", current_node->value);
                current_node = current_node->prev;
        }
        puts("");
}

void print_linked_list(struct LinkedList *l, bool reverse)
{
        if (reverse)
                print_linked_list_bw(l);
        else
                print_linked_list_fw(l);
}

bool is_palindrome(struct LinkedList *l)
{
        size_t steps = 0;
        struct Node *current_head = l->head;
        struct Node *current_tail = l->tail;
        while (steps < l->length / 2) {
                if (current_head->value != current_tail->value)
                        return false;
                current_head = current_head->next;
                current_tail = current_tail->prev;
                steps++;
        }
        return true;
}

int main() {
        
        struct LinkedList *l = make_linked_list();
        struct Node *n;

        n = make_node(5);
        push(l, n);
        n = make_node(5);
        push(l, n);

        print_linked_list(l, false);
        printf(is_palindrome(l) ? "is a palindrome" : "is not a palindrome");

        return 0;
}
