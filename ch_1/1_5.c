#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node {
        char c;
        struct Node *next;
};

struct LinkedList {
        struct Node *head;
        size_t length;
};

struct Node *make_node(char c)
{
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->c = c;
        new_node->next = NULL;
        return new_node;
}

struct LinkedList *make_list()
{
        struct LinkedList *new_list = malloc(sizeof(struct LinkedList));
        if (!new_list)
                exit(1);
        new_list->head = NULL;
        return new_list;
}

void push(char c, struct LinkedList *list) 
{
        struct Node *new_node = make_node(c);
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
}

struct LinkedList *str_to_list(char str[])
{
        struct LinkedList *list = make_list();
        for (int i = strlen(str); i >= 0; i--)
                push(str[i], list);
        return list;
}

void print_list(struct Node *head)
{
        struct Node *cur_node = head;
        while (cur_node->next) {
                printf("%c", cur_node->c);
                cur_node = cur_node->next;
        }
}

bool is_one_away(char *str1, char *str2)
{
        if (abs(strlen(str1) - strlen(str2)) > 1)
                return false;

        int dif_ct = 0;
        struct LinkedList *list1 = str_to_list(str1);
        struct LinkedList *list2 = str_to_list(str2);
        struct Node *long_list  = list1->length >= list2->length ? list1->head : list2->head;
        struct Node *short_list = long_list == list1->head ? list2->head : list1->head;

        while (short_list->next) {
                if (long_list->c == short_list->c) {
                        long_list = long_list->next;
                        short_list = short_list->next;
                } else if (long_list->next->c == short_list->c) {
                        long_list = long_list->next;
                        dif_ct++;
                } else 
                        return false;
        }

        printf("final dif_ct: %d\n", dif_ct);
        return true;
}

int main() {
        char *str1 = "be";
        char *str2 = "ba";
        if (is_one_away(str1, str2))
                puts("one away");
        else
                puts("not one away");
        return 0;
}
