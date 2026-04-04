/*News Feed*/

#include<iostream>
using namespace std;

class Node{
public:
    string content;
    int timeStamp;
    Node* next;

    Node(string content, int timeStamp){
        this->content = content;
        this->timeStamp = timeStamp;
        next = nullptr;
    }
};

class NewsFeed{
private:
    Node* head;

public:
    NewsFeed(){ head = nullptr; }

    /**
     * 1. Adding a new post to the end of the feed
     */
    void addPost(string content, int timeStamp){
        if(head == nullptr){
            head = new Node(content, timeStamp);
            return;
        }
        Node* newNode = new Node(content, timeStamp);
        Node* mover = head;

        while(mover->next != nullptr) mover = mover->next;

        mover->next = newNode;
    }

    /**
     * 2. Removing a post by its content
     */
    void removePost(string content){
        if(head == nullptr){
            cout << "There are no news in the list.\n";
            return;
        }

        if(head->next == nullptr){

            if(head->content == content){
                Node* temp = head;
                head = nullptr;
                cout << "Content: '" << temp->content << "' Timestamp: '" << temp->timeStamp << "', deleted successfully!\n";
                delete temp;
                return;
            }
            else{
               cout << "There is no news wiht this content in the list.\n";
               return; 
            }
        }

        if(head->content == content){
            Node* temp = head;
            head = head->next;
            cout << "Content: '" << temp->content << "' Timestamp: '" << temp->timeStamp << "', deleted successfully!\n";
            delete temp;
            return;
        }

        Node* pre = head;
        while(pre->next != nullptr){
            if(pre->next->content == content) break;
            pre = pre->next;
        }

        // we reched at last node
        if(pre->next == nullptr){
            
            // the content is also which we want to delete..
            if(pre->content == content){
                cout << "Content: '" << pre->content << "' Timestamp: '" << pre->timeStamp << "', deleted successfully!\n";
                delete pre;
                return;
                // there is a BUG
            }
            else{
                cout << "There is no news wiht this content in the list.\n";
                return;
            }
        }
        
        Node* toBeDeleted = pre->next;
        pre->next = toBeDeleted->next;

        cout << "Content: '" << toBeDeleted->content << "' Timestamp: '" << toBeDeleted->timeStamp << "', deleted successfully!\n";
        delete toBeDeleted;
    }

    /**
     * 3. Displaying all posts in chronological order
     */
    void displayAllPosts(){
        if(head == nullptr){
            cout << "There are no news in the list to display.\n";
            return;
        }

        Node* mover = head;
        cout << "\t\tHeadlines by Hasan Newz.\n";
        int sno = 1;
        while(mover){
            cout <<sno++<< ". Content: '" << mover->content << "' Timestamp: '" << mover->timeStamp << "'.\n";
            mover = mover->next;
        }
    }

    /**
     * 4. Total Count of Posts
     */
    int totalPost(){
        if(head == nullptr) return 0;

        int count = 0;
        Node* mover = head;
        while(mover){
            count++;
            mover = mover->next;
        }
        return count;
    }

    /**
     * 5. Search a post by its content
     * @return address of that node
     */
    Node* search(string content){
        if(head == nullptr) return nullptr;

        Node* mover = head;
        while(mover != nullptr){
            if(mover->content == content) break;
            mover = mover->next;
        }

        if(mover == nullptr) return nullptr;

        return mover;
    }
};

int main(){
 
    NewsFeed feed = NewsFeed();
 
    // ── 1. Add seven posts
    cout << "========================================\n";
    cout << "         ADDING POSTS TO FEED\n";
    cout << "========================================\n";
 
    feed.addPost("Post 1", 1);
    feed.addPost("Post 2", 2);
    feed.addPost("Post 3", 3);
    feed.addPost("Post 4", 4);
    feed.addPost("Post 5", 5);
    feed.addPost("Post 6", 6);
    feed.addPost("Post 7", 7);
 
    cout << "\n7 posts added successfully!\n";
 
    // ── 2. Display all posts
    cout << "\n========================================\n";
    cout << "        ALL POSTS (CHRONOLOGICAL)\n";
    cout << "========================================\n";
    feed.displayAllPosts();
 
    // ── 3. Total count
    cout << "\n========================================\n";
    cout << "           TOTAL POST COUNT\n";
    cout << "========================================\n";
    cout << "Total posts: " << feed.totalPost() << "\n";
 
    // ── 4. Remove two posts as requested by user
    cout << "\n========================================\n";
    cout << "           REMOVING POSTS\n";
    cout << "========================================\n";
 
    string removeTarget;
 
    cout << "Enter content of post to remove (1st): ";
    getline(cin, removeTarget);
    feed.removePost(removeTarget);
 
    cout << "Enter content of post to remove (2nd): ";
    getline(cin, removeTarget);
    feed.removePost(removeTarget);
 
    // ── 5. Display remaining posts
    cout << "\n========================================\n";
    cout << "        REMAINING POSTS\n";
    cout << "========================================\n";
    feed.displayAllPosts();
 
    // ── 6. Updated count
    cout << "\n========================================\n";
    cout << "        UPDATED TOTAL POST COUNT\n";
    cout << "========================================\n";
    cout << "Total posts: " << feed.totalPost() << "\n";
 
    // ── 7. Search a post as requested by user
    cout << "\n========================================\n";
    cout << "           SEARCH A POST\n";
    cout << "========================================\n";
 
    string searchTarget;
    cout << "Enter content to search: ";
    getline(cin, searchTarget);
    if(feed.search(searchTarget)!= nullptr) cout << "found."; 


 
    cout << "\n========================================\n";
    cout << "              DONE!\n";
    cout << "========================================\n"; 
    
}