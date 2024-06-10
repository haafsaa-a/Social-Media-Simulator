#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

// this class will handle userinfo
class User
{
    string username;
    string fullname;
    string dob;
    string email;
    vector<User> friends;

public:
    // constructors
    User() : username(""), fullname(""), dob(""), email(""){};
    User(string usern, string fulln, string birth, string mail) : username(usern), fullname(fulln), dob(birth), email(mail){};

    // fucntion to get username
    string getUsername() const // const is used so that username does not change
    {
        return username;
    }

    // overload == operator to facilitate username-based comparisons
    bool operator==(User &user)
    {
        if (username == user.username)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // function to input user details
    void input()
    {
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter name: ";
        getline(cin, fullname);
        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter date of birth: ";
        getline(cin, dob);
    }

    // this function will add user of user's choice to friends list (which is a vector basically)
    void addFriends(User &userFriends)
    {
        friends.push_back(userFriends);
    }

    // this function displays all the users which user has chosen to be friends with
    void displayFriends()
    {
        if (friends.empty())
        {
            cout << "No friends." << endl;
        }
        else
        {
            for (auto &friendUser : friends)
            {
                cout << friendUser.getUsername() << endl;
            }
        }
    }
};

// sole purpose of this class is to handle comments on a post (including timestamp/commenter)
class Comments
{
private:
    string commenter; // person who is commenting
    string content;   // comment basically
    time_t timestamp; // time at which comment is being posted

public:
    // constructors
    Comments() : commenter(""), content("")
    {
    };
    Comments(int ID, string c, string c2) : commenter(c), content(c2){};

    // functions to represent comments
    void getComment()
    {
        cin.ignore(); // as I'm using getline() instead of cin, so program was showing unexpected behaviour. So by adding this function,
                      // program runned smoothly. This was because it consumed the newline character which was causing issue with getline().

        cout << "Enter your comment: " << endl;
        getline(cin, content); // i felt the need of using getline() instead of cin because when i added spaces in content of comment, program showed unexpected
                               // behaviour, because it read only first word and not the spaces. Getline reads a whole line until it encounters a newline char
                               // so this worked well with all inputs i took in strings.

        cout << "Enter your name: " << endl;
        getline(cin, commenter);
        timestamp = time(0);
    }

    // this function displays comments on a post
    void displayComment()
    {
        char *dt = ctime(&timestamp); // converting time_t var to a string to be read by human
        cout << "Comment: " << content << endl;
        cout << "Commenter: " << commenter << endl;
        cout << "Time: " << dt << endl;
    }
};

class Post
{
    // designed to represent user's posts on social media platform
private:
    string content;
    time_t timeStamp;
    double likes;
    vector<Comments> comment;

public:
    Post() : content(""), likes(0)
    {
    };
    Post(string contentP, int like) : content(contentP), likes(like){};

    // overload + operator to allow users to like the post
    Post operator+(User &user)
    {
        likes++;
        return *this;
    };

    // this function takes input of content of post from user
    void getpost()
    {
        cout << "Enter your content: " << endl;
        getline(cin, content);
        timeStamp = time(0);
    }

    // this function represents a post including its time, comments, likes.
    void displayPost()
    {
        char *dt = ctime(&timeStamp);
        cout << "Content: " << content << endl;
        cout << "Time: " << dt << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << endl;
        for (auto &userComments : comment)
        {
            userComments.displayComment(); // calling this function here prints all the comments associated specifically with this post which is being
                                           // displayed by the function
        }
    }

    // this function will add up a comment to comment vector
    void addComment(const Comments &newComment)
    {
        comment.push_back(newComment);
    }
};

class SocialNetwork
{
    /*Create a SocialNetwork class to manage the overall social media platform.
      Implement methods to add new users, establish friendships, create posts, and add comments to posts.
      */
private:
    // adding vectors of these classes because i am not dealing with single user and single post/comment
    vector<User> user;
    vector<Post> post;

public:
    // method to add users to the vector
    void addUserToVector(User &newUser)
    {
        user.push_back(newUser);
    }

    // method to input user details
    void inputUserDetails(User &newUser)
    {
        newUser.input();
    }

    // this function will return a user from user vector
    vector<User> &getUsers()
    {
        return user;
    }

    // this method will return a post from post vector
    vector<Post> &getposts()
    {
        return post;
    }

    // function to establish friendships between two users
    void addfriend(User &user1, User &user2)
    {
        user1.addFriends(user2);
        user2.addFriends(user1);
    }

    // function to create posts
    void createPosts(User &user, Post &posts)
    {
        posts.getpost();
        post.push_back(posts);
    }

    // method to display posts
    void displaypost(Post &uposts)
    {
        uposts.displayPost();
    }

    // method to add a specific comment to a post by a specific user
    void addComments(User &user, Post &post, Comments &comments)
    {
        post.addComment(comments);
    }

