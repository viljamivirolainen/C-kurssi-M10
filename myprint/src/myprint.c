#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "stdlib.h"

int myprint(const char *str, ...) {
    va_list args;
    int count = 0;
    const char *cpy = str;
    int len = strlen(str);
    int i = 0;
    int number;
    while (i <= len) {
        if (str[i] == '&') count++;
        i++;
    }
    va_start(args, str);
    for (int x = 0; x<len;x++) 
    {
        if(cpy[x] == '&') {
            number = va_arg(args, int);
            printf("%d", number);
        } 
        else printf("%c",cpy[x]);
    }
    va_end(args);
    return count;
}
