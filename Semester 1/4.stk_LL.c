#include <stdio.h>	
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }   
    printf("enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top==NULL){
        printf("stack is empty!\n");
    }else{
        struct node *temp;
        temp=top;
        printf("popped element : %d\n",temp->data);
        top=top->next;
        free(temp);        
    }
}
void peek(){
    if(top==NULL){
        printf("stack is empty!\n");
    }else{
        printf("top element : %d\n",top->data);
    }
}
void display(){
    if(top==NULL){
        printf("stack is empty!\n");
    }else{
        struct node *temp;
        temp=top;
        printf("stack elements (top to bottom):\n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int choice;
    while(1){
        printf("\nchoose operation : \n1.push\n2.pop\n3.peek\n4.display\n5.exit\n>>>");
        if(scanf("%d",&choice)!=1){
            printf("invalid input! please enter a number.\n");
            while(getchar()!='\n');
                continue;
        }
    
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
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
}