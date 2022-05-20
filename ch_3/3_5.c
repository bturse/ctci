#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Array {
        size_t size;
        size_t used;
        int *array;
};

struct Array *make_array(size_t init_size)
{
        struct Array *new_array = malloc(sizeof(struct Array));
        if(! new_array)
                exit(1);
        new_array->array = malloc(sizeof(new_array->array) * init_size);
        if(! new_array->array)
                exit(1);
        new_array->size = init_size;
        new_array->used = 0;
        return new_array;
}

void free_array(struct Array *a)
{
        for (size_t i = 0; i < a->used; i++)
                a->array[i] = 0;
        free(a->array);
        a->size = 0;
        a->used = 0;
        free(a);
}

void push(int i, struct Array *a)
{
        if (a->used >= a->size) {
                a->size *= 2;
                a->array = realloc(a->array, sizeof(a->array) * a->size);
        }
        a->array[a->used++] = i;
}

int peek(struct Array *a)
{
        return a->array[a->used - 1];
}

int *pop(struct Array *a)
{
        return &a->array[--a->used];
}


void sort_stack(struct Array *a)
{
        int *current_i = NULL;
        int *temp_i = NULL;

        struct Array *lesser_stack = make_array(a->used);
        bool sorted;
        
        do {
                sorted = true;
                while (a->used > 0) {
                        if (current_i == NULL)
                                current_i = pop(a);
                        if (*current_i >= peek(a)) {
                                push(*pop(a), lesser_stack);
                        } else {
                                temp_i = pop(a);
                                push(*current_i, lesser_stack);
                                current_i = temp_i; temp_i = NULL;
                        }
                }
                push(*current_i, a); 
                current_i = NULL;
                while (lesser_stack->used > 0) {
                        if (! current_i)
                                current_i = pop(lesser_stack);
                        if (*current_i < peek(lesser_stack)) {
                                temp_i = pop(lesser_stack);
                                if (*temp_i < peek(a))
                                        sorted = false;
                                push(*temp_i, a);
                                temp_i = NULL;
                        } else {
                                push(*current_i, a);
                                current_i = pop(lesser_stack);
                        }
                }
                        if (*current_i <= peek(a))
                                push(*current_i, a);
                        else
                                push(*current_i, lesser_stack);
                        current_i = NULL;
        } while (!sorted && !lesser_stack->used);
        free_array(lesser_stack);
}


int main() {
        struct Array *a = make_array(3);
        push(1, a);
        push(2, a);
        push(5, a);
        push(2, a);
        push(4, a);
        puts("a before sorting: ");
        for (int i = 0; i < a->used; ++i)
                printf("i: %d\t%d\n", i, a->array[i]);
        puts("sorting");
        sort_stack(a);
        puts("a after sorting: ");
        for (int i = 0; i < a->used; ++i)
                printf("i: %d\t%d\n", i, a->array[i]);
        free_array(a);
        return 0;
}
