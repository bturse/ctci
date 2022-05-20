#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Array {
        size_t size;
        size_t used;
        char *str;
};

void append_array(struct Array *arr, char c)
{
        if(arr->used == arr->size) {
                arr->size *= 2;
                arr->str = strcpy(malloc(sizeof(arr->size)), arr->str);
        }
        arr->str[arr->used++] = c;
}

struct Array *make_array(size_t init_size)
{
        struct Array *new_array = malloc(sizeof(struct Array));
        if (!new_array)
                exit(1);
        new_array->size = init_size;
        new_array->used = 0;
        new_array->str = malloc(init_size);
        return new_array;
}

void compress(char str[])
{       
        int i;
        int compr_len = 0;
        struct Array *compr_arr = make_array(2);

        for (i = 0; i < strlen(str); i++){
                int ahead = 1;
                int streak = 1;
                while (str[i] == str[i + ahead++])
                        streak++;
                i += streak - 1;
                printf("%c", str[i]);
                printf("%d", streak);
                compr_len += 2;
        }
}

int main() {
//        compress("aabcccccaaa");
        compress("abcd");

        return 0;
}
