#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>

#define MAX_NODES 20


typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    else if (val < root->value) {
        root->left = insertNode(root->left, val);
    }
    else {
        root->right = insertNode(root->right, val);
    }
    return root;
}


void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}


int sumEvenNodes(Node* root, std ::vector<int> buffer) {
    int sum = 0;
    for (auto val : buffer) {
        if ((val & 1) == 0) {
            sum = sum + val; }
    }
    return sum;
}


int countByLoop(std ::vector<int> buffer, int size) {
    int total = 0;
    for (int i = 0; i < size; i ++) {  
        if (buffer[i] != -1) {
            total = total + 1;
        }
    }
    return total;
}

int main() {
    std ::vector<int> values = {15, 6, 23, 4, 7, 71, 5, 50, 12, 10, 35, 17, 26, 80, 1, 14, 3, 2, 8, 9};
    Node* root = NULL;
    int idx = 0;

    
    while (idx < MAX_NODES) {
        root = insertNode(root, values[idx]);
        idx ++;
    }
    printf("Binary Search Tree created.\n");

    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    
    printf("Checking parity of values:\n");
    for (auto v : values) {
        if ((v & 1) == 0) {
            printf("%d is Even\n", v);
        }
        else {
            printf("%d is Odd\n", v);
        }
    }

    
    int count = countByLoop(values, MAX_NODES);
    printf("Number of valid values: %d\n", count);

    
    int sumEven = sumEvenNodes(root, values);
    printf("Sum of even values: %d\n", sumEven);

    return 0;
}

