// TODO
// figure out public/private functions per c file (every file should have 1 root and n helpers)

#include <stdio.h>
#include <string.h>
#include "help.h"

int main() {
    char username[9] = "User";
    char hostname[9] = "ENTOS";
    char inputBuffer[99];

    while (1) {
        printf("%s@%s: ", username, hostname);
        scanf("%s", inputBuffer);

        if (!strcmp(inputBuffer, "help")) help();
        else if (!strcmp(inputBuffer, "quit")) return 0;
        else printf("Invalid argument!\n");
    }
}