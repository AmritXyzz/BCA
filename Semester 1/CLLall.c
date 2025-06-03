#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertbeg();
void insertend();
void deletebeg();
void deleteend();
void print();

int main() {
    int ch;
    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Delete from beginning\n4. Delete from end\n5. Print\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                insertbeg();
                break;
            case 2: 
                insertend();
                break;
            case 3: 
                deletebeg();
                break;
            case 4: 
                deleteend();
                break;
            case 5: 
                print();
                break;
            case 6: 
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    } while (ch != 6);
    
    return 0;
}

void insertbeg() {
    int d;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    } else {
        printf("Enter the data: ");
        scanf("%d", &d);
        ptr->data = d;

        if (head == NULL) {
            head = ptr;
            ptr->next = head; // Point to itself
        } else {
            struct node *temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = ptr; // Link last node to new node
            ptr->next = head; // New node points to head
            head = ptr; // Update head to new node
        }
    }
}

void insertend() {
    int d;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    } else {
        printf("Enter the data: ");
        scanf("%d", &d);
        ptr->data = d;

        if (head == NULL) {
            head = ptr;
            ptr->next = head; // Point to itself
        } else {
            struct node *temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = ptr; // Link last node to new node
            ptr->next = head; // New node points to head
        }
    }
}

void deletebeg() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        if (temp->next == head) {
            // Only one node in the list
            head = NULL; // List becomes empty
        } else {
            struct node *last = head;
            while (last->next != head) {
                last = last->next; // Find the last node
            }
            head = head->next; // Move head to the next node
            last->next = head; // Update last node's next to new head
        }
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    if (temp->next == head) {
        // Only one node in the list
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        head = NULL; // List becomes empty
        return;
    }

    struct node *prev = NULL;
    while (temp->next != head) {
        prev = temp; // Keep track of the second last node
        temp = temp->next; // Move to the last node
    }
    printf("Deleted element is %d\n", temp->data);
    free(temp);
    prev->next = head; // Update second last's next to head
}

void print() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("The elements in the list are:\n");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next; // Move to the next node
        } while (temp != head);
    }
}