    // displays all the post by a user in chronological order
    void userTimeline()
    {
        cout << "-----------------" << endl;
        cout << "TIMELINE: " << endl;
        for (auto &userposts : post)
        {
            userposts.displayPost();
            cout << "-----------------" << endl;
        }
    }

    // this fucntion prints friend vector and shows friend of a specific user
    void displayfriends()
    {
        cout << "Friends: " << endl;
        for (auto &currentUser : user)
        {
            currentUser.displayFriends();
        }
    }
};

int main()
{
    SocialNetwork S1;
    User users;
    Post posts;
    int input;

    // these functions will take input from user and will add that user to the vector created in social network class
    S1.inputUserDetails(users);
    S1.addUserToVector(users);

    // interface for whole program
    while (1)
    {
        cout << "----------------------------------" << endl;
        cout << "Choose from following: " << endl;
        cout << "1. Add posts" << endl
             << "2. Add comments to posts" << endl
             << "3. Like any post " << endl
             << "4. Make friends" << endl
             << "5. View friends" << endl
             << "6. View Timeline " << endl
             << "7. Change user " << endl
             << "8. Exit " << endl;
        cout << "----------------------------------" << endl;
        cout << "Your choice(1-8): ";
        cin >> input;
        cin.ignore(); // to ignore newline char that was creating problem in running of program
        // add posts
        if (input == 1)
        {
            S1.createPosts(users, posts);
            continue;
        }
        // add comments to posts
        else if (input == 2)
        {
            // show all posts to user
            cout << "All posts: " << endl;
            for (int i = 0; i < S1.getposts().size(); i++)
            {
                cout << "----------------------" << endl;
                cout << "Post number: " << i + 1 << endl;
                S1.displaypost(S1.getposts()[i]);
                cout << "----------------------" << endl;
            }

            // now user can choose any post to comment at
            int postIndex;
            cout << "Choose a post to add a comment (by post number): ";
            cin >> postIndex;
            int index = postIndex - 1;

            if (index >= 0 && index < S1.getposts().size())
            {
                // Create a new Comments object for each comment
                Comments newComment;
                newComment.getComment();

                // Add the new comment to the post
                S1.addComments(users, S1.getposts()[index], newComment);
                cout << "Comment added to post " << index + 1 << endl;
            }
            else
            {
                cout << "Invalid post index." << endl;
            }

            continue;
        }
        // like any post
        else if (input == 3)
        {
            // show all available posts to user
            cout << "All posts: " << endl;
            for (int i = 0; i < S1.getposts().size(); i++)
            {
                cout << "----------------------" << endl;
                cout << "Post number: " << i + 1 << endl;
                S1.displaypost(S1.getposts()[i]);
                cout << "----------------------" << endl;
            }

            // now user can choose any post to like
            int postIndex;
            cout << "Choose a post to like: ";
            cin >> postIndex;

            int index = postIndex - 1;
            if (index >= 0 && index < S1.getposts().size())
            {
                S1.getposts()[index] = S1.getposts()[index] + users; // overloaded operator is being used to like a post
                cout << "Post liked!" << endl;
            }
            else
            {
                cout << "Invalid post number." << endl;
            }

            continue;
        }
        // make friends
        else if (input == 4)
        {
            // Display a list of existing users
            cout << "Existing users: " << endl;
            for (int i = 0; i < S1.getUsers().size(); i++)
            {
                cout << i + 1 << ". " << S1.getUsers()[i].getUsername() << endl;
            }

            // Ask the user to choose a user to become friends with
            int userChoice;
            cout << "Choose a user to become friends with (by user number): ";
            cin >> userChoice;
            userChoice--; // Adjusting the index to start from 0

            if (userChoice >= 0 && userChoice < S1.getUsers().size())
            {
                // Establish friendship
                S1.addfriend(users, S1.getUsers()[userChoice]);
                cout << "You are now friends with " << S1.getUsers()[userChoice].getUsername() << "!" << endl;
            }
            else
            {
                cout << "Invalid user choice." << endl;
            }

            continue;
        }
        // view friends
        else if (input == 5)
        {
            cout << "----------------------" << endl;
            S1.displayfriends(); // this function will display all friends
            cout << "----------------------" << endl;
            continue;
        }
        // view timeline
        else if (input == 6)
        {
            S1.userTimeline();
            continue;
        }
        // switch user
        else if (input == 7)
        {
            // Create a new user
            User newUsers;

            // Input user details
            S1.inputUserDetails(newUsers);

            if (users == newUsers) // overloaded operator will check if usernames are same or not
            {
                cout << "Same usernames. User is not added! " << endl;
            }
            else
            {
                // Add the user to the vector
                S1.addUserToVector(newUsers);
                cout << "New user added! " << endl;

                // Update the original user with the new user details
                users = newUsers;
            }

            continue;
        }
        else if (input == 8)
        {
            cout << "Bye Bye :)" << endl;
            break;
        }
        else
        {
            cout << "Choose a valid option!" << endl;
            continue;
        }
    }
}