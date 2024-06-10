Social Network Console Application

Overview:
    This console application simulates a basic social network platform where users can create posts, add comments, like posts, make friends, and view their timeline. The program is written in C++ and uses object-oriented programming principles.

Classes
1. User: Represents a user in the social network. Each user has a username, full name, date of birth, email, and a vector of friends.

2. Comments: Represents comments on a post. Each comment includes the commenter's name, content, and timestamp.

3. Post: Represents a user's post on the social media platform. It includes content, timestamp, likes, and a vector of comments.

4. SocialNetwork: Manages the overall social media platform. It includes methods to add new users, establish friendships, create posts, add comments to posts, and display user timelines.


How to Use
1. Run the program in a C++ environment.
Commands: g++ code.cpp -o code
          .\code

2. The program will prompt you to create a user profile by entering details such as username, full name, email, and date of birth.

3. Choose from the following options:
    - Add posts
    - Add comments to posts
    - Like any post
    - Make friends
    - View friends
    - View timeline
    - Change user
    - Exit

4. Follow the on-screen instructions for each option. You can create posts, add comments, like posts, make friends, and switch between user profiles.

5. Exit the program when done.

POINTS
- The program uses C++ standard libraries for input/output, string manipulation, vectors, and time functions.
- Overloaded operators are used for comparing usernames and liking posts.
- Since this was just an assignment, it may not handle advanced errors and security features, but it provides a basic functionality of a social media platform.