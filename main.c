// TODO
// figure out public/private functions per c file (every file should have 1 root and n helpers)

#include <stdio.h>
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

void printName(char* name) {
    printf("%s -> ", name);
}

static void welcome() {
    printf("\nThis is the ENT operating system. Welcome.\n\n");
}

static void help() {
    printf("This is the ENT Operating System, a completely impractical suite of software that I am writing for fun. ENT is a recursive acronym that stands for \"ENT's Not TempleOS\".\n");
    printGlossary();
}

static void printGlossary() {
    printf("TODO\n");
}