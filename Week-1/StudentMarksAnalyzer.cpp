#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, marks[100], sum = 0;
    cout << "===== STUDENT MARKS ANALYZER =====\n";
    cout << "Enter number of students: ";
    cin >> n;

    if(n < 1 || n > 100){
        cout << "Invalid number of students!";
        return 0;
    }

    for(int i = 0; i < n; i++){
        cout << "Enter marks of Student " << i + 1 << ": ";
        cin >> marks[i];
        if(marks[i] < 0 || marks[i] > 100){
            cout << "Invalid marks!";
            return 0;
        }
        sum += marks[i];
    }

    double average = (double)sum / n;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++) {
            if(marks[j] < marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "\nMarks in Descending Order: ";
    for(int i = 0; i < n; i++){
        cout << marks[i] << " ";
    }

    cout << "\n\nTop 3 Marks:\n";
    int top = (n < 3) ? n : 3;
    for(int i = 0; i < top; i++){
        cout << "Rank " << i + 1 << ": "
             << marks[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Marks: " << average;
    cout << "\n\n===== ANALYSIS COMPLETE =====";
    return 0;
}
