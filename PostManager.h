//
// Created by Nathan Michael Carey on 7/29/20.
//

#ifndef CAREY_PA3_POSTMANAGER_H
#define CAREY_PA3_POSTMANAGER_H
#include "Post.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class PostManager {
public:
    void readPost(ifstream &inFiles);
    void writePost(Post MakePost);
    void endProgram(ofstream &oFiles);
    vector<Post> postsRecord; //Vector that stores all Posts
    PostManager(); //Default Constructor
private:
};
#endif //CAREY_PA3_POSTMANAGER_H
