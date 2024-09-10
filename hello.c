#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(void){
    srand(time(NULL));
    int result = (rand() % 5) + 1;
    return result;
}

int square(int a){
    return a * a;
}

int custSum(int a){
    int sum = 0;
    for(int i=0; i < a; i++){
        if((i % 3 == 0) || (i % 5 == 0)){
            sum += i;
        }
    }
    return sum;
}

long long maxPrimeFactors(long long n)
{

    long long maxPrime = -1;


    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    while (n % 3 == 0) {
        maxPrime = 3;
        n = n / 3;
    }


    for (int i = 5; i*i<=n; i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0) {
            maxPrime = i + 2;
            n = n / (i + 2);
        }
    }

    if (n > 4)
        maxPrime = n;

    return maxPrime;
}

int main(void){

  int num;
  scanf("%d", &num);
  printf("this is the value %d \n", square(num));
  printf("This is the random %d \n", dice());
  printf("this is sum of 3 or 5 multiples below 1000 %d \n", custSum(1000));
  printf("Largest prime factor %lld \n", maxPrimeFactors(25698751));
}


