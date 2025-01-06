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

/*
Objective : convert a string to an integer
Input : string
Output : integer
*/
int str_to_int(char * str){
    int i = 0;
    int res = 0;
    while (str[i] != '\0'){
        res = res*10 + str[i] - '0';
        i++;
    }
    return res;
}
