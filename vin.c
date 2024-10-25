#include <stdio.h>
#include <string.h>
#include "ent.h"
#include "vin.h"

static char name[9] = "Vin";

void vin() {
    welcome();
    input();
}

static void welcome() {
    printf("\nvin - Vi INjured, not a programmer's text editor.\n\n");
}

static void help() {
    printf("TODO\n");
}

static void input() {
    char inputBuffer[9];

    while (1) {
        printHost();
        printName(name);
        printPrompt();
        scanf("%s", inputBuffer);

        if (!strcmp(inputBuffer, "help")) help();
        else if (!strcmp(inputBuffer, ""));



        else if (!strcmp(inputBuffer, "quit")) return;
        else printf("Unknown command: \"%s\"\n", inputBuffer);
    }
}