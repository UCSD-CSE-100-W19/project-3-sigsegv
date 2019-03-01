//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// Graph.hpp
// CSE 100 Project 3

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

class Graph {
 protected:
  //MAYBE ADD CLASS DATA STRUCTURE(S) HERE
  vector<Node> nodes;
  vector<Edge> edges;

 public:
  Graph(void);

  ~Graph(void);

  //MAYBE ADD SOME MORE METHODS HERE SO AS TO ANSWER QUESTIONS IN YOUR PA
	
  /* YOU CAN MODIFY THIS IF YOU LIKE , in_filename : THE INPUT FILENAME */

  bool loadFromFile(const char* in_filename);

  bool pathfinder(Node* from, Node* to);
    
  void socialgathering(vector<string>& invitees, const int& k);

  void add(string to, string from);
};

#endif  // GRAPH_HPP
