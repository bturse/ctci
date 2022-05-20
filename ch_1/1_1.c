#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_char_unique(char *str, int n)
{
        int i, j;
        for (i = 0; i < n - 1; ++i) {
                printf("i: %d\tstr[%d]: %c\n", i, i, str[i]);
                for (j = i + 1; j < n; ++j) {
                        printf("\tj: %d\tstr[%d]: %c\n", j, j, str[j]);
                        if (str[i] == str[j])
                                return false;
                }
        }
        return true;
}


int main() {
        char *test = "abcdeff";
        if(is_char_unique(test, strlen(test)))
                puts("unique");
        else
                puts("not unique");
        return 0;
}
