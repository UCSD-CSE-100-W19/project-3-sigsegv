//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// pathfinder.cpp
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

/*
 * Checks if program was called with correct number of arguments
 */
void usage(char* program_name) {
    cerr << program_name << " called with incorrect arguments." << endl;
    cerr << "Usage: " << program_name
    << " friendship_pairs_file test_pairs_file output_file"
    << endl;
    exit(-1);
}

/*
 * Reads in ids from a graph file and adds nodes/edges to the graph.
 * Given a list of pairs, prints out the shortest path between the
 * two nodes in an output file.
 * Arguments: A graph file, pairs file, and output file.
 */
int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        usage(argv[0]);
    }
    
    char* graph_filename = argv[1];
    char* pairs_filename = argv[2];
    char* output_filename = argv[3];
    
    Graph * g = new Graph();
    
    // open graphfile
    ifstream graphfile(graph_filename);
    string id1, id2;
    
    // read in all ids from graph file
    while (graphfile >> id1 >> id2) {
        // add nodes and edges to graph
        g->addNodesAndEdge(id1, id2);
    }
    // close graphfile
    graphfile.close();
    
    // open pairs file
    ifstream pairfile(pairs_filename);
    // open output file
    ofstream fout(output_filename);
    
    string shortestPath;
    string p1, p2;
    
    // read pairs from file
    while (pairfile >> p1 >> p2) {
        Node * node1 = g->getNode(p1);
        Node * node2 = g->getNode(p2);
        // find shortest path between node1 and node2
        shortestPath = g->pathfinder(node1, node2);
        // print path to output file
        fout << shortestPath;
        // don't print a new line at the end of the file
        if (!pairfile.eof()) {
            fout << "\n";
        }
    }
    
    // close pairfile and fout
    pairfile.close();
    fout.close();
    
    delete g;
    return 0;
}
