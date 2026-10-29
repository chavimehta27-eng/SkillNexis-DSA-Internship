#include <iostream>
using namespace std;
int main(){
    int n, swaps = 0;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    if(n < 1 || n > 100){
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\nTotal Swaps: " << swaps;
    return 0;
}
