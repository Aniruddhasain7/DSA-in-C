#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertinlinkedlist(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node* head = NULL;
    insertinlinkedlist(&head, 10, 1); 
    insertinlinkedlist(&head, 20, 2); 
    insertinlinkedlist(&head, 30, 3);
    insertinlinkedlist(&head, 25, 3); 
    printList(head); 
    return 0;
}
