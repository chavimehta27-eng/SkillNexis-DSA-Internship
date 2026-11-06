#include <bits/stdc++.h>
using namespace std;
class TextEditor{
    string text;
    stack<string> undoStack;
    stack<string> redoStack;
public:
    TextEditor(){
        text = "";
    }
    void typeText(string newText){
        undoStack.push(text);
        text = text + newText;
        while(!redoStack.empty()){
            redoStack.pop();
        }
        cout << "Text added successfully.\n";
    }
    void undo(){
        if(undoStack.empty()){
            cout << "Nothing to undo.\n";
            return;
        }
        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
        cout << "Undo successful.\n";
    }
    void redo(){
        if(redoStack.empty()){
            cout << "Nothing to redo.\n";
            return;
        }
        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
        cout << "Redo successful.\n";
    }
    void display(){
        cout << "\nCurrent Text: " << text << endl;
    }
};
int main(){
    TextEditor editor;
    int choice;
    string input;
    do{
        cout << "\n--- Undo-Redo Text Editor ---\n";
        cout << "1. Type Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display Text\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter text: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                editor.typeText(input);
                break;

            case 2:
                editor.undo();
                break;

            case 3:
                editor.redo();
                break;

            case 4:
                editor.display();
                break;

            case 5:
                cout << "Exiting editor.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}
