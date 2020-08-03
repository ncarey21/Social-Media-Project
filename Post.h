//
// Created by Nathan Michael Carey on 7/29/20.
//

#ifndef CAREY_PA3_POST_H
#define CAREY_PA3_POST_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Post {
public:
    Post();//Default Constructor
    Post(string newTitle, string newBody, string newAuthor);//Overloaded Constructor
    ~Post();//Destructor
    Post(const Post & copy);//Copy Constructor
    Post& operator=(const Post &);//Copy Assignment Operator
    void Display();
    string* title;
    string* body;
    string* author;
private:
};
#endif //CAREY_PA3_POST_H
