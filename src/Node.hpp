#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

class Node {
protected:
    string id;      // id value inside of Node
    bool visited;   // flag if Node was visited or not
    Node* prev;       // previously visited Node
    int dist;       // distance from root to Node
    vector<string> adj; // vector containing all adjacent Nodes
    
public:
    Node(str) : id(str), visited(false), prev(NULL), dist(0), adj(new vector<string>()) {}
};

#endif  // GRAPH_HPP
