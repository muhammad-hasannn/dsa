/*Social Media Notofications*/

#include<iostream>
#include<string>
using namespace std;

class NotificationStack{
private:
    static const int capacity = 10;
    string notifications[capacity];
    int top = -1;

public:
    void push(string msg){
        if(top == capacity-1){
            cout << "No more notifications can be added.\n";
            return;
        }
        notifications[++top] = msg;
    }

    void pop(){
        if(top == -1){
            cout << "No notification in the stack.\n";
            return;
        }
        top--;
    }

    string peek(){
        return notifications[top];
    }

    bool isEmpty(){ return top == -1; }

    void display(){
        if(top == -1){
            cout << "No notifications to display:(\n";
            return;
        }

        for(int i = top; i >= 0; i--){
            cout << i+1 << ". " << notifications[i] << "\n";
        }
        cout << "\n";
    }

};

int main(){

}