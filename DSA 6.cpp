#include <iostream>
using namespace std;

// Node structure for the threaded binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;  // Flag to check if the right pointer is a thread or a regular right child
    Node* nullptr ;
    Node(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

// Function to insert a node into the threaded binary tree
Node* insert(Node* root, int value) {
    if (!root)
        return new Node(value);

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        if (!root->right || root->isThreaded) {
            // If there is no right child or the right child is a thread
            Node* newNode = new Node(value);
            newNode->right = root->right;
            newNode->isThreaded = true;
            root->right = newNode;
            root->isThreaded = false;
        } else {
            // If there is a right child, recursively insert to the right subtree
            root->right = insert(root->right, value);
        }
    }

    return root;
}

// Function to perform in-order traversal of the threaded binary tree
void inOrderTraversal(Node* root) {
    Node* current = root;

    while (current) {
        // Find the leftmost node
        while (current->left) {
            current = current->left;
        }

        // Print the current node
        cout << current->data << " ";

        // Traverse using threads or move to the right child
        while (current->isThreaded) {
            current = current->right;
            cout << current->data << " ";
        }

        // Move to the right child
        current = current->right;
    }
}

// Function to perform pre-order traversal of the threaded binary tree
void preOrderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        if (!root->isThreaded) {
            preOrderTraversal(root->right);
        }
    }
}

int main() {
    Node* root;

    // Insert nodes into the threaded binary tree
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);

    // Perform in-order traversal
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Perform pre-order traversal
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}

