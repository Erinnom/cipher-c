#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
/*
Objective : get the size of a file
Input : file
Output : size of the file
*/

int get_file_size(FILE *file){
    // Save the current position
    long current = ftell(file);
    // Move to the end of the file
    fseek(file,0,SEEK_END);
    // Get the position
    long size = ftell(file);
    // Move back to the saved position
    fseek(file,current,SEEK_SET);
    return size;
}

/*
Objective : get the content of a file
Input : file, length
Output : content of the file
*/
char *get_content(FILE *file, int length){
    char *content = (char *)malloc(length);
    fread(content,1,length,file);
    return content;
}
#endif
