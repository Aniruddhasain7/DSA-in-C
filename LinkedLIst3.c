#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = NULL; 
        current = next;
    }
    *head = NULL; 
}

void append(struct Node** head, int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newnode->data = newdata;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newnode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }  
}

int main() {
    struct Node* head = NULL;
    int n, value, i = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    while (i < n) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
        i++;
    }

    printf("Original list: ");
    printList(head);

    deleteList(&head);
    printf("\nLinked list deleted\n");

    return 0;
}
