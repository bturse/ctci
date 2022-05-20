#include <stdio.h>
#include <stdlib.h>

size_t MAX_STACK = 10; // largest possible inner stack

struct OuterArray {
        size_t size;
        size_t used;
        struct InnerArray **array;
};

struct InnerArray {
        size_t size;
        size_t used;
        char *array;
};

struct OuterArray *make_outer_array(size_t init_size)
{
        struct OuterArray *new_outer_array = malloc(sizeof(struct OuterArray));
        if (! new_outer_array)
                exit(1);
        new_outer_array->array = malloc(sizeof(*new_outer_array->array) * init_size);
        if (! new_outer_array->array)
                exit(1);
        new_outer_array->size = init_size;
        new_outer_array->used = 0;
        return new_outer_array;
}

struct InnerArray *make_inner_array(size_t init_size)
{
        struct InnerArray *new_inner_array = malloc(sizeof(struct InnerArray));
        if (! new_inner_array)
                exit(1);
        new_inner_array->array = malloc(sizeof(*new_inner_array->array) * init_size);
        if (! new_inner_array->array)
                exit(1);
        new_inner_array->size = init_size;
        new_inner_array->used = 0;
        return new_inner_array;
}

void push_inner_array(char c, struct InnerArray *ia)
{
        struct InnerArray a = *ia;
        if (ia->used >= ia->size) {
                ia->size *= 2;
                ia->array = realloc(ia->array, sizeof(ia->array) * ia->size);
        }
        ia->array[ia->used++] = c;
}

void push_outer_array(struct InnerArray *ia, struct OuterArray *oa)
{
        if (oa->used >= oa->size) {
                oa->size *= 2;
                oa->array = realloc(oa->array, sizeof(*oa->array) * oa->size);
        }
        oa->array[oa->used++] = ia;
}

struct InnerArray *peek_outer_array(struct OuterArray *oa)
{        
        if (oa->used == 0)
                return NULL;
        struct InnerArray *ia = oa->array[oa->used - 1];
        if (ia->used == 0)
                oa->used--;
        return oa->array[oa->used - 1];
}

char pop_inner_array(struct InnerArray *ia)
{
        return ia->array[--ia->used];
}

struct InnerArray *pop_outer_array(struct OuterArray *oa)
{
        struct InnerArray *ia = peek_outer_array(oa);
        if (ia->used == 0)
                oa->used--;
        return oa->array[oa->used--];
}

char pop(struct OuterArray *oa)
{
        struct InnerArray *ia = peek_outer_array(oa);
        if (! ia)
                return '\0';
        return pop_inner_array(ia);
}

void push(char c, struct OuterArray *oa)
{
        struct InnerArray *ia = make_inner_array(2);
        if (oa->used == 0) {
                push_inner_array(c, ia);
                push_outer_array(ia, oa);
                return;
        }
        ia = peek_outer_array(oa);
        if (ia->used >= MAX_STACK) {
                ia = make_inner_array(MAX_STACK / 2);
                push_inner_array(c, ia);
                push_outer_array(ia, oa);
        } else {
                push_inner_array(c, ia);
        }
}

int main() {
        struct InnerArray *ia = make_inner_array(1);
        struct OuterArray *oa = make_outer_array(1);
        for (char c = 65; c <= 77; c++) {
                printf("pushing: %c\n", c);
                push(c, oa);
        }
        puts("");
        printf("MAX_STACK: %zu\n", MAX_STACK);
        printf("oa->used: %zu\n", oa->used);
        for (int i = 0; i < oa->used; i++) {
                printf("\t");
                printf("oa->array[%d]->used: %zu\n", i, oa->array[i]->used);
        }
        puts("");
        for(char c = 65; c <= 77; c++)
                printf("pop: %c\n", pop(oa));
        return 0;
}

