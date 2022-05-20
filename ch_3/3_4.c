#include <stdlib.h>
#include <stdio.h>

struct Array {
        size_t size;
        size_t used;
        int *array;
};

struct Queue {
        struct Array *l_array;
        struct Array *r_array;
};

struct Array *make_array(size_t init_size)
{
        struct Array *new_array = malloc(sizeof(struct Array));
        if (! new_array)
                exit(1);
        new_array->array = malloc(sizeof(new_array->array) * init_size);
        if (! new_array->array)
                exit(1);
        new_array->size = init_size;
        new_array->used = 0;
        return new_array;
}

struct Queue *make_queue()
{
        struct Queue *new_queue = malloc(sizeof(struct Queue));
        if (! new_queue)
                exit(1);
        new_queue->l_array = NULL;
        new_queue->r_array = NULL;
        return new_queue;
}

void push(int i, struct Array *a)
{
        if(a->used >= a->size) {
                a->size *= 2;
                a->array = realloc(a->array, sizeof(a->array) * a->size);
        }
        a->array[a->used++] = i;
}

int pop(struct Array *a)
{
        return a->array[--a->used];
}

int peek(struct Array *a)
{
        return a->array[a->used - 1];
}

void reset_array(struct Array *a, size_t init_size)
{
        a->used = 0;
        a->size = init_size;
        a->array = realloc(a->array, sizeof(a->array) * a->size);
}

void add(int i, struct Queue *q)
{
        struct Array *l_array = q->l_array;
        struct Array *r_array = q->r_array;
        reset_array(r_array, 5);
        push(i, l_array);
        for (int n = l_array->used - 1; n >= 0; n--)
                push(l_array->array[n], r_array);
}

int remove_q(struct Queue *q)
{
        return pop(q->r_array);
}

int main() {
        struct Array *l_array = make_array(5);
        struct Array *r_array = make_array(5);
        struct Queue *queue = make_queue();
        queue->l_array = l_array;
        queue->r_array = r_array;

        for (int i = 0; i < 10; i++)
                add(i, queue);

        printf("l_array:\n");
        for (int i = 0; i < 10; i++)
                printf("%d:\t%d\n", i, queue->l_array->array[i]);
        printf("r_array:\n");
        for (int i = 0; i < 10; i++)
                printf("%d:\t%d\n", i, queue->r_array->array[i]);
        puts("remove:");
        for (int i = 0; i < 10; i++)
                printf("%d:\t%d\n", i, remove_q(queue));
        return 0;
}


