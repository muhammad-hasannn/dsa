#include<iostream>
using namespace std;

const int n = 10;
int customers[n];
int f = -1, r = -1;
int currSize = 0;

void enqueue(int customerNumber){
    if(currSize == n){
        cout << "No more customers can be added.\n";
        return;
    }

    if(f == -1 & r == -1){
        f = r = 0;
        customers[r] = customerNumber;
        currSize++;
        return; 
    }

    r = (r+1)%n;
    customers[r] = customerNumber;
    currSize++;
}

void dequeue(){
    if(currSize == 0){
        cout << "There are no customers in queue.\n";
        return;
    }

    f = (f+1)%n;
    currSize--;
}

void display(){
    if(currSize == 0){
        cout << "No customers in queue to display.\n";
        return;
    }

    int i = f;
    cout << "\n\t*Customers in Queue*\n";
    for(int count = 0; count < currSize; count++){
        cout << customers[i] << " ";
        i = (i+1)%n;
    }
    cout << "\n";
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);

    cout << "\n";
    display();

    cout << "\n";
    enqueue(11);

    dequeue();
    dequeue();
    dequeue();

    cout << "\n";
    display();
}