/*Javelin Throw Score Tracking*/

#include<iostream>
using namespace std;

class Player{
private:
    static const int turns = 3;
    int scores[turns];
    int top = -1;

public:
    void push(int val){
        if(top == turns-1){
            cout << "No more distance can be recorded.\n";
            return;
        }
        scores[++top] = val;
    }

    int seeTop(){ return scores[top]; }
};

int main(){
    Player pa, pb;    
    int paScore = 0, pbScore = 0;

    for(int i = 0; i < 3; i++){
        int input = 0;

        cout << "Enter distance for player 1: ";
        cin >> input;
        pa.push(input);

        cout << "Enter distance for player 2: ";
        cin >> input;
        pb.push(input);

        if(pa.seeTop() > pb.seeTop()){
            cout << "\nIn round " <<i+1<< ", Player A's throw was longest with a distance of " << pa.seeTop() << "\n\n";
            paScore++;
        }
        else if(pb.seeTop() > pa.seeTop()){
           cout << "\nIn round " <<i+1<< ", Player B's throw was longest with a distance of " << pb.seeTop() << "\n\n";
           pbScore++; 
        }
        else cout << "\nIn round " <<i+1<< " both player have same throwing distance.\n\n";
    }

    // display winner
    cout << "\n\t\t---RESULT---\n";
    if(paScore > pbScore) cout << "Player A is winner with having " << paScore << " throw(s) longeer than player B.\n";
    else if(pbScore > paScore) cout << "Player B is winner with having " << pbScore << " throw(s) longeer than player A.\n";
    else cout << "Both player have same score.\n";    
}