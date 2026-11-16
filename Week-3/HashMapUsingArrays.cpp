#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
class HashMap{
    int keys[SIZE];
    int values[SIZE];
    bool occupied[SIZE];
public:
    HashMap(){
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }
    int hashFunction(int key){
        return key % SIZE;
    }
    void insert(int key, int value){
        int index = hashFunction(key);
        for(int i = 0; i < SIZE; i++){
            int pos = (index + i) % SIZE;
          
            if(!occupied[pos] || keys[pos] == key){
                keys[pos] = key;
                values[pos] = value;
                occupied[pos] = true;

                cout << "Key-value pair inserted.\n";
                return;
            }
        }
        cout << "HashMap is full!\n";
    }
    void search(int key){
        int index = hashFunction(key);
        for(int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;
            if(!occupied[pos]) {
                break;
            }
            if(keys[pos] == key){
                cout << "Value: " << values[pos] << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }
    void display(){
        cout << "\nHashMap:\n";
        for(int i = 0; i < SIZE; i++){
            cout << i << " : ";
            if(occupied[i]){
                cout << keys[i] << " -> " << values[i];
            }else{
                cout << "Empty";
            }
            cout << endl;
        }
    }
};

int main(){
    HashMap h;
    int choice, key, value;
    do {
        cout << "\n--- HashMap Using Arrays ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter key: ";
                cin >> key;

                cout << "Enter value: ";
                cin >> value;

                h.insert(key, value);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                h.search(key);
                break;

            case 3:
                h.display();
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);
    return 0;
}
