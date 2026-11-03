#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully!\n";
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node inserted successfully!\n";
    }

    // Delete from beginning
    void deleteFromBeginning(){
        if (head == NULL){
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted successfully!\n";
    }

    // Delete from end
    void deleteFromEnd(){
        if (head == NULL){
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Node deleted successfully!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~LinkedList(){
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;
    do {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                list.deleteFromBeginning();
                break;

            case 4:
                list.deleteFromEnd();
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);
    return 0;
}
