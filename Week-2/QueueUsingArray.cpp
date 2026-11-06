#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Queue{
    int arr[MAX];
    int front, rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int value){
        if (rear == MAX - 1){
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " inserted into queue.\n";
    }
    void dequeue(){
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Deleted element: " << arr[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void peek(){
        if(front == -1){
            cout << "Queue is empty.\n";
        }
        else{
            cout << "Front element: " << arr[front] << endl;
        }
    }
    void display(){
        if(front == -1){
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    int choice, value;
    do {
        cout << "\n--- Queue Using Array ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
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
