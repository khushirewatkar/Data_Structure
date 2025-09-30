#include <stdio.h>
#define SIZE 5

int hash(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index = hash(key);

    while (table[index] != -1)
    {
        index = (index + 1) % SIZE;
    }
    table[index] = key;
}

void display(int table[])
{
    printf("\n---HASH TABLE-----\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("index %d : %d\n", i, table[i]);
    }
}

int main()
{
    int hashTable[SIZE];
    int keys[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        insert(hashTable, keys[i]);
    }
    display(hashTable);

    return 0;
}
