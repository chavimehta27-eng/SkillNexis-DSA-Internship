#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    string name;
    string phone;
    Node* left;
    Node* right;
    Node(string n, string p) {
        name = n;
        phone = p;
        left = NULL;
        right = NULL;
    }
};
class ContactDirectory {
    Node* root;
    Node* insert(Node* node, string name, string phone) {
        if (node == NULL) {
            return new Node(name, phone);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, phone);
        }
        else if (name > node->name) {
            node->right = insert(node->right, name, phone);
        }
        else {
            node->phone = phone;
            cout << "Contact updated successfully.\n";
        }
        return node;
    }
    Node* search(Node* node, string name) {
        if(node == NULL || node->name == name) {
            return node;
        }

        if(name < node->name) {
            return search(node->left, name);
        }
        return search(node->right, name);
    }

    Node* findMin(Node* node){
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    Node* deleteContact(Node* node, string name) {
        if (node == NULL) {
            return NULL;
        }
        if(name < node->name){
            node->left = deleteContact(node->left, name);
        }
        else if(name > node->name){
            node->right = deleteContact(node->right, name);
        }
        else{
            if(node->left == NULL){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->name = temp->name;
            node->phone = temp->phone;
            node->right = deleteContact(node->right, temp->name);
        }
        return node;
    }
    void inorder(Node* node){
        if(node == NULL){
            return;
        }
        inorder(node->left);
        cout << "Name: " << node->name
             << " | Phone: " << node->phone << endl;
        inorder(node->right);
    }
public:
    ContactDirectory(){
        root = NULL;
    }
    void insertContact(string name, string phone) {
        root = insert(root, name, phone);
        cout << "Contact inserted successfully.\n";
    }
    void searchContact(string name) {
        Node* result = search(root, name);
        if(result == NULL){
            cout << "Contact not found.\n";
        }
        else{
            cout << "Contact found!\n";
            cout << "Name: " << result->name << endl;
            cout << "Phone: " << result->phone << endl;
        }
    }
    void removeContact(string name) {
        if (search(root, name) == NULL) {
            cout << "Contact not found.\n";
            return;
        }
        root = deleteContact(root, name);
        cout << "Contact deleted successfully.\n";
    }
    void displayContacts(){
        if (root == NULL) {
            cout << "Directory is empty.\n";
            return;
        }
        cout << "\nContacts in alphabetical order:\n";
        inorder(root);
    }
};

int main(){
    ContactDirectory directory;
    int choice;
    string name, phone;
    do {
        cout << "\n--- Contact Directory ---\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display Contacts\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter phone number: ";
                getline(cin, phone);

                directory.insertContact(name, phone);
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> ws;
                getline(cin, name);

                directory.searchContact(name);
                break;

            case 3:
                cout << "Enter name to delete: ";
                cin >> ws;
                getline(cin, name);

                directory.removeContact(name);
                break;

            case 4:
                directory.displayContacts();
                break;

            case 5:
                cout << "Exiting Contact Directory.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
    return 0;
}
