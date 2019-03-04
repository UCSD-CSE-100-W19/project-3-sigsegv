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
//#include "Graph.cpp"

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
    
    Graph * g = new Graph();
    
    // open graph file
    ifstream graphfile(graph_filename);
    string id1, id2;
    
    // read in all ids from graph_filename
    while (graphfile >> id1 >> id2) {
        // add nodes and edges to graph
        g->addNodesAndEdge(id1, id2);
    }
    // close infile
    graphfile.close();
    
    // open pairs file
    ifstream pairfile(pairs_filename);
    // open output file
    ofstream fout(output_filename);
    
    // get pairs from file
    string shortestPath;
    string p1, p2;
    while (pairfile >> p1 >> p2) {
        Node * node1 = g->getNode(p1);
        Node * node2 = g->getNode(p2);
        shortestPath = g->pathfinder(node1, node2);
        fout << shortestPath;
        if (!pairfile.eof()) {
            fout << "\n";
        }
    }
    // close in/out file
    pairfile.close();
    fout.close();
    
    return 0;
}
