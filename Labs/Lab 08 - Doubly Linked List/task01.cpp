#include<iostream>
using namespace std;

class Node{
public:
    string step;
    Node* pre;
    Node* next;

    Node(string step){
        this->step = step;
        pre = next = nullptr;
    }
};

class UniversityRoute{
private:
    Node* head;
    Node* tail;

public:
    UniversityRoute(){ head = tail = nullptr; }
    
    // 1. add new route step
    void addRouteStep(string val){
        if(head == nullptr){
            head = tail = new Node(val);
        } else {
            Node* newNode = new Node(val);

            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 2. delete entire route
    void deleteEntireRoute(){
        if(head == nullptr){
            cout << "No route step to delete\n";
        } else {
            while(head != nullptr){
                Node* temp = head;

                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
            cout << "All steps deleted.\n";
        }
    }

    // 3. show route in reverse order
    void displayReverse(){
        if(head == nullptr){
            cout << "No route to display.\n";
        } else {
            Node* temp = tail;

            cout << "Route Steps:\n\n";
            int count = 1;
            while(temp != nullptr){
                cout << count++ << ". " << temp->step << "\n";
                temp = temp->pre;
            }
        }
    }
};

int main(){
    UniversityRoute route;

    route.addRouteStep("Start from Home");
    route.addRouteStep("Go straight for 500m");
    route.addRouteStep("Turn left at the traffic signal");
    route.addRouteStep("Continue for 1.2 km");
    route.addRouteStep("Turn right towards Bahria University");
    route.addRouteStep("You have reached Bahria University");

    cout<<"========== Bahria University ---> Home ==========\n";
    route.displayReverse();

    cout<<"\nDeleting Entire Route...\n";
    route.deleteEntireRoute();

    cout<<"\nTrying to display after deletion:\n";
    route.displayReverse();    
}