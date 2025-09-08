#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int bill;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int bill) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bill = bill;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertBill(struct Node** head, int bill) {
    struct Node* newNode = createNode(bill);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to calculate total, max, min
void calculateSales(struct Node* head) {
    if (head == NULL) {
        printf("No records found!\n");
        return;
    }

    int total = 0, max = head->bill, min = head->bill;
    struct Node* temp = head;

    while (temp != NULL) {
        total += temp->bill;
        if (temp->bill > max) max = temp->bill;
        if (temp->bill < min) min = temp->bill;
        temp = temp->next;
    }

    printf("\nTotal Sale of the Day: %d\n", total);
    printf("Maximum Bill: %d\n", max);
    printf("Minimum Bill: %d\n", min);
}

int main() {
    struct Node* head = NULL;
    int n, bill;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter bill amount of customer %d: ", i + 1);
        scanf("%d", &bill);
        insertBill(&head, bill);
    }

    calculateSales(head);

    return 0;
}
