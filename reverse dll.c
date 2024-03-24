#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int newData);
void printList(struct Node* head);
void reverseList(struct Node** head);

int main() {
    struct Node* head = NULL;
insertAtEnd(&head, 3);
insertAtEnd(&head, 7);
insertAtEnd(&head, 9);

printf("Original doubly linked list: ");
printList(head);
    printf("\n");

reverseList(&head);

printf("Reversed doubly linked list: ");
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
newNode->prev = NULL;
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
newNode->prev = last;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        if (current != NULL && current->prev == NULL) {
            *head = current;
        }
    }
}

