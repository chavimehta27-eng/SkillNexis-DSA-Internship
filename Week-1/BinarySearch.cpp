#include <iostream>
using namespace std;

int main(){
    int n, key;
    int arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    if(n < 1 || n > 100){
        cout << "Invalid array size";
        return 0;
    }
  
    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;
    int pos = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == key){
            pos = mid;
            break;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(pos != -1){
        cout << "Element found at position: " << pos + 1;
    }
    else{
        cout << "Element not found";
    }
    return 0;
}
