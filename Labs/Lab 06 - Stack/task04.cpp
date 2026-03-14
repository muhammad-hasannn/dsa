/*Image Editing*/

#include<iostream>
#include<string>
using namespace std;

class EditTimeline{
private:
    static const int maxEdits = 10;
    string arr[maxEdits];
    int top = -1;

public:
    void addEdit(string s){
        if(top == maxEdits-1){
            cout << "No more edits can be done!\n";
            return;
        }
        arr[++top] = s;
        cout << "Edit added!\n";
    }

    void undoEdit(){
        if(top == -1){
            cout << "No editing is done!\n";
            return;
        }
        top--;
        cout << "Edit deleted successfully!\n";
    }

    void displayEdits(){
        if(top == -1){
            cout << "No editing is done!\n";
            return;
        }

        for(int i = top;i >= 0; i--){
            cout << i+1 << ". " << arr[i] << "\n";
        }
    }
};

int main(){
    EditTimeline editor; 
    int choice = 0;

    cout << "\n***Welcome To Image Editor***\n\n";

    do{
        cout << "\n\t---MENU---\n";
        cout << "1. Add Edit.\n";
        cout << "2. Undo Edit.\n";
        cout << "3. See Edit History.\n";
        cout << "4. Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        cout << "\n";
        if(choice == 1){
            string msg;
            cout << "Enter edit message: ";
            getline(cin, msg);

            editor.addEdit(msg);
        }
        else if(choice == 2){
            editor.undoEdit();
        }
        else if(choice == 3){
            cout << "\n---Edit Hidtory---\n";
            editor.displayEdits();
        }
        else if(choice == 4){
            cout << "Editor closed.\n";
        }
        else cout << "Invalid choice.\n";
    
    }while(choice != 4);
}