#include "Post.h"
#include <iostream>

Post::Post(){
    //Default Constructor
    title = new string("none");
    body = new string("none");
    author = new string("none");
};
Post::Post(string newTitle, string newBody, string newAuthor){
    //Overloaded Constructor
    title = new string(newTitle);
    body = new string(newBody);
    author = new string(newAuthor);
};
Post::~Post(){
    //Destructor - step 1 of the rule of 3
    delete title;
    delete body;
    delete author;
};
Post::Post(const Post & copy){
    //Copy Constructor - step 2 of the rule of 3
    title = new string;
    body = new string;
    author = new string;
    *title = *(copy.title);
    *body = *(copy.body);
    *author = *(copy.author);
}
Post& Post::operator=(const Post & copy){
    //Copy Assignment Operator - step 3 of the rule of 3
    if(this != &copy){
        delete title;
        delete body;
        delete author;
        *title = *(copy.title);
        *body = *(copy.body);
        *author = *(copy.author);
    }
    return *this;
}
void Post::Display() {
    //Prints Post elements, and boxes them in with . and - characters to appear more user-friendly
    for (int i = 0; i < (*title).length(); i++) {
        cout << ".";
    }
    cout << endl << *title << endl;
    for (int i = 0; i < (*body).length(); i++) {
        cout << "-";
    }
    cout << endl << *body << endl;
    for (int i = 0; i < (*body).length(); i++) {
        cout << "-";
    }
    cout << endl << "@" << *author << endl;
    for (int i = 0; i < (*author).length(); i++) {
        cout << ".";
    }
    cout << endl << endl;
};
