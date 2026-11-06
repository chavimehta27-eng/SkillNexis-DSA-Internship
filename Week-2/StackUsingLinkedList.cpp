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
class Stack{
    Node* top;
public:
    Stack(){
        top = NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack.\n";
    }
    void pop(){
        if (top == NULL){
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        cout << "Deleted element: " << top->data << endl;
        top = top->next;
        delete temp;
    }
    void peek(){
        if (top == NULL){
            cout << "Stack is empty.\n";
        }
        else{
            cout << "Top element: " << top->data << endl;
        }
    }
    void display(){
        if (top == NULL){
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Stack(){
        while (top != NULL){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main(){
    Stack s;
    int choice, value;
    do{
        cout << "\n--- Stack Using Linked List ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }while (choice != 5);
    return 0;
}
