#include <iostream>
#include <string>
#include "PostManager.h"
#include "Post.h"
using namespace std;
/*
 * This Program acts as a basic Social Media -
 * It lets users write posts, view posts, and search for posts by author.
 * Author: Nathan Carey
 * Date: 07/29/2020
 */
int main() {
    int userChoice = 0;
    PostManager temp;

    ifstream inFile;
    inFile.open("../Results.csv");
    while(inFile.is_open()) {
        temp.readPost(inFile); //Reads in posts from "Results.csv" file into vector to store previously made posts
        inFile.close();
    }

    while(userChoice != 5) { //Checks for user input options 1-4 and quits program if option 5 or another key is inputted

        cout << "Welcome, Please Select An Option (1-5) \n1. Create Post\n2. View Last 10 Posts\n3. View All Posts\n4. Find Posts By User\n5. Quit" << endl;
        cin >> userChoice;
        cin.clear();
        cin.ignore();

        if (userChoice == 1) { //New Post
            string newTitle, newBody, newAuthor;
            cout << "Please Enter The Following Information\nTitle\nBody\nAuthor" << endl;
            getline(cin, newTitle, '\n');
            getline(cin, newBody, '\n');
            getline(cin, newAuthor, '\n');
            while (newTitle.length() > 25) {
                cout << "Please re-enter a title (25 character max)" << endl;
                getline(cin, newTitle);
                cin.clear();
            }
            while (newBody.length() > 255) {
                cout << "Post too long, please re-type your post (255 character max)" << endl;
                getline(cin, newBody);
                cin.clear();
            }
            cout << "Post Created Successfully!" << endl;
            Post MakePost(newTitle, newBody, newAuthor); //Uses constructor to initialize user-made post
            temp.writePost(MakePost); //Stores new post to the vector<Post>
        }
        if (userChoice == 2) { //View Last 10 Posts
            if (temp.postsRecord.size() < 10) { //Prints All Posts if # of Posts is < 10
                for (int i = 0; i < temp.postsRecord.size(); i++) {
                    temp.postsRecord.at(i).Display();
                }
            }
            else { //Prints last 10 posts if # of posts > 10
                for (int i = temp.postsRecord.size() - 10; i < temp.postsRecord.size(); i++) {
                    temp.postsRecord.at(i).Display();
                }
            }
        }
        if (userChoice == 3) { //Print All Posts
            for (int i = 0; i < temp.postsRecord.size(); i++) {
                temp.postsRecord.at(i).Display();
            }
        }
        if (userChoice == 4) { //Author Search
            string author;
            cout << "Please enter an author name" << endl;
            cin >> author;
            vector<Post> tempVec; //test vector to populate if string author returns a match
            for (int i = 0; i < temp.postsRecord.size(); i++) {
                string *tempPoint = temp.postsRecord.at(i).author;
                if (*tempPoint == author) {
                    tempVec.push_back(temp.postsRecord.at(i));
                    temp.postsRecord.at(i).Display();
                }
            }
            if (tempVec.empty()){
                cout << "No such author found" << endl;
            }
        }
    }
    cout << "End of Program" << endl;
    ofstream oFile("../Results.csv");
    temp.endProgram(oFile); //Writes all Posts inside of the vector postsRecord to the "Results.csv" file
    oFile.close(); //Closes the file stream

    return 0;
}
