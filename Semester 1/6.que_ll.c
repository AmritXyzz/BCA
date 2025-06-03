#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued element: %d\n", front->data);
        struct node *temp = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }
        free(temp);
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        struct node *temp = front;
        while (temp != NULL) {
            printf("%d | ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose operation:\n1.Enqueue\n2.Dequeue\n3.Front\n4.Display\n5.Exit\n>>> ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5:
                printf("Exiting program... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}