#include <stdio.h>	
#define N 7
int queue[N];
int front=-1;
int rear =-1;
void enqueue(){
    if(rear==(N-1)){
        printf("Queue is full!\n");
    }else if(rear==-1){
        rear=0;
        front=0;
        printf("enter data : ");
        scanf("%d",&queue[front]);
    }else{
        rear++;
        printf("enter data : ");
        scanf("%d",&queue[rear]);
    }
}
void dequeue(){
    if(rear==-1 && front==-1){
        printf("Queue is empty!\n");
    }else if(rear==front){
        printf("Dequeued element : %d",queue[rear]);
        rear=-1;
        front=-1;
    }else{
        printf("Dequeued element : %d",queue[front]);
        front++;
    }
}
void peek(){
    if(rear==-1 && front==-1){
        printf("Queue is empty!\n");
    }else{
        printf("Front element : %d",queue[front]);
    }
}
void display(){
    if(rear==-1 && front==-1){
        printf("Queue is empty!\n");
    }else{
        printf("Queue elements : \n");
        for(int i=front; i<=rear; i++){
            printf("%d| ",queue[i]);
        }
    }
}
int main(){
    int choice;
    while(1){
        printf("\nchoose operation : \n1.Enqueue\n2.Dequeue\n3.front\n4.display\n5.exit\n>>>");
        if(scanf("%d",&choice)!=1){
            printf("invalid input! please enter a number.\n");
            while(getchar()!='\n');
                continue;
        }
    
        switch (choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("exiting program...Goodbye!\n");
                return 0;
            default:
                printf("invalid choice! try again.\n");
        }
    }
    return 0;
}