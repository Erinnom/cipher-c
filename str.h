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

/*
Obejctive : compare two strings
Input : two strings
Output : 1 if the strings are the same, 0 otherwise
*/
int compare_str(char * str1, char * str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0'){
        return 1;
    }
    return 0;
}
