//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 3/9/19
//
// part3.cpp
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
    << " item_pairs_file item_id output_file"
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
    char* output_filename = argv[3];
    istringstream ss(argv[2]);
    string id = ss.str(); // id of Node to start from
    
    Graph * g = new Graph();
    
    // open graphfile
    ifstream graphfile(graph_filename);
    string id1, id2;
    
    // read in all ids from graph file
    while (graphfile >> id1 >> id2) {
        // add nodes and edges to graph
        g->addNodes(id1, id2);
    }
    // close graphfile
    graphfile.close();
    
    // open output file
    ofstream fout(output_filename);
    
    // get paths
    cout << "id = " << "'" << id << "'" << endl;
    cout << "g->containsNode(id) = " << g->containsNode(id) << endl;
    if (g->containsNode(id)) {
        Node * n = g->getNode(id);
        vector<string> paths = g->DFS(n);
        for (int i=0; i<paths.size(); i++) {
            fout << paths[i];
            if (i != paths.size()-1) {
                fout << "\n";
            }
        }
    } else {
        fout << "No paths found." << endl;
    }
    
    // close fout
    fout.close();
    
    delete g;
    return 0;
}
