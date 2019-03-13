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
//TODO
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
		// Push it onto the vector and insert into the hashmap with the id
		nodes.push_back(toNode);
		nodeMap[toNode->id] = toNode;
	} else {
		toNode = nodeMap[to];
	}

	// if from node not in graph
	if (!containsNode(from)) {
		// Make a new node
		fromNode = new Node(from);
		// Push it onto the vector and insert into the hashmap with the id
		nodes.push_back(fromNode);
		nodeMap[fromNode->id] = fromNode;
	} else {
		fromNode = nodeMap[from];
	}

	// add toNode to fromNode's adj vector
	fromNode->adj.push_back(toNode);
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

/* Implement pathfinder*/
// return string containing shortest path between from and to
// Pathfinder method
// Params: Node pointers to find shortest path between from and to nodes
// Return: String containing the path between from and to, nothing if no path
vector<string> Graph::DFS(Node* from) {
	// if from node is not in graph,
	// then there are no paths starting from it
	cout << "before checking from" << endl;
	if (from == NULL) return {};
	cout << "after checking from" << endl;
	vector<string> paths; // vector containing paths

	stack<Node*> toSearch;

	for (unsigned int i = 0; i < nodes.size(); i++){
		nodes[i]->visited = false;
		nodes[i]->prev = NULL;
	}

	toSearch.push(from);
	from->visited = true;

	while (!toSearch.empty()) {
		Node * curr = toSearch.top();
		string path = "";
		toSearch.pop();
		for (unsigned int i = 0; i < curr->adj.size(); i++) {
			Node * n = curr->adj[i];
			if (!n->visited){
				n->visited = true;
				n->prev = curr;
				toSearch.push(n);
			}
			if (n->adj.empty()) {
				path += " \n ";
				while(n->prev){
					path += n->id + " ";
					n = n->prev;
				}
				path += n->id;
			}
		}
		path = revOrder(path);
		cout << path << endl;
		paths.push_back(path);
	}

	/*for(unsigned int i = 0; i < paths.size(); i++){
		string str = paths[i];
		if(str.at(0) == ' ')
			str.erase(str.begin());
	}*/

	//unique(paths.begin(), paths.end());
	return paths;
}

string Graph::revOrder(string str) { 
	int i = str.length() - 1; 
	int start = i + 1; 
	int end = i + 1;
	string result = ""; 

	while(i >= 0) { 
		if(str[i] == ' ') { 
			start = i + 1; 
			while(start != end) 
				result += str[start++]; 

			result += ' '; 

			end = i; 
		} 
		i--; 
	} 
	start = 0; 
	while(start != end) 
		result += str[start++]; 

	return result; 
} 
