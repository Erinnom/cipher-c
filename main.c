#include "xor.c"
#include "file.c"


int main(int argc, char **argv){
    if (argc != 4){
        //printf("Usage : %s <message> <key> <output>\n",argv[0]);
        return 1;
    }
    FILE *message = fopen(argv[1],"rb");
    if (message == 0){
        //printf("Error : can't open %s\n",argv[1]);
        return 1;
    }
    FILE *key = fopen(argv[2],"rb");
    if (key == 0){
        //printf("Error : can't open %s\n",argv[2]);
        return 1;
    }

    char *message_str = file_read(message);
    if (message_str == 0){
        //printf("Error : can't read %s\n",argv[1]);
        return 1;
    }
    char *key_str = file_read(key);
    char *output_str = str_xor(message_str,key_str);
    if (output_str == 0){
        //printf("Error : can't xor %s and %s\n",argv[1],argv[2]);
        return 1;
    }
    FILE *output = fopen(argv[3],"wb");
    if (output == 0){
        //printf("Error : can't open %s\n",argv[3]);
        return 1;
    }
    fprintf(output,output_str);

    fclose(message);
    fclose(key);
    fclose(output);

    return 0;
}
