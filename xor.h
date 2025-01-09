#ifndef XOR_H
#define XOR_H
#include <stdio.h>
#include <stdlib.h>
/*
Objective : cypher a text with a key with the XOR method
Input : data, data length, key, key length
Output : cyphered text
*/
char * xor_string(char *txt, int txt_length,char *key,int key_length){
    char *output = (char *)malloc(txt_length);
    for (int i = 0; i < txt_length; i++){
        output[i] = txt[i] ^ key[i%key_length];
    }
    return output;
}
#endif
