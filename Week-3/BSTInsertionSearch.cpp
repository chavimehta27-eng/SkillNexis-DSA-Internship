#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BST {
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }
    bool search(Node* node, int key) {
        if (node == NULL) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        if (key < node->data) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }
public:
    BST() {
        root = NULL;
    }
    void insertValue(int value) {
        root = insert(root, value);
    }
    void searchValue(int key) {
        if (search(root, key)) {
            cout << key << " found in BST.\n";
        }
        else {
            cout << key << " not found in BST.\n";
        }
    }
};

int main() {
    BST tree;
    int n, value, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insertValue(value);
    }

    cout << "Enter value to search: ";
    cin >> key;
    tree.searchValue(key);
    return 0;
}
