// Constants
#define PI 3.1415926535897932384626433832795028841971693993751
#define E 2.71828182845904523536028747135266249775724709369995
#define G 6.67430e-11
#define H 6.62607015e-34
#define C 299792458
#define KB 1024
#define MB 1024*1024
#define GB 1024*1024*1024
#define TB 1024*1024*1024*1024
#define PB 1024*1024*1024*1024*1024
#define EB 1024*1024*1024*1024*1024*1024
#define ZB 1024*1024*1024*1024*1024*1024*1024
#define YB 1024*1024*1024*1024*1024*1024*1024*1024


/*
Objective : find max between two value
Input : int a, int b
Output : int
*/
long int int_max(long int a, long int b){
    if (a > b){
        return  a;
    }
    return b;
}

/*
Objective : find min between two value
Input : int a, int b
Output : int
*/
int int_min(long int a, long int b){
    if (a < b){
        return  a;
    }
    return b;
}
