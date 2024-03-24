#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int newData);
void deleteMiddleNode(struct Node** head);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;
insertAtEnd(&head, 1);
insertAtEnd(&head, 2);
insertAtEnd(&head, 3);
insertAtEnd(&head, 4);
insertAtEnd(&head, 5);

printf("List before deletion: ");
printList(head);
    printf("\n");

deleteMiddleNode(&head);

printf("List after deletion: ");
printList(head);
    printf("\n");

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
printf("Memory allocation failed!\n");
exit(EXIT_FAILURE);
    }
newNode->data = data;
newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteMiddleNode(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
printf("List is empty or contains only one node.\n");
        return;
    }
    struct Node* slowPtr = *head;
    struct Node* fastPtr = *head;
    struct Node* prev = NULL;

    while (fastPtr != NULL &&fastPtr->next != NULL) {
fastPtr = fastPtr->next->next;
prev = slowPtr;
slowPtr = slowPtr->next;
    }

prev->next = slowPtr->next;
    free(slowPtr);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
printf("%d ", temp->data);
        temp = temp->next;
    }
}

