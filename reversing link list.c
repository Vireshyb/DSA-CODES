#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int newData);
void printList(struct Node* head);
struct Node* reverseList(struct Node* head);

int main() {
    struct Node* head = NULL;
insertAtEnd(&head, 1);
insertAtEnd(&head, 2);
insertAtEnd(&head, 3);
insertAtEnd(&head, 4);
insertAtEnd(&head, 5);

printf("Original linked list: ");
printList(head);
    printf("\n");

    head = reverseList(head);

printf("Reversed linked list: ");
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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
prev = current;
        current = next;
    }

    return prev;
}

