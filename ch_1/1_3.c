#include <stdio.h>
#include <string.h>

void get_url_str(char *str) 
{
        for (int i = 0; i < strlen(str); i++) {
                if (str[i] == ' ') {
                        putchar('%');
                        putchar('2');
                        putchar('0');
                } else
                        putchar(str[i]);
        }
}

int main() {
        char *test = "this is some text";
        get_url_str(test);
        return 0;
}
