#include<stdio.h>
#define Max 100

typedef struct{
    int front;
    int rear;
    int data[Max];
}LQ;

// enqueue
void enqueue(LQ *Q, int element){
    if(Q->rear == Max-1){
        printf("Queue overflow\n");
    }
    else{
        Q->rear++;
        Q->data[Q->rear] = element;
        printf("%d is enqueued \n", element);
    }
}

// dequeue
int dequeue(LQ *Q){
    if(Q->front > Q->rear){
        printf("Queue empty \n");
        return -1;
    }
    else{
        int element = Q->data[Q->front];
        Q->front++;
        return element;
    }
}

int main(){
    LQ Q = {0, -1};
    int choice, element;

    while(1){
        printf("\n Queue Operations \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&Q, element);
                break;

            case 2: 
                element = dequeue(&Q);
                if (element != -1) {
                    printf("Dequeued: %d\n", element);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}