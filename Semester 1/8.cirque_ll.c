#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
    int value;
    printf("Enter data: ");
    scanf("%d", &value);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) { // Queue is empty
        front = newNode;
        rear = newNode;
        rear->next = front; // Point rear to front to make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued element: %d\n", front->data);
        if (front == rear) { // Only one element
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            rear->next = front; // Maintain circular link
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
        struct Node* temp = front;
        printf("Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose operation:\n1.Enqueue\n2.Dequeue\n3.Front\n4.Display\n5.Exit\n>>>");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
 continue;
        }

        switch (choice) {
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
                printf("Exiting program... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}