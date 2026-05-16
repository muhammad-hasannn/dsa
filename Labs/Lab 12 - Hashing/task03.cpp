#include<iostream>
using namespace std;

#define TABLE_SIZE 11

struct Fruit{
    string name;
    float price;
};

int myHash(string key){
    return (key.length() % TABLE_SIZE);
}

int prob(int hashIndex, int i){
    return ((hashIndex + (i*i)) % TABLE_SIZE);
}

void insertFruit(Fruit table[], Fruit f){
    int idx = myHash(f.name);

    if(table[idx].name != ""){
        int j = 1;
        int originalIdx = idx;

        while(j < TABLE_SIZE){
            idx = prob(originalIdx, j);

            if(table[idx].name == ""){
                table[idx] = f;
                return;
            }
            j++;
        }

        if(j == TABLE_SIZE){
            cout << "Table is full.\n";
            return;
        }

    } else table[idx] = f;
}

int main(){
    Fruit fruitTable[TABLE_SIZE] = {}; // the empty curly braces will initialize it with: "" & 0.00

    // printing initial state
    for(int i = 0; i < TABLE_SIZE; i++){
        if(fruitTable[i].name == ""){
            cout << "[" << i << "] -> empty.\n"; 
        } else cout << "[" << i << "] -> " << fruitTable[i].name << ", " << fruitTable[i].price << "\n"; 
    }

    insertFruit(fruitTable, {"Mango", 100.0});
    insertFruit(fruitTable, {"Apple", 100.0});
    insertFruit(fruitTable, {"Orange", 100.0});
    insertFruit(fruitTable, {"Banana", 100.0});
    insertFruit(fruitTable, {"Water Melon", 100.0});

    
    cout << "\n";
    for(int i = 0; i < TABLE_SIZE; i++){
        if(fruitTable[i].name == ""){
            cout << "[" << i << "] -> empty.\n"; 
        } else cout << "[" << i << "] -> " << fruitTable[i].name << ", " << fruitTable[i].price << "\n"; 
    }
}