#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) 
        return;
    struct Node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
}

void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) 
        return;
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        temp->next = NULL;
        return;
    }
    int i = 0;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) 
        return;
    struct Node* next = temp->next->next;
    temp->next->next = NULL;
    temp->next = next;
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void push(struct Node** head, int newdata) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = newdata;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter Value %d : ", i + 1,"\n");
        scanf("%d", &data);
        push(&head, data);
    }
    printf("Original list: ");
    printList(head);
    int choice;
    printf("Enter 1 to delete the first node\n 2 to delete a node at a position\n 3 to delete the last node: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            deleteFirstNode(&head);
            printf("After deleting the first node: ");
            printList(head);
            break;
        case 2: ;
            int position;
            printf("Enter the position of the node to delete: ");
            scanf("%d", &position);
            deleteNodeAtPosition(&head, position);
            printf("After deleting node at position %d: ", position);
            printList(head);
            break;
        case 3:
            deleteLastNode(&head);
            printf("After deleting the last node: ");
            printList(head);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
