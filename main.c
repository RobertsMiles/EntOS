// TODO
// figure out public/private functions per c file (every file should have 1 root and n helpers)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "vin.h"

char hostname[9];
char username[9];

int main() {
    char inputBuffer[99];

    // gather info about system
    setHostname();
    setUsername();

    // Print welcome message on startup
    welcome();

    // main input loop
    while (1) {
        printHost();
        scanf("%s", inputBuffer);

        if (!strcmp(inputBuffer, "help")) help();
        else if (!strcmp(inputBuffer, "vin")) vin();

        else if (!strcmp(inputBuffer, "clear")) clear();
        else if (!strcmp(inputBuffer, "quit")) return 0;
        else printf("Unknown command: \"%s\"\n", inputBuffer);
    }
}

void setHostname() {
    printf("Hostname: ");
    scanf("%s", hostname);
}

void setUsername() {
    printf("Username: ");
    scanf("%s", username);
}

void printHost() {
    printf("%s:%s -> ", hostname, username);
}

void clear() {
    system("clear");
}

void printName(char* name) {
    printf("%s -> ", name);
}

static void welcome() {
    printf("\nThis is the ENT operating system. Welcome.\n\n");
}

static void help() {
    printf("\nAvailable commands:\n");
    printGlossary();
}

static void printGlossary() {
    printf("help\t-\tthis command\n");
    printf("clear\t-\tclears terminal\n");
    printf("vin\t-\ttext editor\n");
    printf("\n");
}