#include "str.c"
#include "math.c"
#include "mem.c"


/*
Objective : apply xor opperation between two value
Input : int a, int b
Output : int
*/
int int_xor(int a, int b){
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
Output : int
*/
char * str_xor(char *a, char *b, char *output){
    int len_a = str_lenght(a);
    int len_b = str_lenght(b);
    int len = int_max(len_a,len_b);
    output = malloc(len);
    for (int i = 0; i < len;i++){
        *(output+i) = *(a+i) ^ *(b+i);
    }
    return output;
}
