#define MAX_ITERATION 1024*1024

int str_lenght(char * str){
    int i = 0;
    while (*(str+i) != '\0' && i < MAX_ITERATION){
        i++;
    }
    return i;
}
