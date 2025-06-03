#include <stdio.h>
#include <stdlib.h>

#define N 7
int stack[N], top = -1;

void push() {
    if (top == (N - 1)) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        top++;
        printf("Enter data: ");
        if (scanf("%d", &stack[top]) != 1) {
            printf("Invalid input! Please enter a valid integer.\n");
            top--;
            while (getchar() != '\n');
        }
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("  %d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n>>> ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}