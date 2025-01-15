//implementation of SLL- insertion at specific position

#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int data;
    struct SLL *next ;
};

struct SLL *first, *last = NULL;
struct SLL* createNode(int element){
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    if(NewNode != NULL){
        NewNode ->data = element;
        NewNode ->next = NULL;
    }
    return NewNode;
}

void insert_at_specific_postition(int element, int postion){
    struct SLL *NewNode = createNode(element);
    if(NewNode == NULL){
        printf("Memory allocation failed \n ");
    }
    else{
        if( postion == 1){
            NewNode->next = first;
            first = NewNode;
        }
        else{
            struct SLL *temp = first;
            for(int i = 1; i<postion-1; i++){
                temp = temp->next;
            }
            NewNode->next = temp->next;
            temp ->next =NewNode;
        }
    }
}

void display(){
    struct SLL *temp = first;
    if(first == NULL){
        printf("Empty List \n");  
    }
    else{
        do{
            printf("%d  ", temp->data);
            temp = temp ->next;
        }
        while(temp != NULL);
            printf("NULL \n");
    }
}

int main(){
    insert_at_specific_postition(100,1);
    display();
    insert_at_specific_postition(200,2);
    display();
    insert_at_specific_postition(300,3);
    display();
    insert_at_specific_postition(400,4);
    display();
    insert_at_specific_postition(500,3);
    display();
  
    return 0;
}