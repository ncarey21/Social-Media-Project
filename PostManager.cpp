#include <iostream>
#include "PostManager.h"
#include "Post.h"
#include <sstream>
PostManager::PostManager(){ //Default Constructor
};
void PostManager::readPost(ifstream &inFile) {
    //Reads in file "Results.csv" and parses the Objects (rows) onto a vector<Post>
    string title, author, body, row;
    if (!inFile.is_open()) {
        cout << "File could not open";
    } else {
        while (getline(inFile, row, '\n')) {
            istringstream temp;
            temp.str(row);
            getline(temp, title, '`');
            getline(temp, body, '`');
            getline(temp, author, '`');
            Post tempPost = Post(title, body, author);
            postsRecord.push_back(tempPost);
        }
    }
}
void PostManager::writePost(Post MakePost){
    //Adds Post Object onto postsRecord vector
    postsRecord.push_back(MakePost);
}
void PostManager::endProgram(ofstream &oFiles) {
    //Writes vector to file "Results.csv" and uses ` to separate data members
    string *tempTitle, *tempBody, *tempAuthor;
    for (int i = 0; i < postsRecord.size(); i++) {
        tempTitle = postsRecord.at(i).title;
        oFiles << *tempTitle << "`";
        tempBody = postsRecord.at(i).body;
        oFiles << *tempBody << "`";
        tempAuthor = postsRecord.at(i).author;
        oFiles << *tempAuthor << "`";
        oFiles << endl;
    }
}
