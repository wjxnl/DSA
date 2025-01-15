//implementation of SLL- insertion and deletion at beginning, searching the key

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

//insertion at beginning
void insert_at_beginning(int element){
    struct SLL *NewNode = createNode(element);
    if(NewNode == NULL){
        printf("Memory allocation failed\n\n ");
    }
    else{
        if( first == NULL){
            first = last = NewNode;
        }
        else{
            NewNode ->next = first;
            first = NewNode;
        }
    }
}

//deletion at beginning
void delete_at_beginning(){
    struct SLL *temp = first;
    if(first == NULL){
        printf("List is empty\n\n");
    }
    else{
        if(first->next == NULL){
            first = last = NULL;
            printf("%d is deleted\n\n", temp->data);
            free(temp);
        }
        else{
            first = first ->next;
            printf("%d is deleted\n\n ", temp->data);
            free(temp);
        }
    }
}

//searching
void search(int key){
    int flag =0;
    
    struct SLL *temp = first;
    if(first == NULL){
        printf("Empty List\n\n");  
    }
     else{
        do{
            if(temp->data == key){
                flag += 1;
            }
            temp = temp->next;
        }
        while(temp != NULL);
            if(flag>0){
                printf("key found\n");
            }
            else{
                printf("key not found\n");
            }
    }
}

void display(){
    struct SLL *temp = first;
    if(first == NULL){
        printf("Empty List\n\n");  
    }
    else{
        do{
            printf("%d  ", temp->data);
            temp = temp ->next;
        }
        while(temp != NULL);
            printf("NULL\n\n");
    }
}

int main(){
    insert_at_beginning(100);
    display();
    insert_at_beginning(200);
    display();
    insert_at_beginning(300);
    display();
    delete_at_beginning();
    display();
    search(900);
    return 0;
}