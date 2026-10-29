#include <iostream>
using namespace std;

int main() {
    int n, key, pos = -1;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    if(n < 1 || n > 100) {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            pos = i;
            break;
        }
    }

    if(pos != -1) {
        cout << "Element found at position: " << pos + 1;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
