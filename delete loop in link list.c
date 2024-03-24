#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
bool detectLoop(struct Node* head);

int main() {
    struct Node* head = NULL;

insertAtEnd(&head, 1);
insertAtEnd(&head, 2);
insertAtEnd(&head, 3);
insertAtEnd(&head, 4);
    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
printf("Loop detected in the linked list.\n");
    } else {
printf("No loop detected in the linked list.\n");
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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

