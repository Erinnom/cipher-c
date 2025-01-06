#include <stdio.h>
#include <stdlib.h>
#include "./file.h"
#include "./str.h"
#include "./xor.h"
/*
Objective : cypher a text with a key with the XOR method
Input : command <file> <key>
Output : cyphered text
*/

int main(int argc, char **argv){
    // Check if command is conform
    if (argc != 3){
        printf("command <file path> <keyfile path\n");
        return 1;
    }
    // Open text file
    FILE *file = fopen(argv[1],"rb");
    if (file == NULL){
        printf("Unable to open %s\n",argv[1]);
        return 1;
    }
    // Open key file
    FILE *keyfile = fopen(argv[2],"rb");
    if (keyfile == NULL){
        printf("Unable to open %s\n",argv[2]);
        return 1;
    }

    // Get the key size
    int key_lenght = get_file_size(keyfile);

    // Put key in a variable
    char * key = get_content(keyfile, key_lenght);
    fclose(keyfile);

    // Get file name lenght
    int filenamelenght = get_str_length(argv[1]);

    // define extension
    char * ext = ".ciph";

    // Get extension lenght
    int extlenght = get_str_length(ext);

    // Add new extention to the filename
    char * ouputfile = malloc((filenamelenght + extlenght)*sizeof(char));
    int i = 0;
    while (i < filenamelenght + extlenght) {
        if (i < filenamelenght){
            ouputfile[i] = argv[1][i];
        }else{
            ouputfile[i] = ext[i-filenamelenght];
        }
        i++;
    }
    ouputfile[i] = '\0';

    // Create a new file
    FILE *output = fopen(ouputfile,"wb");
    if (output == NULL){
        printf("Unable to write '%s'\n",ouputfile);
        return 1;
    }

    // Get text file size
    int textlenght = get_file_size(file);

    // Load text file content
    char * txt = get_content(file,textlenght);
    fclose(file);

    // Write the cipher text in the new file
    fwrite(xor_string(txt,textlenght,key,key_lenght), 1, textlenght,output);
    fclose(output);

    return 0;
}
