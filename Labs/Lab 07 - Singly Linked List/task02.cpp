/*Reading Activity Log*/

#include<iostream>
using namespace std;

struct Book{
    string title;
    string genre;
    int time;
};


class Node{
public:
    Book data;
    Node* next;

    Node(Book data){
        this->data = data;
        next = nullptr;
    }
};


class ReadingActivityLog{
private:
    Node* head;

public:
    ReadingActivityLog(){ head = nullptr; }

    void addBook(Book data){
        if(head == nullptr){
            head = new Node(data);
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void displayRecentBooks(){
        if(head == nullptr){
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while(temp){
            cout << "Title: " << temp->data.title << " | Genre: " << temp->data.genre << " | Time: " << temp->data.time << "\n";
            temp = temp->next;
        }
    }

    void deleteBook(){
        if(head == nullptr){
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = temp->next;
        delete temp;

    }
};

int main(){
    ReadingActivityLog obj;

    obj.addBook({"first book", "reality", 1234});
    obj.addBook({"second book", "horror", 1234});
    obj.addBook({"third book", "fiction", 1234});
    obj.addBook({"fourth book", "fantasy", 1234});
    obj.addBook({"fifth book", "thriller", 1234});

    cout << "\n\tAll books in the list\n";
    obj.displayRecentBooks();

    obj.deleteBook();
    cout << "\n\tRemaining books in the list\n";
    obj.displayRecentBooks();

}