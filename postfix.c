#include <stdio.h>
#include<math.h>
#define Max 100


typedef struct{
    int data[Max];
    int tos;
}stack;

void push(stack *s, int num){
    if(s->tos == Max-1){
        printf("Stack is full.");
    }else{
        s->tos++;
        s->data[s->tos] = num;
    }
}

int pop(stack *s){
    if(s->tos == -1){
        printf("Stack underflow");
        return 0;
    }
    else{
        return s->data[s->tos--];
    }
}

int calculateStack (int op1, int op2, char operator ){
    if(operator=='+'){
        return op2 + op1;
    }
    else if(operator == '-'){
        return op2 - op1;
    }
    else if(operator == '*'){
        return op2 * op1;
    }
    else if(operator == '/'){
        return op2 / op1;
    }
    else if( operator == '^'){
        return pow(op2, op1);
    }
    else{
        return -1;
    }
}

void printStack (stack *s){
    if(s->tos == -1){
        printf("Stack is empty");
    }
    else{
        for(int i=0; i<= s->tos; i++ ){
            printf(" Answer : %d", s->data[i]);
        }
    }
}

int main(){
    stack s;
    s.tos = -1;
    int op1 , op2 , result;
    char expression[Max] = {'2' , '3' , '+', '5', '6', '+', '*'};

    for (int i = 0; expression[i] != '\0' ; i++)
    {
        if(expression[i] >= '0'  && expression[i] <= '9'){
            int input = expression[i] - '0';
            push(&s,input);
        }else{
            op1= pop(&s);
            op2= pop(&s);
            result = calculateStack(op1, op2, expression[i]);
            push(&s, result);
        }
    }
    printStack(&s);   
}

