/*BeanBuzz Queue Management System*/

#include<iostream>
#include<string>
using namespace std;

struct Order{
    int no;
    string customerName;
    string drinkType;
    string customization;
};

class Node{
public:
    Order data;
    Node* next;

    Node(Order data){
        this->data = data;
        next = nullptr;
    }
};

class BeanBuzzQueue{
private:
    Node* head;
    int f, r;

public:
    BeanBuzzQueue(){
        head = nullptr;
        f = r = -1;
    }

    void placeOrder(Order od){
        if(f == -1){
            f = r = 0;
            head = new Node(od);
            cout << "Order placed successfully. Order number: " << od.no << "\n";
        }
        
        // insertion at the end case
        else{
            r++;
            Node* newNode = new Node(od);

            Node* temp = head;
            while(temp->next != nullptr) temp = temp->next;
            temp->next = newNode;

            cout << "Order placed successfully. Order number: " << od.no << "\n";
        }
    }

    void serveOrder(){
        if(f == -1) cout << "There are no orders in the list.\n";
        else{
            Node* temp = head;
            head = head->next;

            cout << "Order served successfully. Served order number " << temp->data.no << "\n";
            delete temp;
            f++;
        }

        if(head == nullptr)   // if queue gets empty, reset
            f = r = -1;
    }

    void displayQueueStatus(){
        if(f == -1) cout << "There are no orders in the queue.\n";
        else{
            cout << "\t---Orders in the Queue---\n\n";

            Node* mover = head;
            while(mover){
                cout << "Order No. " << mover->data.no << " Customer name: " << mover->data.customerName << " | Drink type: " <<
                mover->data.drinkType << " | Customization: " << mover->data.customization << "\n";

                mover = mover->next;
            }
        }
    }

    Node* searchOrder(int target){
        if(f == -1) return nullptr;

        Node* mover = head;
        while(mover){
            if(mover->data.no == target) return mover;
            mover = mover->next;
        }

        return nullptr;
    }
};

int main(){
    int choice = 0;
    int totalOrders = 0;
    BeanBuzzQueue q;
    cout << "\n\t***Welcome to BeanBuzz Queue Managment System***\n\n";

    do{
        cout << "\n\t---MENU---\n";
        cout << "1. Place Order.\n";
        cout << "2. Serve Order.\n";
        cout << "3. Display Queue Status.\n";
        cout << "4. Display Order Details\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        cout << "\n";

        switch (choice){

            case 1:{
                Order newOrder;
                cout << "Enter customer name: ";
                getline(cin, newOrder.customerName);
                cout << "Enter drink type: ";
                getline(cin, newOrder.drinkType);
                cout << "Enter customization: ";
                getline(cin, newOrder.customization);
                newOrder.no = ++totalOrders;

                q.placeOrder(newOrder);
            }
            break;

            case 2:
                q.serveOrder();
            break;

            case 3:
                q.displayQueueStatus();
            break;

            case 4:{
                int target = 0;
                cout << "Enter order no. to search: ";
                cin >> target;
                cin.ignore();

                Node* order = q.searchOrder(target);

                if(!order) cout << "There is no order with this order number.\n";
                else{
                    cout << "\tOrder details\n";
                    cout << "No. " << order->data.no << "Customer name: " << order->data.customerName << " | Drink type: " <<
                    order->data.drinkType << " | Customization: " << order->data.customization << "\n";
                }
            }
            break;

            case 5:
                cout << "Closing program.\n";
            break;
            
            default:
                cout << "Please enter a valid choice.\n";
            break;
        }

    }while(choice != 5);
}