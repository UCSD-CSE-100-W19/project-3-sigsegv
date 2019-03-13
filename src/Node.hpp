//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// Node.hpp
// CSE 100 Project 3

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string id;      // id value inside of Node
    bool visited;   // flag if Node was visited or not
    Node* prev;     // previously visited Node
    vector<Node*> adj; // vector containing all adjacent Nodes

    Node() : id(0), visited(false), prev(NULL), adj() {}
    Node(string str) : id(str), visited(false), prev(NULL), adj() {}
};

#endif  // NODE_HPP
