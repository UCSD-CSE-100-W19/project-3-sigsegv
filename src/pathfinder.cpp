//
// Sunny Lau     cs100wav
// 2/26/19 
//
// pathfinder.hpp
// CSE 100 Project 3

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.hpp"

using namespace std;

void usage(char* program_name) {
    cerr << program_name << " called with incorrect arguments." << endl;
    cerr << "Usage: " << program_name
    << " friendship_pairs_file test_pairs_file output_file"
    << endl;
    exit(-1);
}

int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        usage(argv[0]);
    }
    
    char* graph_filename = argv[1];
    char* pairs_filename = argv[2];
    char* output_filename = argv[3];
    
    //TODO
    /* You can call the pathfinder function from here */
    ifstream infile(graph_filename);
    string id1, id2;
    while (infile >> id1 >> id2) {
        pathfinder(id1, id2);
    }

    /*
     // Move this to main()
     // if no path found, print empty line
     if (path.top() != *to) {
     cout << endl;
     return false;
     // else, print out path
     } else {
     while (!path.empty()) {
     cout << path.top() << " ";
     path.pop();
     }
     cout << endl;
     }
     */
}  


/*
 
 NOTES


bool Graph::pathfinder(Node* from, Node* to) {
    queue<Node> queue;
    stack<Node> path;
    queue.queue(*from);
    
    queue.enqueue(*from);
    *from.dist = 0;
    *from.visited = true;
    Node* curr = from;
    while (curr != to) {
        curr = queue.dequeue();
        //for each neighbor of curr
        for (int i = 0; i < curr.adj.size(); i++) {
            Node n = curr.adj[i];
            if (n.dist == INFINITY) {
                n.dist = curr.dist+1;
                n.prev = curr;
                n.visited = true;
                queue.enqueue(n);
            }
        }
    }
    // if no path found, print empty line
    if (path.top() != *to) {
        cout << endl;
        return false;
    // else, print out path
    } else {
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
    return true;
}

Graph()
protected:
vector<Node> nodes;
vector<Edge> edges;

void addNodeAndEdge(string to, string from) {
    Node toNode = new Node(to);
    Node fromNode = new Node(from);
    nodes.push_back(toNode);
    Edge newEdge = newEdge(toNode, fromNode)
    edges.push_back(newEdge);
}

Node()
protected:
string s;
bool visited;
Node* prev;
int dist;
vector<string> adj;
const int INFINITY = 2147483647;

visited = false;
prev = NULL;
dist = INFINITY;

Edge()
protected:
Node* to;
Node* from;
int weight;

to = NULL;
from = NULL;
weight = 1;

