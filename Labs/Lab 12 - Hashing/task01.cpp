#include<iostream>
#include<string>
using namespace std;

int getAverage(string s){
    int a = s[0] - 'A';
    int b = s[s.length()-1] - 'A';
    
    return (a+b)/2;
}

int h(int key, int size){ return key % size; }

int prob(int idx, int size, int i){
    return (idx+i) % size;
}

int main(){
    string names[11] = {"BETA", "RATE", "FREQ", "ALPHA", "MEAN", "SUM", "NUM", "BAR", "WAGE", "PAY", "KAPPA"};

    string hashTable[11];
    
    // inserting
    for(int i = 0; i < 11; i++){
        int avg = getAverage(names[i]);
        int idx = h(avg, 11);

        
        if(hashTable[idx] != ""){
            int j = 1;
            int originalIdx = idx;

            while(true){
                idx = prob(originalIdx, 11, j);

                if(hashTable[idx] == ""){
                    hashTable[idx] = names[i];
                    break;
                }
                
                j++;
                if(j == 11){
                    cout << "Table is full.\n";
                    break;
                }
            }
        } else hashTable[idx] = names[i];
    }

    
    // printing
    for(int i = 0; i < 11; i++){
        if(hashTable[i] == "-1"){
            cout << "[" << i << "] -> empty.\n";
        } else cout << "[" << i << "] -> " << hashTable[i] << "\n";
    }

    
}