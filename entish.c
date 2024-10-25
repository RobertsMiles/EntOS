#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ent.h"
#include "entish.h"

static char name[9] = "entish";

void entish() {
    welcome();
    input();
}

static void welcome() {
    printf("\nentish - A basic RPN interpreter\n\n");
}

static void help() {
    printf("TODO\n");
}

static void input() {
    // input
    // push input to stack
    // evaluate if input is operator
    // if so, pop last three from stack
    // push resultant to stack

    char inputBuffer[99];
    Node* topNode = NULL;

    while (1) {
        printHost();
        printName(name);
        printPrompt();
        while (1) {
            scanf(" %s", inputBuffer);

            if (!strcmp(inputBuffer, "quit")) return;
            else if (!strcmp(inputBuffer, "=")) {
                printf("%d\n", topNode->value);
                topNode = freeStack(topNode);
                break;
            }
            else if (!strcmp(inputBuffer, "+")) topNode = add(topNode);
            else if (!strcmp(inputBuffer, "-")) topNode = subtract(topNode);
            else if (!strcmp(inputBuffer, "*")) topNode = multiply(topNode);
            else if (!strcmp(inputBuffer, "/")) topNode = divide(topNode);
            else if (!strcmp(inputBuffer, "%")) topNode = modulus(topNode);
            else topNode = push(topNode, atoi(inputBuffer));
        }
    }
}

static Node* freeStack(Node* topNode) {
    while (topNode != NULL) {
        Node* newTopNode = topNode->lastNode;
        free(topNode);
        topNode = newTopNode;
    }
    return topNode;
}

static Node* push(Node* topNode, int input) {
    Node* newTopNode = (Node*) malloc(sizeof(Node));
    newTopNode->value = input;
    newTopNode->lastNode = topNode;
    return newTopNode;
}

static Node* add(Node* topNode) {
    Node* newTopNode = topNode->lastNode;
    newTopNode->value += topNode->value;
    free(topNode);
    return newTopNode;
}

static Node* subtract(Node* topNode) {
    Node* newTopNode = topNode->lastNode;
    newTopNode->value -= topNode->value;
    free(topNode);
    return newTopNode;
}

static Node* multiply(Node* topNode) {
    Node* newTopNode = topNode->lastNode;
    newTopNode->value *= topNode->value;
    free(topNode);
    return newTopNode;
}

static Node* divide(Node* topNode) {
    Node* newTopNode = topNode->lastNode;
    newTopNode->value /= topNode->value;
    free(topNode);
    return newTopNode;
}

static Node* modulus(Node* topNode) {
    Node* newTopNode = topNode->lastNode;
    newTopNode->value %= topNode->value;
    free(topNode);
    return newTopNode;
}