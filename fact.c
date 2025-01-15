#include<stdio.h>

int fact(int n ){
    if(n==1){
        return 1;
    }
    else{
        return fact(n-1)*n;
    }
}

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("The answer is:: %d \n", fact(num) );
}