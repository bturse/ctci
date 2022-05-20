#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_permutation(char *str_1, char *str_2) 
{
        int str1_ct[255] = {0};
        int str2_ct[255] = {0};
        for (int i = 0; i < strlen(str_1); i++)
                //printf("%d\t%c")
                str1_ct[str_1[i]] += 1;
        for (int j = 0; j < strlen(str_2); j++)
                str2_ct[str_2[j]] += 1;
        for (int k = 0; k < 255; k++) {
                if (str1_ct[k] == str2_ct[k])
                        continue;
                else
                        return false;
        }
        return true;
}

int main() {
        char *str1 = "ttiip";
        char *str2 = "itpit";
        if (is_permutation(str1, str2))
                puts("permutation");
        else
                puts("not permutation");
        return 0;
}
