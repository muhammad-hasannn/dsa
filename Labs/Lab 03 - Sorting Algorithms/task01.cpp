/*Analyzing Sales Data*/

#include<iostream>
#include "printArray.h"
using namespace std;

void bubble(int arr[], int n){
    
    for(int i = 0 ; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
        cout << "After "<<i+1<<" pass: ";
        printIntArray(arr, n);
    }
    cout << "\nFinal sorted array: ";
    printIntArray(arr, n);

}

void selection(int arr[], int n){

    for(int i = 0; i < n-1; i++){
        int smallIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[smallIndex] > arr[j]) smallIndex = j;
        }
        swap(arr[i], arr[smallIndex]);

        cout << "After "<<i+1<<" pass: ";
        printIntArray(arr, n);
    }
    cout << "\nFinal sorted array: ";
    printIntArray(arr, n);

}

void insertion(int arr[], int n){
    
    for(int i = 1; i < 5; i++){ //we are considering first element as sorted
        int curr = arr[i];
        int pre = i - 1;

        while(pre >= 0 && arr[pre] > curr){
            arr[pre+1] = arr[pre];
            pre--;
        }
        arr[pre+1] = curr; // placing current element at it's right place

        cout << "After "<<i+1<<" pass: ";
        printIntArray(arr, n);
    }
    cout << "\nFinal sorted array: ";
    printIntArray(arr, n);
}


int main(){
    int sales[10] = {12500, 97000, 8800, 10200, 13040, 7010, 9800, 10150, 12030, 10500};

    cout << "\nOriginal Array: ";
    printIntArray(sales, 10);

    int choice = 0;
    cout << "\nSelect a sorting algorithm.\n";
    cout << "1. Bubble sort.\n";
    cout << "2. Selection sort.\n";
    cout << "3. Insertion sort.\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
        cout << "\n\t\t\tBubble Sort:\n";
        bubble(sales, 10);
        break;

        case 2:
        cout << "\n\t\t\tSelection Sort:\n";
        selection(sales, 10);
        break;

        case 3:
        cout << "\n\t\t\tInsertion Sort:\n";
        insertion(sales, 10);
        break;

        default:
        cout << "Inavlid choice!\n";
        break;
    }
}