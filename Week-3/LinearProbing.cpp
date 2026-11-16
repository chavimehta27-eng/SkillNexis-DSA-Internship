#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
class HashTable {
    int table[SIZE];
public:
    HashTable(){
        for (int i=0; i<SIZE; i++) {
            table[i] = -1;
        }
    }
    int hashFunction(int key){
        return key % SIZE;
    }
    void insert(int key){
        int index = hashFunction(key);
        for(int i= 0; i< SIZE; i++){
            int pos = (index + i) % SIZE;
            if(table[pos] == -1){
                table[pos] = key;
                cout << key << " inserted at index "
                     << pos << endl;
                return;
            }
        }
        cout << "Hash table is full!\n";
    }
    void display() {
        cout << "\nHash Table:\n";
        for(int i= 0; i< SIZE; i++){
            cout << i << " : ";
            if(table[i] == -1){
                cout << "Empty";
            }else{
                cout << table[i];
            }
            cout << endl;
        }
    }
};
int main(){
    HashTable h;
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i= 0; i < n; i++){
        cin >> key;
        h.insert(key);
    }
    h.display();
    return 0;
}
