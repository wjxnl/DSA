#include<stdio.h>

void toh(int n, char src, char dest, char temp){
    if(n == 1){
        printf("move disk %d from %c to %c \n", n, src, dest);
    }
    else{
        toh(n-1, src, temp, dest);
        printf("move disc %d from %c to %c\n", n, src, dest);
        toh(n-1, temp, dest, src);
    }
}

int main(){
    int num;
    char A='A', B='B', C='C';
    printf("Enter the number of disc: \n");
    scanf("%d", &num);
    toh(num, A, C, B);
}