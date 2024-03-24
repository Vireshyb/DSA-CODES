#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int newData);
void printList(struct Node* head);
int findMiddle(struct Node* head);

int main() {
    struct Node* head = NULL;

insertAtEnd(&head, 3);
insertAtEnd(&head, 7);
insertAtEnd(&head, 9);
insertAtEnd(&head, 5);
insertAtEnd(&head, 2);

printf("Linked list: ");
printList(head);
    printf("\n");

    int middle = findMiddle(head);
    if (middle != -1) {
printf("Middle element of the linked list: %d\n", middle);
    } else {
printf("Linked list is empty.\n");
    }

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

int findMiddle(struct Node* head) {
    if (head == NULL) {
        return -1;
    }
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while (fast_ptr != NULL &&fast_ptr->next != NULL) {
fast_ptr = fast_ptr->next->next;
slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}
