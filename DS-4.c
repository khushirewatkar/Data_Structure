#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    struct Song *next;
};

struct Song *head = NULL;

// Insert song at end
void insertSong(char songName[]) {
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, songName);
    if (head == NULL) {
        head = newSong;
        newSong->next = head;
    } else {
        struct Song *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newSong;
        newSong->next = head;
    }
    printf("Song added: %s\n", songName);
}

// Display playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist empty!\n");
        return;
    }
    struct Song *temp = head;
    printf("Playlist: ");
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("(back)\n");
}

// Play songs
void playSongs() {
    if (head == NULL) {
        printf("No songs to play!\n");
        return;
    }
    struct Song *temp = head;
    printf("Playing songs:\n");
    do {
        printf("Now playing: %s\n", temp->name);
        temp = temp->next;
    } while (temp != head);
}

// Search song
void searchSong(char songName[]) {
    if (head == NULL) {
        printf("Playlist empty!\n");
        return;
    }
    struct Song *temp = head;
    int pos = 1;
    do {
        if (strcmp(temp->name, songName) == 0) {
            printf("Song found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Song not found!\n");
}

// Count songs
void countSongs() {
    if (head == NULL) {
        printf("Playlist empty!\n");
        return;
    }
    struct Song *temp = head;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Total songs: %d\n", count);
}

int main() {
    int choice;
    char song[50];

    do {
        printf("\n1.Insert  2.Display  3.Play  4.Search  5.Count  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song name (no spaces): ");
                scanf("%s", song);
                insertSong(song);
                break;
            case 2: displayPlaylist(); break;
            case 3: playSongs(); break;
            case 4:
                printf("Enter song to search: ");
                scanf("%s", song);
                searchSong(song);
                break;
            case 5: countSongs(); break;
            case 6: printf("Exit...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
