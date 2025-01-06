/*
Objective : get the length of a string
Input : string
Output : length of the string
*/
int get_str_length(char * str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
