/*Limca flavor finder*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string flavors[5] = {"Classic Lemon", "Mint Splash", "Citrus Zing", "Lime & Ginger", "Masala FIzz"};

    string targetFlavor;
    cout << "Enter flavor to find: ";
    getline(cin, targetFlavor);

    for(int i = 0; i < 5; i++){
        if(targetFlavor == flavors[i]){
            cout << "\nFlavor Found." << endl;
            return 0;
        }
    }
    cout << "\n" << targetFlavor << " is not currently offered." << endl;
}