#include <stdio.h>

double add(double a, double b){return a+b;}
double sub(double a, double b){return a-b;}
double multiply(double a, double b){return a*b;}
double divide(double a, double b){return a/b;}

int main(){

    double i, j;
    double (* operation)(double, double);

    printf("what is the two input numbers. \n");
    scanf("%lf %lf", &i, &j);

    int select;
    printf("what is the operation? \n");

    scanf("%d", &select);
    switch(select){
        case 1:
        operation = add;
        break;
        case 2:
        operation = sub;
        break;
        case 3:
        operation = multiply;
        break;
        case 4:
        operation = divide;
        break;
    }

    printf("%lf ", operation(i, j));

    return 0;
}