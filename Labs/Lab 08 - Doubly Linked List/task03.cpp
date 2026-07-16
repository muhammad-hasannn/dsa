#include<iostream>
#include <string>
using namespace std;

struct Song{
    int id;
    string name;
    string singer;
    int year;
};

class Node{
public:
    Song data;
    Node* pre;
    Node* next;

    Node(Song data){
        this->data = data;
        pre = next = nullptr;
    }
};


class MyHitPlaylist{
private:
    Node *head, *tail;

public:
    MyHitPlaylist(){ head = tail = nullptr; }

    // 1. Add new song. Each song will append to end
    void addSong(Song val){
        if(head == nullptr){
            head = tail = new Node(val);
            head->next = head;
            head->pre = head;
            return;
        }

        Node* newNode = new Node(val);

        newNode->pre = tail;
        tail->next = newNode;
        tail = newNode;

        tail->next = head;
        head->pre = tail;
    }

    // 2. Play in backward order
    void playBackward(){
        if(head == nullptr){
            cout << "No songs in playlist to play in backward order.\n";
            return;
        }

        Node* temp = tail;

        cout << "\t---Songs in the playlist---\n";
        do{
            cout << "ID: " << temp->data.id << " | Name: " << temp->data.name << " | Singer: " << temp->data.singer
            << " | Released year: " << temp->data.year << "\n";
            temp = temp->pre;

        }while(temp != tail);
        
    }

    // 3. Circular play back
    void circularPlayBack(){
        if(head == nullptr){
            cout << "No songs in playlist to play.\n";
            return;
        }

        cout << "\nIMPORTANT: To stop press: Ctrl + c\n";
        string startPlaying;
        cout << "Press enter to continue... ";
        cin >> startPlaying;

        Node* temp = head;
        while(temp){
            cout << "Playing... " << temp->data.name << "Singer: " << temp->data.singer << "\n";
            temp = temp->next;
        }
    }

    // 4. Search by year 
    void searchByYear(int target){
        if(head == nullptr){
            cout << "No songs in playlist.\n";
            return;
        }
        cout << "Songs released in " << target << "\n";

        Node* temp = head;
        int count = 1;
        do{
            if(temp->data.year == target){
                cout << count++ << ". Name: " << temp->data.name << ", Singer: " << temp->data.singer << "\n";
            }
            temp = temp->next;
        }while(temp != head);
    }

    // 5. delete from begining
    void deleteFromBegin(){
        if(head == nullptr){
            cout << "No song to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(!head) head = tail = nullptr;
        else{ tail->next = head; head->pre = nullptr; }

        delete temp;
    }
};

int main(){

    MyHitPlaylist playlist;

    Song s1 = {1,"Wake me up","aleemrk",2024};
    Song s2 = {2,"Uljhan","Nabeel Akbar",2022};
    Song s3 = {3,"Kaha tak","Ka$na",2023};
    Song s4 = {4,"Locked Doors","JJ47",2025};
    Song s5 = {5,"Qalam","AHSAN",2022};

    playlist.addSong(s1);
    playlist.addSong(s2);
    playlist.addSong(s3);
    playlist.addSong(s4);
    playlist.addSong(s5);

    cout<<"Backward Playlist\n";
    playlist.playBackward();

    cout<<"\nSearching songs released in 2017\n";
    playlist.searchByYear(2017);

    cout<<"\nDeleting first song\n";
    playlist.deleteFromBegin();

    cout<<"\nBackward Playlist After Deletion\n";
    playlist.playBackward();
    
    playlist.circularPlayBack();

}