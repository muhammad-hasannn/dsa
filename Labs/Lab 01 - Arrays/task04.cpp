#include<iostream>
using namespace std;


int main(){
    
    int prices[3][3];

    cout << "Enter values: " << endl;
    for(int i = 0; i < 3; i++){
        cout << "Row " << i+1 << ": " << endl;
        for(int j = 0; j < 3; j++){
            cout << "\tColoumn " << j+1 << ": ";
            cin >> prices[i][j];
        }
    }

    cout << "\nOriginal Matrix: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << prices[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // taking transpose
    int tPrices[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tPrices[i][j] = prices[j][i];
        }
    }

    cout << "\nAfter Transpose: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << tPrices[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}