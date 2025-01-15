#include<stdio.h>
#define Max 10
//define person as a structure
typedef struct 
{
    char name[50];
    int age;
}person;

//define stack as a structure
typedef struct 
{
    int tos;
    person data[Max];
}stack;

//initialising stack
void initialiseStack(stack *s){
    s->tos= -1;
}

//isEmpty function
int isEmpty(stack *s){
    if(s->tos == -1){
        return 1;
    }
    return 0;
}

//isFull function
int isFull(stack *s){
    if(s->tos == Max-1){
        return 1;
    }
    return 0;
}

//push function
void push(person p, stack *s){
    if(isFull(s)){
        printf("Stack overflow");
    }
    else{
    s->data[++s->tos] = p;
    }
}

//pop function
person pop(stack *s){
    if(isEmpty(s)){
        printf("Stack underflow");
        person null = {
            "",0
        };
        return null;
    }
    else{   
        return s->data[s->tos--];
    }
}

//peek function
person peek(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty. Insert some datas.");
        person null = {
            "", 0
        };
        return null;
    }
    return s->data[s->tos];
}

//display function
void displayStack(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
    }
    else{
    for (int i = 0; i <= s->tos; i++){
        printf("\nPerson %d: \n Name: %s,\n Age: %d \n\n ", i+1, s->data[i].name, s->data[i].age);
    }
    }
}

int main(){
    stack s;
    initialiseStack(&s);

    person p1 = {"anusha", 20};
    person p2 = {"joe", 15};
    person p3 = {"jack", 25};

    printf("\n Initial stack \n");
    displayStack(&s);

    push(p1, &s);
    push(p2, &s);
    push(p3, &s);

    printf("\n New stack \n");
    displayStack(&s);

    printf("\n Popping stack \n");
    person poppedItem = pop(&s);
    printf("Popped Item: \n Name: %s,\n Age: %d \n ",  poppedItem.name, poppedItem.age);
    printf("\n After popping stack \n");
    displayStack(&s);

    printf("\n Peeking stack \n");
    person peekedItem = peek(&s);
    printf("Peeked Item: \n Name: %s,\n Age: %d \n ",  peekedItem.name, peekedItem.age);
    
    return 0;
}
