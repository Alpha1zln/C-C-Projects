//vr 8 ........... FriendlyPlanet ***************


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//  ******************************************************
class FriendlyPlanet {

private:
    unordered_map<string, vector<string>> friendsList;
    unordered_map<string, vector<string>> userPosts;
    unordered_map<string, int> postLikes;
    unordered_map<string, vector<string>> followers;


public:
    //  ***********************
    void addFriend(const string& user, const string& friendName) {
        friendsList[user].push_back(friendName);
        friendsList[friendName].push_back(user);
    }

    //  ***********************
    void createPost(const string& user, const string& post) {
        userPosts[user].push_back(post);
        postLikes[post] = 0;
    }

    //  ***********************
    void showPosts(const string& user) {
        if (userPosts.find(user) == userPosts.end()) {
            cout << "No posts found for user " << user << endl;
            return;
        }

        cout << "Posts for user " << user << ":" << endl;
        for (const auto& post : userPosts[user]) {
            cout << post << " (Likes: " << postLikes[post] << ")" << endl;
        }
    }

    //  ***********************
    void showMutualConnections(const string& user) {
        if (friendsList.find(user) == friendsList.end()) {
            cout << "User not found in the network." << endl;
            return;
        }

        cout << "Mutual connections for user " << user << ":" << endl;
        for (const auto& friendName : friendsList[user]) {
            cout << friendName << endl;
        }
    }

    //  ***********************
    void followUser(const string& follower, const string& user) {
        followers[user].push_back(follower);
    }

    //  ***********************
    void showFollowers(const string& user) {
        if (followers.find(user) == followers.end()) {
            cout << "No followers found for user " << user << endl;
            return;
        }

        cout << "Followers of user " << user << " (" << followers[user].size() << " followers):" << endl;
        for (const auto& follower : followers[user]) {
            cout << follower << endl;
        }
    }


    //  ***********************
    void likeUserPost(const string& entryPerson, const string& user) {
        if (userPosts.find(user) == userPosts.end()) {
            cout << "User not found." << endl;
            return;
        }

        cout << "Choose a post to like of user " << user << " -" << endl;
        int i = 1;
        for (const auto& post : userPosts[user]) {
            cout << i << ": " << post << endl;
            i++;
        }

        int choice;
        //cout << entryPerson << " liked the post of user: " << user << "!" << endl;
        cout << "Enter the post number to like: ";
        cin >> choice;

        if (choice >= 1 && choice <= i - 1) {
            string selectedPost = userPosts[user][choice - 1];
            postLikes[selectedPost]++;
            cout << entryPerson << " liked the post of user: " << user << "!" << endl;
        } else {
            cout << "Invalid post number." << endl;
        }
    }

    //  ***********************
    void seeLikes(const string& user) {
        if (userPosts.find(user) == userPosts.end()) {
            cout << "User not found." << endl;
            return;
        }

        cout << "Likes on " << user << "'s posts:" << endl;
        for (const auto& post : userPosts[user]) {
            cout << post << " (Likes: " << postLikes[post] << ")" << endl;
        }
    }
};


//  main***************************************************
int main() {
    FriendlyPlanet fb;

    cout << "Welcome to FriendlyPlanet!" << endl;

    while (true) {
        cout << endl << "FriendlyPlanet features :: \n";
        cout << "1- Add friends           2- Create post\n";
        cout << "3- See posts             4- See mutual connections\n";
        cout << "5- Follow user           6- See followers\n";
        cout << "7- Like post             8- See likes\n";
        cout << "9- Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string userName, friendName;
            cout << "Enter your name: ";
            cin >> userName;
            cout << "Enter friend's name: ";
            cin >> friendName;
            
            fb.addFriend(userName, friendName);
            cout << "Friend added successfully!" << endl;
        } 
        else if (choice == 2) {
            string userName, post;
            cout << "Enter your name: ";
            cin >> userName;
            cin.ignore();
            
            cout << "Create post: ";
            getline(cin, post);
            fb.createPost(userName, post);
            
            cout << "Post created successfully!" << endl;
        } 
        else if (choice == 3) {
            string userName;
            cout << "Enter your name: ";
            cin >> userName;
            fb.showPosts(userName);
        } 
        else if (choice == 4) {
            string userName;
            cout << "Enter your name: ";
            cin >> userName;
            fb.showMutualConnections(userName);
        } 
        else if (choice == 5) {
            string entryPerson, userToFollow;
            cout << "Enter your name (entry person's name): ";
            cin >> entryPerson;
            cout << "Enter user's name (to follow): ";
            cin >> userToFollow;

            fb.followUser(entryPerson, userToFollow);
            cout << entryPerson << " is now following " << userToFollow << endl;
        } 
        else if (choice == 6) {
            string user;
            cout << "Enter user's name: ";
            cin >> user;
            fb.showFollowers(user);
        } 
        else if (choice == 7) {
            string entryPerson, userToLike;
            cout << "Enter your name (entry person's name): ";
            cin >> entryPerson;
            cout << "Enter user's name (whose posts to like): ";
            cin >> userToLike;
            fb.likeUserPost(entryPerson, userToLike);
        } 
        else if (choice == 8) {
            // ... (existing code)
                 string userName;
                cout << "Enter your name: ";
                cin >> userName;
                fb.seeLikes(userName);
        }
        else if (choice == 9) {
            cout << "Exiting..." << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
