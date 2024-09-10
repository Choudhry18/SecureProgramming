#include <stdio.h>
#include <string.h>


/*
Write a C program that takes a string of letters as input and outputs the letter that appears most frequently in the string. 
If there are multiple letters with the same maximum frequency, output the first one that reaches this frequency. 
*/

int main(void){

    char in [100];
    scanf("%s", in);
    int length = strlen(in);
    int counter[52] = {0};
    char maxChar = ',';
    int maxCount = 0;
    for(int i=0; i< length; i++){
        char chr = in[i];
        if(chr >= 'a' && chr <= 'z'){
            counter[chr - 'a']++;
            if(counter[chr - 'a'] > maxCount){
                maxChar = chr;
                maxCount = counter[chr - 'a'];
            }
        }else{
            counter[(chr - 'A') + 26]++;
            if(counter[(chr - 'A') + 26] > maxCount){
                maxChar = chr;
                maxCount = counter[chr - 'a'];
            }
        }
    }

    printf("The max occuring character is %c ", maxChar);
    printf("It Occurs %d times", maxCount);
}