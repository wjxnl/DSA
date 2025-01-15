#include<stdio.h>

int fibo(int n){
    if(n==1 || n==2){
        return 1;
    }
    else{
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    int num;
    printf("Enter the number:: ");
    scanf("%d", &num);
    printf("The result is:: %d", fibo(num));
    return 0;
}