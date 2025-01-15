#include<stdio.h>
long long int fact(int n){
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i; 
    }
    return result;
}

int main(){
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of a negative number doesn't exist\n");
    } 
    else {
        printf("Factorial of %d is %lld\n", num, fact(num));
    }
    return 0;
}
