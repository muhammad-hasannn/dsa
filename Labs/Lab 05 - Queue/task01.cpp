/* Efficient Package Management: Emily's Logistics Queue System */

#include<iostream>
using namespace std;

const int n = 6;
int packages[n];
int f = -1, r = -1;

void enQueue(int val){
    if(r == n-1){
        cout << "Queue is full!\n";
        return;
    }

    if(f == -1){
        f = 0, r++;
        packages[r] = val;
        return;
    }

    r++;
    packages[r] = val;
    return;
}

void deQueue(){
    if(f == -1){
        cout << "Queue is empty!\n";
        return;
    }

    if(f == r+1){
        cout << "Once upon a time queue was full, but right now it's empty!\n";
        return;
    }

    cout << "Deleting: " << packages[f] << "\n";
    f++;
    return;
}

void display(){
    cout << "Current Queue: ";
    for(int i = f; i <= r; i++) cout << packages[i] << " ";
    cout << "\n";
    return;
}

int main(){
    
    enQueue(10);
    enQueue(7);     
    enQueue(4);     
    enQueue(8);     
    enQueue(2);     
    enQueue(15);
    
    display();

    enQueue(25);

    deQueue();

    display();
}