#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool is_pal_perm(char str[])
{
        int i;
        char char_ct[255] = {0};
        int even_ct = 0;
        for (i = 0; i < strlen(str); i++)
                char_ct[str[i]]++;
        for (i = 0; i < 255; i++) {
                if (char_ct[i] % 2 != 0)
                        even_ct++;
                if (even_ct > 1)
                        return false;
        }
                return true;
}

int main() {
        char *str = "abbcc2233";
        if (is_pal_perm(str))
                puts("true!");
        else
                puts("not true!");
        return 0;
}


