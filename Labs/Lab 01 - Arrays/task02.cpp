/*Priority Shift in Amusement Park*/

#include<iostream>
#include<string>
using namespace std;

void rightRotate(string names[], int n){
    string last = names[n-1];

    // rotating
    for(int i = n-1; i > 0; i--) names[i] = names[i-1];

    names[0] = last;
}

int main(){
    string names[5];

    cout << "Enter names: " << endl;
    for(int i = 0; i < 5; i++){
        cout << i+1 << ": ";
        getline(cin, names[i]);
    }

    cout << "\nOriginal line: ";
    for(string s : names) cout << s << " ";
    cout << endl;

    rightRotate(names, 5);

    cout << "Updated line: ";
    for(string s : names) cout << s << " ";
    cout << endl;
}