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

using namespace std;

Graph::Graph(void)
	: nodes(0) {}

	Graph::~Graph(void) {
		for (auto itr : nodes) {
			delete itr.second;
		}
	}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
//TODO

/* Read in relationships from an inputfile to create a graph */

bool Graph::loadFromFile(const char* in_filename) {
	ifstream infile(in_filename);

	vector<node> theGraph;

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

		//TODO - YOU HAVE THE PAIR OF IDS OF 2 FRIENDS IN 'RECORD'. WHAT DO NEED TO DO NOW? 
		// Add the edge to the graph
		// Call addNodeAndEdge

	}

	if (!infile.eof()) {
		cerr << "Failed to read " << in_filename << "!\n";
		return false;
	}

	infile.close();
	return true;
}

/* Implement pathfinder*/
//TODO 
bool Graph::pathfinder(Node* from, Node* to) {
	queue<Node> queue;
	for(int k = 0; k < nodes.size(); k++){
		nodes[i].dist = INFINITY;
		nodes[i].prev = NULL;  
	}

	stack<Node> path;
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
	// Reset dist to infinity for all nodes
	/*queue.push_back(*from);
	 *from.dist = 0;
	 Node* curr = from;
	 while(curr != to){
	 curr = queue.dequeue();
	//For all neighbors of curr
	for( int i = 0; i < curr.adj.size(); i++){
	Node n = curr.adj[i];
	if(n.dist == INFINITY){
	n.dist = curr.dist + 1;
	n.prev = curr;
	queue.enqueue(n);
	}
	}
	}
	return true;*/
}

/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {

}

void Graph::add(string to, string from){
	Node* newNode = new Node(to);
	bool inVector = false;

	for(Node n : nodes){
		if(*newNode != n)
			continue;
		else{
			inVector = true;
			break;
		}
	}
	if(inVector}
			nodes.push_back(newNode);

			Edge newEdge = new Edge(newNode, *prev);
			edges.push_back(newEdge);
			}
