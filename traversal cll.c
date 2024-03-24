#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int newData);
void traverseCircularLinkedList(struct Node* head);

int main() {
    struct Node* head = NULL;

insertAtEnd(&head, 3);
insertAtEnd(&head, 7);
insertAtEnd(&head, 9);

printf("Circular linked list: ");
traverseCircularLinkedList(head);

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
newNode->next = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
newNode->next = *head;
        *head = newNode; // Update head to point to the new node
    }
}

void traverseCircularLinkedList(struct Node* head) {
    if (head == NULL) {
printf("Circular linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

