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
#include <map>

using namespace std;

// Constructor method
Graph::Graph() : nodes(0) {}

// Destructor method
Graph::~Graph() {
    // For each Node in nodes, delete it
    for(unsigned int i = 0; i < nodes.size(); i++){
        delete nodes[i];
    }
}

// Checks if the hashmap contains the Node object
// Params: string containing the id of the object
// Return: Whether or not a Node with id exists in the hashmap
bool Graph::containsNode(string id) {
    if (nodeMap.count(id) > 0) return true;
    else return false;
}

// Getter method for Node objects
// Params: string containing the id of the object
// Return: A pointer to the desired Node, NULL if it doesn't exist
Node* Graph::getNode(string id) {
    if (containsNode(id)) {
        return nodeMap.at(id);
    } else {
        return NULL;
    }
}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
// Adds a Node to the hashmap and nodes vector
// Params: strings containg the ids of two nodes we want to connect
void Graph::addNodes(string from, string to) {
    // Node pointers pointing to Node objects with ids from and to
    Node * toNode;
    Node * fromNode;
    // if to node not in graph
    if (!containsNode(to)) {
        // Make a new node
        toNode = new Node(to);
        // Insert into the hashmap with the id
        nodes.push_back(toNode);
        nodeMap[toNode->id] = toNode;
    } else {
        toNode = nodeMap[to];
    }
    
    // if from node not in graph
    if (!containsNode(from)) {
        // Make a new node
        fromNode = new Node(from);
        // Insert into the hashmap with the id
        nodes.push_back(fromNode);
        nodeMap[fromNode->id] = fromNode;
    } else {
        fromNode = nodeMap[from];
    }
    
    // add fromNode and toNode to adj vectors
    fromNode->adj.push_back(toNode);
    toNode->adj.push_back(fromNode);
    
    // set degrees of from and to nodes
    fromNode->degree = fromNode->adj.size();
    toNode->degree = toNode->adj.size();
}

/* Read in relationships from an inputfile to create a graph */
// Loads nodes from file
// Params: const char pointer to the input file's name
// Return: Whether or not the file was correctly read
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
        
        // add nodes to Graph
        addNodes(record[0],record[1]);
    }
    
    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }
    
    infile.close();
    return true;
}

// Returns string containing shortest path between from and to
// Pathfinder method
// Params: Node pointers to find shortest path between from and to nodes
// Return: String containing the path between from and to, nothing if no path
string Graph::pathfinder(Node* from, Node* to) {
    // infinity = numeric_limits<int>::max()
    queue<Node*> toSearch;
    
    // Return blank if either params are NULL
    if (from == NULL || to == NULL) return "";
    
    // Set all nodes' dist to maximum int size and prev to NULL
    for (unsigned int k = 0; k < nodes.size(); k++) {
        nodes[k]->dist = numeric_limits<int>::max();
        nodes[k]->prev = NULL;
    }
    
    // Push from node onto queue
    toSearch.push(from);
    // Set dist and visited of from to 0 and true, respectively
    from->dist = 0;
    from->visited = true;
    Node* curr = from;
    // While the queue is not empty
    while (!toSearch.empty()) {
        // Get the front of the queue and pop it
        curr = toSearch.front();
        toSearch.pop();
        // For each neighbor of curr
        for (unsigned int i = 0; i < curr->adj.size(); i++) {
            Node* n = curr->adj[i];
            // If the dist of the node is maximum int size, change its dist to curr's dist + 1,
            // prev to curr, visited to true, and push it onto the queue
            if (n->dist == numeric_limits<int>::max()) {
                n->dist = curr->dist+1;
                n->prev = curr;
                n->visited = true;
                toSearch.push(n);
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
    
    // If no path, return blank
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

/*
 * Given an integer k, returns a list of nodes, sorted by id,
 * such that all nodes in the list are connected to at least
 * k other nodes.
 * param k the core number
 * return vector of node pointers that are in k-core
 */
vector<Node*> Graph::socialgathering(const int k) {
    
    vector<Node*> toInvite;
    
    // copy nodes to toInvite vector
    for (unsigned int i = 0; i < nodes.size(); i++) {
        toInvite.push_back(nodes[i]);
    }
    
    while(1) {
        // get iterator that points to node with smallest degree
        vector<Node*>::iterator minDeg = min_element(toInvite.begin(), toInvite.end(), compareDegrees);
        
        // get node with min degree
        Node * minDegNode = *minDeg;
        
        // if minDegNode's degree < k,
        if (minDegNode->degree < k) {
            
            // then: for each of its neighbors, n:
            for (unsigned int j = 0; j < minDegNode->adj.size(); j++) {
                Node * n = minDegNode->adj[j];
                
                // if deg(n) > deg(curr)
                if (n->degree > minDegNode->degree) {
                    
                    // decrement n's degree
                    n->degree = n->degree - 1;
                }
            }
            
            // remove the element from toInvite
            toInvite.erase(minDeg);
            
        } else {
            // if minDegNode's degree > k,
            // then all remaining nodes in toInvite are core-k
            break;
        }
    }
    
    // sort toInvite by id
    sort(toInvite.begin(), toInvite.end(), compareIds);
    
    // return list of invitees
    return toInvite;
}

// Compares two nodes by their degrees
bool Graph::compareDegrees(Node* n1, Node* n2) {
    return n1->degree < n2->degree;
}

// Compares two nodes by their ids
bool Graph::compareIds(Node* n1, Node* n2) {
    return stoi(n1->id) < stoi(n2->id);
}
