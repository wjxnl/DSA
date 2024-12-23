#include<stdio.h>
#define Max 100

typedef struct{
    int front;
    int rear;
    int data[Max];
}circularQueue;

void Enqueue(circularQueue *Q, int element){
    if(Q->front == (Q->rear + 1) % Max){
        printf("Queue is full. \n");
    }
    else{
      
        Q->data[Q->rear] = element;
        Q->rear= (Q->rear + 1) % Max;
        printf("\n..................................................\n%d is enqueued \n..................................................\n", element);
    }
}

int Dequeue(circularQueue *Q){
    if(Q->front == Q->rear){
        printf("Queue is empty. \n");
        return -1;
    }
    else{
        int element= Q->data[Q->front] ;
        Q->front= (Q->front+1) % Max;
        return element;
    }
}

int main(){
    circularQueue q = {0, 0};
    int choices, element;
    do{
        printf("\n1. Enqueue \n2. Dequeue \n3. Exit\n");
        scanf("%d", &choices);
        switch(choices){
            case 1:
                printf("Enter the element to enqueue \n");
                scanf("%d", &element);
                Enqueue( &q, element);
                break;
            case 2:
                element= Dequeue(&q);
                printf("\n..................................................\nDequeued element is %d \n..................................................\n", element);
                break;
            case 3:
                printf("Bye");
                break;
            default:
                printf("Invalid input");
                break;
        }
    }while(choices != 3);

}