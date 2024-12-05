#include "xor.c"
#include <stdio.h>

int main(){
    char str1[10] = "Hallo";
    char str2[10] = "Woald";

    char *output = str_xor(str1, str2);
    int j = 0;
    while (j < 5){
        printf("%0x\n",output[j]);
        j++;
    }
    // printf("%0x\n",output);
    return 0;
}
