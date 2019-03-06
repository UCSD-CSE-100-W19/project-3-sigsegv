//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
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
	for(unsigned int i = 0; i < nodes.size(); i++){
		delete nodes[i];
	}
	for(unsigned int i = 0; i < edges.size(); i++){
		delete edges[i];
	}
}

bool Graph::containsNode(string id) {
    if (nodeMap.count(id) > 0) return true;
    else return false;
}

Node* Graph::getNode(string id) {
    if (containsNode(id)) {
        return nodeMap.at(id);
    } else {
        return NULL;
    }
}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
//TODO
void Graph::addNodesAndEdge(string from, string to) {
    Node * toNode;
    Node * fromNode;
    // if to node not in graph
    if (!containsNode(to)) {
        toNode = new Node(to);
        nodes.push_back(toNode);
        nodeMap[toNode->id] = toNode;
    } else {
        toNode = nodeMap[to];
    }
    
    // if from node not in graph
    if (!containsNode(from)) {
        fromNode = new Node(from);
        nodes.push_back(fromNode);
        nodeMap[fromNode->id] = fromNode;
    } else {
        fromNode = nodeMap[from];
    }
    
    // add fromNode and toNode to adj vectors
    fromNode->adj.push_back(toNode);
    toNode->adj.push_back(fromNode);
    
    // add new edge to edges vector
    // if edge not in edges
    //Edge * newEdge = new Edge(toNode, fromNode);
    //edges.push_back(newEdge);
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

    if (from == NULL || to == NULL) return "";
    
    for (unsigned int k = 0; k < nodes.size(); k++) {
        nodes[k]->dist = numeric_limits<int>::max();
        nodes[k]->prev = NULL;
    }
    
    queue.push(from);
    from->dist = 0;
    from->visited = true;
    Node* curr = from;
    while (!queue.empty()) {
        curr = queue.front();
        queue.pop();
        for (unsigned int i = 0; i < curr->adj.size(); i++) {
            Node* n = curr->adj[i];
            if (n->dist == numeric_limits<int>::max()) {
                n->dist = curr->dist+1;
                n->prev = curr;
                n->visited = true;
                queue.push(n);
            }
        }
    }
    
    vector<string> pathVec; // vector containing id's of Nodes
    string pathStr = "";
    
    // get path
    curr = to;
    while(curr != NULL) {
        pathVec.push_back(curr->id);
        curr = curr->prev;
    }
    
    if (pathVec.back() != from->id){
        return "";
    } else {
        // turn path into string
        while(!pathVec.empty()) {
            pathStr += pathVec.back();
            // print last elem without space at end
            if (pathVec.size() > 1)
                pathStr += " ";
            pathVec.pop_back();
        }
        return pathStr;
    }
}

/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {
    
}
