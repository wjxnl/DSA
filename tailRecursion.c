#include<stdio.h>
long long fact(int n, long int acc){
    if(n == 1){
        return acc;
    }
    else{
        return fact(n-1, acc*n);
    }
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The result is %ld \n", fact(n, 1));
}