#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(Stack* stack, int item) {
    if (stack->top < MAX - 1) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1; // Return -1 if stack is empty
    }
}

// Queue structure using two stacks
typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

// Function to enqueue an item
void enqueue(Queue* queue, int item) {
    push(queue->stack1, item);
}

// Function to dequeue an item
int dequeue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

// Function to display the queue
void display(Queue* queue) {
    // Temporary stack to hold elements for display
    Stack* tempStack = createStack();
    
    // Move elements from stack2 to tempStack for display
    while (!isEmpty(queue->stack2)) {
        push(tempStack, pop(queue->stack2));
    }

    // Move elements from stack1 to tempStack for display
    while (!isEmpty(queue->stack1)) {
        push(tempStack, pop(queue->stack1));
    }

    // Display elements
    printf("Queue: ");
    for (int i = 0; i <= tempStack->top; i++) {
        printf("%d ", tempStack->items[i]);
    }
    printf("\n");

    // Restore elements back to stack2
    while (!isEmpty(tempStack)) {
        push(queue->stack2, pop(tempStack));
    }

    // Free the temporary stack
    free(tempStack);
}

// Main function to demonstrate the queue implementation
int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("Enqueued: %d\n", value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                free(queue->stack1);
                free(queue->stack2);
                free(queue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}