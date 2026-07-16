#include<iostream>
#include <queue>
using namespace std;

class Node{
public:
    float data;
    bool isDummy;
    Node *left, *right;

    Node(float data, bool isDummy = false){
        this->data = data;
        this->isDummy = isDummy;
        left = right = nullptr;
    }
};

// a. display prices in sorted order
void displaySortedPrices(Node* root){
    if(!root) return;

    displaySortedPrices(root->left);
    cout << root->data << " ";
    displaySortedPrices(root->right);
}

// b. display no of prices below average
void diplayPricesBelowAvg(Node* root){
    if(root->left == nullptr){ // empty check
        cout << "There is no price below average in the tree.\n";
    }

    Node* temp = root->left;
    int count = 0;
    queue<Node*> q;
    q.push(temp);

    // doing simple level order traversal
    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            Node* curr = q.front();
            q.pop();
            count++;        

            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
    }    
    cout << "Items below average: " << count << ".\n";
}

// c. no of prices above average

// d. diaplay the highest price
int getHighestPrice(Node* root){
    if(root->right != nullptr){
        Node* temp = root->right;
    
        while(temp->right != nullptr) temp = temp->right;

        return temp->data;        
    }
    else if(root->left != nullptr){
        Node* temp = root->left;
        while(temp->right != nullptr) temp = temp->right;
        return temp->data;
    }

    return -1;   
}

int main(){
    Node* root = new Node(13.273, true); // anchor value to split data

    
}