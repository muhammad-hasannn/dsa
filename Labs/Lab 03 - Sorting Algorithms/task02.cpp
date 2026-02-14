/*File Management */

#include<iostream>
#include<string>
#include "printArray.h"
using namespace std;

void bubble(string s[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n-i-1; j++){
            if(s[j] > s[j+1]) swap(s[j], s[j+1]);
        }
    }
}

int main(){
    string files[5] = {"Report.docx", "Photo.jpg", "Presentation.pptx", "notes.txt", "Archives.zip"};

    cout << "\nFiles before sorting: ";
    printStringArray(files, 5);

    bubble(files, 5);

    cout << "\nFiles after sorting: ";
    printStringArray(files, 5);
}