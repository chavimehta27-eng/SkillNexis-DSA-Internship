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
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverseUsingStack(){
        if(head == NULL){
            cout << "List is empty.\n";
            return;
        }
        stack<int> s;
        Node* temp = head;
        while (temp != NULL){
            s.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL){
            temp->data = s.top();
            s.pop();
            temp = temp->next;
        }
        cout << "Linked list reversed successfully.\n";
    }
    void display(){
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    ~LinkedList(){
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main(){
    LinkedList list;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        list.insertAtEnd(value);
    }
    cout << "\nOriginal ";
    list.display();
    list.reverseUsingStack();
    cout << "Reversed ";
    list.display();
    return 0;
}
