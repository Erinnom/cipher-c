#define MAX_MEMORY_SIZE 1024*1024

/*
Objective : allocate memory space
Input : Number of Bytes
Output : poiter to this allocated memory
*/
static unsigned char mem[MAX_MEMORY_SIZE] = {};
static int i = 0;
void * malloc(long int size){

    if (i + size > MAX_MEMORY_SIZE){
        return 0;
    }
    void *ptr = &mem[i];
    i+= size;
    return ptr;
}
