/*Event Scheduling System*/

#include<iostream>
#include<string>
using namespace std;

struct Event{
    string name, date;
};

Event events[10] = {
    {"Seminar", "1-09-2024"},
    {"Food Festival", "3-09-2024"},
    {"Concert", "5-09-2024"},
    {"Trade Show", "11-09-2024"},
    {"Birthday", "18-09-2024" },
    {"Workshop", "19-09-2024"},
    {"Wedding Anniversary", "21-09-2024"},
    {"Graduation Ceremony", "23-09-2024"}
};
int n = 10;

void insertEvent(string name, string date, int id){
    // first of all shifting
    for(int i = n-1; i > id;  i--){
        events[i].name = events[i-1].name;
        events[i].date = events[i-1].date;
    }

    // inserting
    events[id].name = name;
    events[id].date = date;
}

void deleteEvent(int id){
    for(int i = id; i < n-1; i++){
        events[i].name = events[i+1].name;
        events[i].date = events[i+1].date;
    }

    events[n-1].name = "";
    events[n-1].name = "";
}

int main(){

    cout << "***Original Schedule***" << endl << endl;
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << events[i].name << " | " << events[i].date << endl;
    }

    // a.	Insert a new event “Orientation” date: 10-09-2024
    insertEvent("Orientation", "10-09-2024", 3);

    cout << "\n***After adding an Orientation***" << endl << endl;
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << events[i].name << " | " << events[i].date << endl;
    }

    // b.	Delete the event of Trade Show from list.
    deleteEvent(4);
    cout << "\n***After deleting Trade Show***" << endl << endl;
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << events[i].name << " | " << events[i].date << endl;
    }    
}