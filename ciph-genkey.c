/*
Objective: Generate a random key for the ciphering algorithm
Input: command <key_length> <output_file>
Output: a key of <key_length> bytes in <output_file>
*/
#include <stdlib.h>
#include <stdio.h>
#include "./str.h"
int main(int argc, char ** argv){
    // Check the number of arguments
    if (argc != 3){
        printf("command <key_length> <output_file>\n");
        return 1;
    }
    // Open the output file
    FILE * output = fopen(argv[2],"wb");
    if (output == NULL){
        printf("Unable to write '%s'\n",argv[2]);
        return 1;
    }

    // Generate the key
    char * key = malloc(str_to_int(argv[1])*sizeof(char));
    char j;
    srand((unsigned int) &j); // use the address of j as seed
    for (int i = 0; i < str_to_int(argv[1]); i++){
        key[i] = rand()%256;
    }
    // Write the key in the output file
    fwrite(key,sizeof(char),str_to_int(argv[1]),output);
    fclose(output);
    return 0;
}
