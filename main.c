#include "xor.c"
#include <stdio.h>

int main(){
    char *output;
    char str1[10] = "hello";
    char str2[10] = "World";
    str_xor(str1, str2, output);
    printf("%s\n",output);
    return 0;
}
