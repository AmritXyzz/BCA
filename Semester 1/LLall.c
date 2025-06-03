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
        ptr->next = head;
        head = ptr;
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
        ptr->next = NULL;

        if (head == NULL) {
            head = ptr;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void deletebeg() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;
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
    if (temp->next == NULL) {
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted element is %d\n", temp->data);
    free(temp);
    prev->next = NULL;
}

void print() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("The elements in the list are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}