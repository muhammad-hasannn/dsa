/* I have misinterpreted the question, the role of country and captail is reversed. */

#include<iostream>
#include<string>
using namespace std;

#define TABLE_SIZE 10

int myHash(int key) { return key % TABLE_SIZE; }

int prob(int index, int i) { return (index+i) % TABLE_SIZE; }

// 1. Insert
void insert(string hashTable[][2], string country, string capital){
    int idx = myHash(capital.length());

    if(hashTable[idx][0] != ""){
        int j = 1;
        int originalIdx = idx;

        while(j < TABLE_SIZE){
            idx = prob(originalIdx, j);

            if(hashTable[idx][0] == ""){
                hashTable[idx][0] = country;
                hashTable[idx][1] = capital;
                break;
            }
            j++;
        }

        if(j == TABLE_SIZE){
            cout << "Table is full.\n";
        }

    } else {
        hashTable[idx][0] = country;
        hashTable[idx][1] = capital;
    }
}

// 2. Delete a country from the hash table
bool deleteCountry(string table[][2], string country, string capital){
    int idx = myHash(capital.length());

    if(table[idx][0] != country){
        int j = 1;

        while(j < TABLE_SIZE){
            idx = prob(idx, j);

            if(table[idx][0] == country){
                table[idx][0] = "";
                table[idx][1] = "";
                return true;
            }
            j++;
        }

        if(j == TABLE_SIZE){
            cout << "Country not found in table.\n";
            return false;
        }
    } else {
        table[idx][0] = "";
        table[idx][1] = "";
        return true;
    }
    return false;
}

// 3. Update a capital using its country name
void update(string table[][2], string country, string oldCapital, string newCapital){
    // first I'll delete, then will re insert it as per capital

    if(deleteCountry(table, country, oldCapital)) insert(table, country, newCapital);
}

// 4. Search for country by captital
void search(string table[][2], string capital){
    int idx = myHash(capital.length());

    if(table[idx][1] != capital){
        int j = 1;
        while(j < TABLE_SIZE){
            idx = prob(idx, j);

            if(table[idx][1] == capital){
                cout << "Name: " << table[idx][0] << "\n";
                cout << "Capital: " << table[idx][1] << "\n";
                return;
            }
            j++;            
        }
        if(j == TABLE_SIZE){
            cout << "Country not found.\n";
            return;
        }
    }
    else{
        cout << "Name: " << table[idx][0] << "\n";
        cout << "Capital: " << table[idx][1] << "\n";
        return;
    }
}

int main(){

    string hashTable[TABLE_SIZE][2];

    // inserting values
    insert(hashTable, "United States", "Washington DC");
    insert(hashTable, "Brazil", "Brasilia");
    insert(hashTable, "Japan", "Tokyo");
    insert(hashTable, "Germany", "Berlin");
    insert(hashTable, "Pakistan", "Islamabad");
    insert(hashTable, "Argentina", "Buenos Aires");
    insert(hashTable, "Australia", "Canberra");

    // printing table
    cout << "Initial Hash Table:\n\n";

    for(int i = 0; i < TABLE_SIZE; i++){

        cout << "[" << i << "] -> ";

        if(hashTable[i][0] == ""){
            cout << "empty\n";
        }
        else{
            cout << hashTable[i][0] << " : " << hashTable[i][1] << "\n";
        }
    }

    // searching
    cout << "\nSearching for Japan:\n";
    search(hashTable, "Tokyo");

    // updating
    cout << "\nUpdating capital of Brazil...\n";
    update(hashTable, "Brazil", "Brasilia", "Rio de Janeiro");

    // deleting
    cout << "\nDeleting Germany...\n";

    if(deleteCountry(hashTable, "Germany", "Berlin")){
        cout << "Germany deleted successfully.\n";
    }

    // final table
    cout << "\nFinal Hash Table:\n\n";

    for(int i = 0; i < TABLE_SIZE; i++){

        cout << "[" << i << "] -> ";

        if(hashTable[i][0] == ""){
            cout << "empty\n";
        }
        else{
            cout << hashTable[i][0] << " : " << hashTable[i][1] << "\n";
        }
    }
}