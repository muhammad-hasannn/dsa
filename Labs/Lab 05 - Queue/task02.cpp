/* Ticket Booking System for a Movie Theater */

#include<iostream>
using namespace std;

struct Movie{
    string name;
    int price;
};

const int n = 6;
Movie movies[n];
int f = -1, r = -1;
int currSize = 0;

void enQueue(Movie m){
    if(currSize == n){
        cout << "No more movies can added.\n";
        return;
    }    
    
    if(f == -1 && r == -1){
        f = r = 0;
        movies[r] = m;
        currSize++;
        return;
    }

    r = (r+1)%n;
    movies[r] = m;
    currSize++;    
}

void dequeue() {
    if(currSize == 0){
        cout << "There are no movies in queue.\n";
        return;
    }

    f = (f+1)%n;
    currSize--;
}

void display(){
    if(currSize == 0){
        cout << "No movies in queue to display.\n";
        return;
    }

    int i = f;
    cout << "\n\t*Movies in Queue*\n";
    for(int count = 0; count < currSize; count++){
        cout << movies[i].name << ", " << movies[i].price << "\n";
        i = (i+1)%n;
    }
}

int main(){

    enQueue({"Avatar", 10});
    enQueue({"Inception", 7});
    enQueue({"The Dark Night", 4});
    enQueue({"Intersettler", 8});
    enQueue({"The Matrix", 2});
    enQueue({"The Star Wars", 15});

    cout << "\n";
    display();
    cout << "\n";

    enQueue({"Divergent", 25});
    cout << "\n";

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();
}