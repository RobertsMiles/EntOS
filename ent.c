// TODO
// allow for multiple users
// reset hostname and username
// require password to logon as user
// finish vin
// fix about
// add lisp interpreter
// add color coding
// add file for index of programs that each program adds to to be read by glossary() and welcome()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ent.h"
#include "vin.h"
#include "entish.h"

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
        else if (!strcmp(inputBuffer, "entish")) entish();
        else if (!strcmp(inputBuffer, "clear")) clear();
        else if (!strcmp(inputBuffer, "about")) about();
        else if (!strcmp(inputBuffer, "quit")) return 0;
        else printf("Unknown command: \"%s\"\n", inputBuffer);
    }
}

void printHost() {
    printf("%s:%s", hostnameBuffer, usernameBuffer);
}

void printName(char* name) {
    printf(":%s", name);
}

void printPrompt() {
    printf(" -> ");
}

void clear() {
    system("clear");
}

static void setHostname() {
    FILE* hostname;
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

static void setUsername() {
    FILE* username;
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

static void about() {
    FILE* about;
    char ch;
    about = fopen("root/about", "r");
    while ((ch = fgetc(about)) != EOF) {
        printf("%c", ch);
    }
    fclose(about);
    printf("\n");
}

static void welcome() {
    printf("\nThis is the ENT system. Welcome.\n\n");
}

static void help() {
    printf("Available commands:\n");
    glossary();
}

static void glossary() {
    printf("help\t-\tthis command\n");
    printf("about\t-\tabout the ENT system\n");
    printf("clear\t-\tclear the terminal\n");
    printf("vin\t-\ttext editor\n");
    printf("entish\t-\tbasic RPM interpreter\n");
}