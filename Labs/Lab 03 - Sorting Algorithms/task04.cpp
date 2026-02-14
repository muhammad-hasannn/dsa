/*Organizing Cars by Type and Price*/

#include<iostream>
#include<string>
#include "printArray.h"
using namespace std;

struct Car{
    string name;
    float price;
    string type;
};

void printArray(Car c[], int n){
    for(int i = 0; i < n; i++){
        cout << "Car: " << c[i].name << ", Price: $" << c[i].price << ", Type: " << c[i].type << "\n";
    }
}

void selection(Car c[], int n, string byWhatToSort){

    for(int i = 0; i < n-1; i++){
        int smallIndex = i;

        for(int j = i+1; j < n; j++){
            if(byWhatToSort == "price"){
                if(c[j].price < c[smallIndex].price)
                    smallIndex = j;
            }
            else{ // type
                if(c[j].type < c[smallIndex].type)
                    smallIndex = j;
            }
        }

        swap(c[i], c[smallIndex]);
    }
}

int main(){

    Car cars[5] = {
        {"Mehran", 48.25, "Sedan"},
        {"Cultus", 72.00, "SUV"},
        {"Civic", 130.50, "Convertible"},
        {"Corola", 53.40, "Sedan"},
        {"Alto", 110.75, "SUV"}
    };

    int n = 5;

    cout << "Original List of Cars:\n";
    printArray(cars, n);

    selection(cars, n, "type");
    cout << "\nSorted By Type:\n";
    printArray(cars, n);

    selection(cars, n, "price");
    cout << "\nSorted By Price:\n";
    printArray(cars, n);

    return 0;
}
