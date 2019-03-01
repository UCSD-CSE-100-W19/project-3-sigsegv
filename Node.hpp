//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// node.hpp
// CSE 100 Project 3

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
public:
    string id;
    bool visited;
    int  prev;
    int  dist;

    /*Node(){
        id = NULL;
        visited = false;
        prev = 0;
        dist = 0;
    }*/

    Node(string ID){
        id = ID;
        visited = false;
        prev = 0;
        dist = 0;
    }
};

#endif
