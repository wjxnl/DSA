//implementation of SLL - insertion and deletion at the end

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

//insertion
void insert_at_end(int element){
    struct SLL *NewNode = createNode(element);
    if(NewNode == NULL){
        printf("Memory allocation failed \n ");
    }
    else{
        if(first == NULL) {
            first = last = NewNode;

        }
        else{
            last->next =NewNode;
            last = NewNode;
        }
    }
}

//deletion
void delete_at_End(){
    struct SLL *temp = first;
    if(first == NULL){
        printf("List is empty\n");
    }
    else{
        if(first->next == NULL){
            first = last = NULL;
            printf("%d is deleted\n", temp->data);
            free(temp);
        }
        else{
           while(temp->next != last)
           {
            temp = temp->next ;
           }
           last = temp;
           temp = temp->next;
           printf("%d is deleted", temp->data);
           free(temp);
           last->next = NULL;
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
    insert_at_end(100);
    display();
    insert_at_end(200);
    display();
    delete_at_End();
    return 0;
}