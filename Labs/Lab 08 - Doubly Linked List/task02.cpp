#include<iostream>
using namespace std;

struct Card{
    string rank;
    string suit;
};

class Node{
public:
    Card data;
    Node* pre;
    Node* next;

    Node(Card data){
        this->data = data;
        pre = next = nullptr;
    }
};

class CardDeck{
private:
    Node *head, *tail;

public:
    CardDeck(){ head = tail = nullptr; }

    // 1. Adding new card (at top)
    void addNewCard(Card val){
        if(head == nullptr){
            head = tail = new Node(val);
        } else {
            Node* newNode = new Node(val);

            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    // 2. Display the card (in forward order)
    void displayCards(){
        if(head == nullptr){
            cout << "No cards to display.\n";
        } else {
            Node* temp = head;

            cout << "\t---Cards in the deck---\n";
            while(temp){
                cout << "Card rank: " << temp->data.rank << ", Card suit: " << temp->data.suit << "\n";
                temp = temp->next;    
            }
            cout << "\n";
        }
    }

    // 3. Inserting Cards After a Specific Card
    void insertByRank(Card val, string target){
        if(head == nullptr){
            head = tail = new Node(val);
            return;
        }        

        // simple linear search
        Node* temp = head;

        while(temp != nullptr){
            if(temp->data.rank == target) break;
            temp = temp->next;
        }

        if(!temp){
            cout << "Card with this rank doesn't exists.\n";
            return;
        }
        
        Node* newNode = new Node(val);
        newNode->pre = temp;
        newNode->next = temp->next;
        
        if(temp == tail){
            temp->next = newNode;
            tail = newNode;
        }
        else{
            temp->next->pre = newNode;
            temp->next = newNode;
        }
    }

    // 4. Search by rank (if present then display with position)
    void searchByrank(string target){
        if(head == nullptr){
            cout << "There are no cards in deck to search from.\n";
            return;
        }

        Node* temp = head;
        int count = 1;
        while(temp){
            if(temp->data.rank == target) break;
            temp = temp->next;
            count++;
        }

        if(!temp){
            cout << "No card with the this rank exists in the deck.\n";
            return;
        }

        cout << "Card details:\n";
        cout << "\tPosition: " << count << "\n";
        cout << "\tRank: " << temp->data.rank << "\n";
        cout << "\tSuit: " << temp->data.suit << "\n";
    }

    // 5. Remove form top
    void removeFromTop(){
        if(head == nullptr){
            cout << "No card to remnove from top.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head == nullptr) tail = nullptr;
        else head->pre = nullptr;

        delete temp;
    }
};

int main(){
    CardDeck deck;

    Card c1 = {"Ace","Spades"};
    Card c2 = {"King","Hearts"};
    Card c3 = {"Queen","Diamonds"};
    Card c4 = {"Jack","Clubs"};
    Card c5 = {"10","Spades"};

    deck.addNewCard(c1);
    deck.addNewCard(c2);
    deck.addNewCard(c3);

    cout<<"Initial Deck\n";
    deck.displayCards();

    cout<<"\nSearching Queen\n";
    deck.searchByrank("Queen");

    cout<<"\nInserting after King\n";
    deck.insertByRank(c4,"King");

    deck.displayCards();

    cout<<"\nRemoving top card\n";
    deck.removeFromTop();

    deck.displayCards();
}