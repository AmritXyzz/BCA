#include <stdio.h>
#define N 7

int queue[N];
int front = -1;
int rear = -1;

void enqueue() {
    if ((rear + 1) % N == front) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) { // Queue is empty
            front = 0;
        }
        rear = (rear + 1) % N;
        printf("Enter data: ");
        scanf("%d", &queue[rear]);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        if (front == rear) { // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % N;
        }
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