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
#include <list>
#include <unordered_map>

using namespace std;


Graph::Graph() : nodes(0), edges(0) {}

Graph::~Graph() {
    while(!nodes.empty()) {
        nodes.pop_back();
    }
    while(!edges.empty()) {
        edges.pop_back();
    }
}

bool Graph::containsNode(Node * n) {
    for (int i=0; i<nodes.size(); i++) {
        if (nodes.at(i).id == n->id) {
            return true;
        }
    }
    return false;
}

Node* Graph::getNode(string id) {
    return nodeMap.at(id);
}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
//TODO
void Graph::addNodesAndEdge(string from, string to) {
    Node * toNode = new Node(to);
    Node * fromNode = new Node(from);
    //push back actual to Node object
    nodes.push_back(*toNode);
    // add Node to nodeMap
    nodeMap.insert({toNode->id, toNode});
    
    // if fromNode not in Graph, add it to Graph
    if (!containsNode(fromNode)) {
        //push back actual from Node object
        nodes.push_back(*fromNode);
        nodeMap.insert({fromNode->id, fromNode});
    }
    // add fromNode and toNode to adj vectors
    fromNode->adj.push_back(toNode);
    toNode->adj.push_back(fromNode);
    // add new edge to edges vector
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
        addNodesAndEdge(record[0],record[1]);
    }
    
    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }
    
    infile.close();
    return true;
}

/* Implement pathfinder*/
// return string containing shortest path between from and to

string Graph::pathfinder(Node* from, Node* to) {
    // infinity = numeric_limits<int>::max()
    queue<Node*> queue;
    
    for (int k = 0; k < nodes.size(); k++) {
        nodes[k].dist = numeric_limits<int>::max();
        nodes[k].prev = NULL;
    }

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
            if (n->dist == numeric_limits<int>::max()) {
                n->dist = curr->dist+1;
                n->prev = curr;
                n->visited = true;
                queue.push(n);
            }
        }
    }
    
    // if no path found, return empty line
    if (queue.back() != to) {
        return "\n";
        
    // else, get and return the path
    } else {
        vector<string> pathVec;
        string pathStr = "";
        
        // get path
        curr = to;
        while(curr->prev != NULL) {
            pathVec.push_back(curr->id);
            curr = curr->prev;
        }
        
        // turn path into string
        while(!pathVec.empty()) {
            pathStr += pathVec.back() + " ";
            pathVec.pop_back();
        }
        pathStr += "\n";
        return pathStr;
    }
}

/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {
    
}
