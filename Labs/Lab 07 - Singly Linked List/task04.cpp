/*Train Route Manager*/

#include<iostream>
using namespace std;

class Node{
public:
    string station;
    Node* next;

    Node(string station){
        this->station = station;
        next = nullptr;
    }
};

class TrainRoute{
private:
    Node* head;
    Node* tail;

public:
    TrainRoute(){ head = tail = nullptr; }

    void insertAtHead(string name){
        if(head == nullptr){
            head = tail = new Node(name);
            tail->next = head;
        } else{
            Node* newNode = new Node(name);
            newNode->next = head;
            head = newNode;

            // tail->next = newNode; // bad practice
            tail->next = head; // good practice
        }
    }

    void insertAtEnd(string name){
        if(head == nullptr){
            head = tail = new Node(name);
            tail->next = head;
        } else{
            Node* newNode = new Node(name);

            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    /**
     * this fn is considering indexing from 1
     */
    void insertAtPosition(int pos, string name){
        if(pos < 1){
            cout << "Invalid Position.\n";
            return;
        }

        if(head == nullptr && pos != 1){
            cout << "Position out of bounds.\n";
            return;
        }

        /**
         * handling pos == 1 here for both conditions
         *  1. linked list is empty
         *  2. any other stiuation of ll
         * 
         * the loop we are writing willn't work if pos == 1;
         * beacise our loop will never run and first node will be considered previous 
         */
        if(pos == 1){
            if(head == nullptr){
                head = tail = new Node(name);
                tail->next = head;
            } else{
                Node* newNode = new Node(name);
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
            return;
        }

        Node* newNode = new Node(name);
        Node* pre = head;

        for(int i = 1; i < pos-1; i++){
            pre = pre->next; // moving pre* first, beacise in first itr it is obv on head...

            
            // if you are thinking that for pos == 2 so pre* will obviously be on head...
            // no problem in that our loop willn't even run one time if pos == 2...
            // this is in case we reach again to head...
            if(pre == head){
                cout << "Position out of bounds.\n";
                return;
            }

        }   
        newNode->next = pre->next;
        pre->next = newNode;

        if(pre == tail) tail = newNode;                
    }


    void deleteHead(){
        if(head == nullptr){
            cout << "List os empty.\n";
            return;
        }

        if(head->next == head){ // we have only one node
            delete head;
            head = tail = nullptr;
        } else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void deleteTail(){
        if(head == nullptr){
            cout << "List is empty.\n";
            return;
        }

        if(head->next == head){
            delete head;
            head = tail = nullptr;
        } else{
            Node* temp = head;

            while(temp->next != tail) temp = temp->next;

            delete tail;
            tail = temp;
            tail->next = head;
        }
    }

    /**
     * indexing from 1
     */
    void deleteAtPodition(int pos){
        if(pos < 1){
            cout << "Invalid position.\n";
            return;
        }

        if(head == nullptr){
            cout << "List is empty.\n";
            return;
        }

        // now it is confirmed that our list exists, let's tackle pos == 1 first...

        if(pos == 1){
            if(head->next == head){
                delete head;
                head = tail = nullptr;
            } else{
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
            return;
        }

        Node* pre = head;

        for(int i = 1; i < pos-1; i++){
            pre = pre->next;

            if(pre == head){ // we traversed completely on list and now have come back to head again...
                cout << "Position out of bounds.\n";
                return;
            }
        }

        if(pre == tail){ // this can also be handled in loop
            cout << "Position out of bounds.\n";
            return;
        }

        if(pre->next == tail){ // we reched to secind last node
            delete tail;
            tail = pre;
            tail->next = head;
        } else{
            Node* toBeDeleted = pre->next;
            pre->next = toBeDeleted->next;
            delete toBeDeleted;
        }
    }

    void displayList(){
        if(head == nullptr){
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while(true){
            cout << temp->station << " ";
            temp = temp->next;

            if(temp == head) break;
        }
        cout << "\n";
    }

};

int main(){


}