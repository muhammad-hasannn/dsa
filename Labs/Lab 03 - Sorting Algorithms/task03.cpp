/*Laundry Clothes Sorting*/

#include<iostream>
using namespace std;

void insertion(char c[], int n){
    
    for(int i = 1; i < 5; i++){
        int curr = c[i];
        int pre = i - 1;

        while(pre >= 0 && c[pre] < curr){
            c[pre+1] = c[pre];
            pre--;
        }
        c[pre+1] = curr;        
    }    
}

int main(){
    char colors[5] = {'A', 'H', 'Y', 'C', 'Z'};

    cout << "\nColors before sorting: ";
    for(int i = 0; i < 5; i++) cout << colors[i] << " | ";
    cout << "\n";

    insertion(colors, 5);

    cout << "\nColors after sorting: ";
    for(int i = 0; i < 5; i++) cout << colors[i] << " | ";
    cout << "\n";
}