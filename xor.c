#include "str.c"
#include "math.c"
#include "mem.c"
/*
Objective : apply xor opperation between two value
Input : int a, int b
Output : int
*/
long int int_xor(long int a, long int b){
    return a ^ b;
}


/*
Objective : apply xor opperation between two value
Input : char a, char b
Output : char
*/
char char_xor(char a, char b){
    return a ^ b;
}


/*
Objective : apply xor opperation between two value
Input : int a, int b
Output : None
*/
char * str_xor(char *a, char *b){
    int len_a = str_lenght(a);
    int len_b = str_lenght(b);
    int len = int_max(len_a,len_b);
    char *output = malloc(len+1);
    if (output == 0){
        return 0;
    }
    for (int i = 0; i < len;i++){
        output[i] = char_xor(a[i%len_a], b[i%len_b]);
    }
    output[i+1] = '\0';
    return output;
}
