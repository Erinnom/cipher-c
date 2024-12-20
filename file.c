/*
Objective : Size of the file
Input : FILE * file
Output : long int
*/

long int file_size(FILE * file) {
    long int size = 0;
    while (fgetc(file) != EOF) {
        size++;
    }
    return size;
}

/*
Objective : read a file
Input : FILE * file
Output : char *
*/
char * file_read(FILE * file) {
    char * output = malloc(file_size(file) + 1);
    if (output == 0) {
        return 0;
    }
    long int i = 0;
    while ((output[i] = fgetc(file)) != EOF) {
        i++;
    }
    output[i + 1] = '\0';
    return output;
}
