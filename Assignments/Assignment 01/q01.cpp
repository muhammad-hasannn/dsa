#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class State{
private:
    vector<char> s;
    
public:
    State() {}

    State(vector<char> s){
        this->s = s;
    }

    vector<char> getState(){
        return s;
    }

    void display(){
        for(char c : s) cout << c << " ";
        cout << "\n";
    }

    bool isEqual(State goal){
        return s == goal.getState();
    }

    int findEmpty(){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-') return i;
        }
        return -1;
    }

    void swapAnimal(int i, int j){
        swap(s[i], s[j]);
    }

    string toString(){
        return string(s.begin(), s.end());
    }

};

class Node{
public:

    State state;
    Node* parent;

    Node(State state, Node* parent = nullptr){
        this->state = state;
        this->parent = parent;
    }
};

class BridgeSolver{
private:
    State start;
    State goal;

public:
    BridgeSolver(State start, State goal){
        this->start = start;
        this->goal = goal;
    }

    // after solving, we'll print path
    void printPath(Node* node){
        vector<State> path;

        while(node != nullptr){
            path.push_back(node->state);
            node = node->parent;
        }

        reverse(path.begin(), path.end());

        for(int i = 0; i < path.size(); i++){
            cout << "Move " << i << ": ";
            path[i].display();
        }
        cout << "\n";
    }

    void solve(){
        queue<Node*> q;
        set<string> visited;

        Node* root = new Node(start);

        q.push(root);
        visited.insert(start.toString());

        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            if(current->state.isEqual(goal)){
                printPath(current);
                return;
            }

            int empty = current->state.findEmpty();
            int size = current->state.getState().size();

            vector<int> moves = {-3, -2, -1, 1, 2, 3};

            for(int move : moves){
                int newPos = empty + move;

                if(newPos < 0 || newPos >= size){
                    continue;
                }

                State child = current->state; // copying the parent into child

                child.swapAnimal(empty, newPos); // updating the child

                string key = child.toString(); // doing this to check it in set

                if(visited.find(key) == visited.end()){
                // visited.end() = the last imaginery position (if set doesn't finds hey, it returns this..)

                    visited.insert(key);

                    Node* childNode = new Node(child, current);

                    q.push(childNode);
                }
            }
        }

        cout << "No solution found.\n";
    }
};


int main(){
    vector<char> initial = {'B', 'B', '-', 'L', 'L', 'E', 'E'};
    vector<char> goal = {'E', 'E', 'B', 'B', '-', 'L', 'L'};   

    State start(initial);
    State end(goal);

    BridgeSolver solver(start,end);    

    solver.solve();
}