#include <stdio.h>
#define MAX_ITERATION 1024*1024

/*
Objective : find the lenght of a string
Input : char * str
Output : int
*/
int str_lenght(char * str){
    int i = 0;
    while (*(str+i) != '\0' && i < MAX_ITERATION){
        i++;
    }
    return i;
}


/*
Objective : print a string in hexadecimal
Input : char * str
Output : None
*/
void str_print_hex(char * str){
    long int i = 0;
    while (*(str+i) != '\0' && i < MAX_ITERATION){
        printf("%0x",*(str+i));
        i++;
    }
    printf("\n");
}
