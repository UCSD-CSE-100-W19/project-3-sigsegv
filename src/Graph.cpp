//
// Sunny Lau     cs100wav
// 2/26/19 
//
// Graph.cpp
// CSE 100 Project 3

#include "Graph.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

const int INFINITY = 2147483647;

Graph::Graph() : nodes(0), edges(0) {}

Graph::~Graph() {
    for (auto itr : nodes) {
        delete itr.second;
    }
}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
//TODO
void Graph::addNodeAndEdge(string from, string to) {
    Node * toNode = new Node(to);
    Node * fromNode = new Node(from);
    nodes.push_back(*toNode);
    Edge * newEdge = new Edge(toNode, fromNode);
    edges.push_back(*newEdge);
}

/* Read in relationships from an inputfile to create a graph */

bool Graph::loadFromFile(const char* in_filename) {
    ifstream infile(in_filename);
    
    while (infile) {
        string s;
        if (!getline(infile, s)) break;
        
        istringstream ss(s);
        vector<string> record;
        
        while (ss) {
            string s;
            if (!getline(ss, s, ' ')) break;
            record.push_back(s);
        }
        
        if (record.size() != 2) {
            continue;
        }
        
        // add node and edge to Graph
        addNodeAndEdge(record[0],record[1]);
    }
    
    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }
    
    infile.close();
    return true;
}

/* Implement pathfinder*/
bool Graph::pathfinder(Node* from, Node* to) {
    queue<Node*> queue;
    
    for (int k = 0; k < nodes.size(); k++) {
        nodes[k].dist = INFINITY;
        nodes[k].prev = NULL;
    }
    
    stack<Node> path;
    queue.push(from);
    from->dist = 0;
    from->visited = true;
    Node* curr = from;
    while (curr != to) {
        curr = queue.front();
        queue.pop();
        //for each neighbor of curr
        for (int i = 0; i < curr->adj.size(); i++) {
            Node* n = curr->adj[i];
            if (n->dist == INFINITY) {
                n->dist = curr->dist+1;
                n->prev = curr;
                n->visited = true;
                queue.push(n);
            }
        }
    }
    return true;
}


/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {
    
}

