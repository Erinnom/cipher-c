// Constants
#include <stdio.h>
#include <sys/types.h>
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
#define MAX_ITERATION 10
// Structures

struct complex{
    double Re;
    double Im;
};

struct polar{
    double r;
    double theta;
};

// Functions

/*
Objective : Convert a complex number from cartesian to polar
Input : struct complex
Output : struct polar
*/
// struct polar complex_to_polar(struct complex c){
//     struct polar p;
//     p.r = (c.Re*c.Re + c.Im*c.Im)**(1/2);
//     p.theta = atan(c.Im/c.Re);
//     return p;
// }

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

/*
Objective : factorial function
Input : int n
Output : int
*/
long int factorial(long int n){
    long int register i = n;
    long int register res = 1;
    while (i > 1){
        res *= i;
        i--;
    }
    return res;
}


/*
Objective : power function
Input : double x, int n
Output : double
*/
double power(double x, long int n){
    double register res = 1;
    long int register i = 0;
    while (i < n){
        res *= x;
        i++;
    }
    return res;
}

/*
Objective : sin function around 0
Input : double x
Output : double
*/
double sin0(double x) {
    while (x > 2*PI){
        x -= 2*PI;
    }
    while (x < -2*PI){
        x += 2*PI;
    }
    double register res = 0;
    long int register i = 0;
    while (i < MAX_ITERATION){
        res += power(-1,i)*power(x,2*i+1)/factorial(2*i+1);
        i++;
    }
    return res;
}

/*
Objective : cos function around 0
Input : double x
Output : double
*/
double cos0(double x) {
    while (x > 2*PI){
        x -= 2*PI;
    }
    while (x < -2*PI){
        x += 2*PI;
    }
    double register res = 0;
    long int register i = 0;
    while (i < MAX_ITERATION){
        res += power(-1,i)*power(x,2*i)/factorial(2*i);
        i++;
    }
    return res;
}

/*
Objective : tan function around 0
Input : double x
Output : double
*/
double tan0(double x) {
    return sin0(x)/cos0(x);
}
