#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int newData);
void insertAtEnd(struct Node** head, int newData);
void deleteNode(struct Node** head, int key);
void printList(struct Node* head);
int main() {
    struct Node* head = NULL;

insertAtBeginning(&head, 9);
insertAtBeginning(&head, 7);
insertAtBeginning(&head, 3);

printf("Linked list after inserting at the beginning: ");
printList(head);
    printf("\n");

insertAtEnd(&head, 5);

printf("Linked list after inserting at the end: ");
printList(head);
    printf("\n");

deleteNode(&head, 7);

printf("Linked list after deleting node with value 7: ");
printList(head);
    printf("\n");

    return 0;
}

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = newData;
newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
newNode->data = newData;
newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
printf("%d ", temp->data);
        temp = temp->next;
    }
}




