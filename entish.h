typedef struct Node {
    int value;
    struct Node* lastNode;
} Node;

void entish();

static void welcome();

static void help();

static void input();

static Node* freeStack(Node* topNode);

static Node* push(Node* topNode, int inputBuffer);

static Node* add(Node* topNode);

static Node* subtract(Node* topNode);

static Node* multiply(Node* topNode);

static Node* divide(Node* topNode);

static Node* modulus(Node* topNode);