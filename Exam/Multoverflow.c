#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int mult(int a, int b){
    if((abs(b) > 1) && (abs(a) > (INT_MAX/abs(b)))){
        printf("Error overflow");
        return -1;
    }else{
        int ans = a*b;
        printf("your answer is %d", ans);
        return ans;
    }
}


int main(){
    int a, b;
    printf("what is the two input numbers. \n");
    scanf("%d %d", &a, &b);
    return mult(a, (INT_MAX/3));
    return 0;
}