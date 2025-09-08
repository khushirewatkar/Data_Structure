#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define LEN 100

char undoStack[MAX][LEN];  
char redoStack[MAX][LEN];
int undoTop = -1, redoTop = -1;

char text[LEN] = "";   // current text

// Push onto stack
void push(char stack[][LEN], int *top, char data[]) {
    if (*top < MAX - 1) {
        strcpy(stack[++(*top)], data);
    }
}

// Pop from stack
void pop(char stack[][LEN], int *top, char data[]) {
    if (*top >= 0) {
        strcpy(data, stack[(*top)--]);
    } else {
        strcpy(data, "");
    }
}

void enterText() {
    char newText[LEN];
    printf("Enter new text: ");
    scanf(" %[^\n]", newText);

    // Save current text into undo before changing
    push(undoStack, &undoTop, text);

    strcpy(text, newText);

    // Clear redo stack after new entry
    redoTop = -1;
}

void undo() {
    if (undoTop == -1) {
        printf("Nothing to undo!\n");
        return;
    }
    // Save current state to redo stack
    push(redoStack, &redoTop, text);

    // Restore from undo stack
    pop(undoStack, &undoTop, text);
}

void redo() {
    if (redoTop == -1) {
        printf("Nothing to redo!\n");
        return;
    }
    // Save current state to undo stack
    push(undoStack, &undoTop, text);

    // Restore from redo stack
    pop(redoStack, &redoTop, text);
}

void display() {
    printf("Current Text: %s\n", text);
}4

int main() {
    int choice;
    while (1) {
        printf("\n--- Text Editor ---\n");
        printf("1. Enter Text\n2. Undo\n3. Redo\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enterText(); break;
            case 2: undo(); break;
            case 3: redo(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
