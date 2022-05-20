#include <stdio.h>
#include <stdlib.h>

struct Node {
        size_t value;
        struct Node *next;
};

struct LinkedList {
        struct Node *head;
};

struct Node *make_node(size_t v)
{
        struct Node *new_node = malloc(sizeof(struct Node));
        if (!new_node)
                exit(1);
        new_node->value = v;
        new_node->next = NULL;
        return new_node;
}

struct LinkedList *make_linked_list()
{
        struct LinkedList *new_linked_list = malloc(sizeof(struct LinkedList));
        if (!new_linked_list)
                exit(1);
        new_linked_list->head = NULL;
        return new_linked_list;
}

void push(struct LinkedList *list, struct Node *new_node)
{
        new_node->next = list->head;
        list->head = new_node;
}

int lton(struct LinkedList *l)
{
        size_t base = 1;
        size_t n = 0;
        struct Node *current_node = l->head;
        while (current_node) {
                n += current_node->value * base;
                base *= 10;
                current_node = current_node->next;
        }
        return n;
}

size_t add_linked_lists(struct LinkedList *l1, struct LinkedList *l2)
{
        size_t operand_1 = lton(l1);
        size_t operand_2 = lton(l2);
        return operand_1 + operand_2;

}

void print_linked_list(struct LinkedList *l)
{
        struct Node *current_node = l->head;
        while (current_node) {
                printf("%zu->", current_node->value);
                current_node = current_node->next;
        }
        puts("");
}

int main() {
        
        struct LinkedList *l1 = make_linked_list();
        size_t n;
        push(l1, make_node(6));
        push(l1, make_node(1));
        push(l1, make_node(7));
        printf("l1: ");
        print_linked_list(l1);
        n = lton(l1);
        printf("n: %zu", n);
        puts("");
        
        struct LinkedList *l2 = make_linked_list();
        push(l2, make_node(2));
        push(l2, make_node(9));
        push(l2, make_node(5));
        printf("l2: ");
        print_linked_list(l2);
        n = lton(l2);
        printf("n: %zu", n);
        puts("");

        printf("sum: %zu", add_linked_lists(l1, l2));

        return 0;
}
