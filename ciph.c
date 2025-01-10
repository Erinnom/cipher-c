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
    if (key_lenght <= 0){
        printf("Error while reading of key\n");
        return 1;
    }

    // Put key in a variable
    char * key = get_content(keyfile, key_lenght);
    fclose(keyfile);

    // Get file name lenght
    int filenamelenght = get_str_length(argv[1]);

    // define extension
    char * ext = ".ciph";

    // Get extension lenght
    int extlenght = get_str_length(ext);

    // Check if the file has the `ext` extension
    char * ouputfile = malloc((filenamelenght + extlenght+1)*sizeof(char));
    if (compare_str(ext,argv[1]+filenamelenght-extlenght) == 1){
        // Remove the extention from the filename
        int i = 0;
        while (i < filenamelenght - extlenght) {
            ouputfile[i] = argv[1][i];
            i++;
        }
        ouputfile[i] = '\0';
    }else {
        // Add new extention to the filename
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
    }

    // Get text file size
    unsigned long int textlenght = get_file_size(file);
    if (textlenght <= 0){
        printf("Error while reading data file, file size of %ld bytes\n",textlenght);
        return 1;
    }

    // Load text file content
    char * txt = get_content(file,textlenght);
    fclose(file);

    // Cypher the text
    char * res = xor_string(txt,textlenght,key,key_lenght);

    // Create a new file
    FILE *output = fopen(ouputfile,"wb");
    if (output == NULL){
        printf("Unable to write '%s'\n",ouputfile);
        return 1;
    }

    // Write the cipher text into the new file
    fwrite(res, 1, textlenght,output);
    fclose(output);

    return 0;
}
