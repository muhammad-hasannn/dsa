/*Gem Hunt in a Treasure Chest*/

#include<iostream>
#include<string>
using namespace std;


int main(){
    string gemChest[10] = {"Sapphire", "Ruby", "Diamond", "Emerald", "Ruby", "Topaz", "Sapphire", "Amethyst", "Diamond", "Ruby"};
    string targetGem;

    cout << "Welcome to GemQuest!" << endl;
    cout << "Enter the name of gem you seek: ";
    getline(cin, targetGem);

    int count = 0;
    for(int i = 0; i < 10; i++){
        if(gemChest[i] == targetGem) count++;
    }

    if(count > 0) cout << "\nYou found "<<count<<" "<<targetGem<< " in the magical GemChest!" << endl;
    else cout << "\nNot found!" << endl;

}