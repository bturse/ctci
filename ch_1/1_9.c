#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool is_substring(char *main_str, char *sub_str)
{
        int j, i = 0;
        while (main_str[i] != '\0') {
                j = 0;
                while (sub_str[j] != '\0') {
                        if (main_str[i] == sub_str[j])
                                j++;
                        else
                                break;
                        return true;
                }
                i++;
        }
        return false;
}

char *concat(const char *str1, const char *str2)
{
        const size_t len1 = strlen(str1);
        const size_t len2 = strlen(str2);
        char *result = malloc(sizeof(len1 + len2 + 1));
        if (!result)
                exit(1);
        memcpy(result, str1, len1);
        memcpy(result + len1, str2, len2 + 1);
        return result;
}

bool is_rotation(char *main_str, char *rotated_str)
{
        char *concat_rotated = concat(rotated_str, rotated_str);
        return is_substring(concat_rotated, main_str) ? true : false;
}

int main() {
        
        char *str1 = "waterbottle";
        char *str2 = "erbottlewat";
        puts(is_substring(str1, str2) ? "true" : "false");
//        printf("%s", concat(str1, str2)); 
        return 0;
}
