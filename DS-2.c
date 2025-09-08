#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack push
void push(int stack[], int *top, int val) {
    if (*top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = val;
}

// Stack pop
int pop(int stack[], int *top) {
    if (*top == -1) {
        return -1;  // empty
    }
    return stack[(*top)--];
}

// Enqueue (insert at rear)
void enqueue(int val) {
    push(stack1, &top1, val);
    printf("%d enqueued\n", val);
}

// Dequeue (remove from front)
void dequeue() {
    int val;
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    if (top2 == -1) {
        // Move all from stack1 → stack2
        while (top1 != -1) {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }
    val = pop(stack2, &top2);
    if (val != -1)
        printf("%d dequeued\n", val);
}

// Display queue
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");

    // Front part is in stack2 (top2 to 0)
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    // Rear part is in stack1 (0 to top1)
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Queue using Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
