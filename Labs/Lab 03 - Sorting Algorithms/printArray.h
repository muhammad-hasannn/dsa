#include<iostream>
#include<string>
using namespace std;


void printIntArray(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " | ";
    cout << "\n";
}

void printStringArray(string s[], int n){
    for(int i = 0; i < n; i++) cout << s[i] << " | ";
    cout << "\n";
}