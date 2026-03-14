/*Syntax Checker*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOpening(char c){
    return c == '(' || c == '[' || c == '{'; 
}

char getOpeningBr(char c){
    if(c == ')') return '(';
    if(c == ']') return '[';
    return '{';
}

bool isValid(string s){
    stack<char> st;
    int openCount = 0, closeCount = 0;    

    for(int i = 0; i < s.length(); i++){  
        
        // if it is opening bracket push it into stack
        if(isOpening(s[i])){
            st.push(s[i]);
            openCount++;
        }

        // it is a closing bracket
        else{

            // we got the closing bracket, but there's no opening bracket before it
            if(st.empty()) return false;

            // get the openeing bracket of it, and compare it with the top of stack if it is same
            if(getOpeningBr(s[i]) != st.top()){
                return false; // if not, terminating
            }
            else{
                st.pop();
                closeCount++;
            }

        }
    }
    return openCount == closeCount;
}

int main(){    

    cout << isValid("");

}

