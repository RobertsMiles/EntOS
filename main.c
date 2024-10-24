// TODO
// allow for multiple users

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include "vin.h"

char hostnameBuffer[9];
char usernameBuffer[9];

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
        printPrompt();
        scanf("%s", inputBuffer);

        if (!strcmp(inputBuffer, "help")) help();
        else if (!strcmp(inputBuffer, "vin")) vin();

        else if (!strcmp(inputBuffer, "clear")) clear();
        else if (!strcmp(inputBuffer, "quit")) return 0;
        else printf("Unknown command: \"%s\"\n", inputBuffer);
    }
}

void setHostname() {
    FILE* hostname;
    mkdir("root", 0777);
    hostname = fopen("root/hostname", "r");
    if (hostname == NULL) {
        hostname = fopen("root/hostname", "w");
        printf("Hostname: ");
        scanf("%s", hostnameBuffer);
        fprintf(hostname, "%s", hostnameBuffer);
    }
    else {
        fgets(hostnameBuffer, 9, hostname); 
    }
    fclose(hostname);
}

void setUsername() {
    FILE* username;
    mkdir("root", 0777);
    username = fopen("root/username", "r");
    if (username == NULL) {
        username = fopen("root/username", "w");
        printf("Username: ");
        scanf("%s", usernameBuffer);
        fprintf(username, "%s", usernameBuffer);
    }
    else {
        fgets(usernameBuffer, 9, username); 
    }
    fclose(username);
}

void printHost() {
    printf("%s:%s", hostnameBuffer, usernameBuffer);
}

void printName(char* name) {
    printf(":%s", name);
}

void printPrompt() {
    printf(": ");
}

void clear() {
    system("clear");
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