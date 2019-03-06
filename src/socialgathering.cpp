//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// socialgathering.cpp
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
    << " friendship_pairs_file k_value output_file"
    << endl;
    exit(-1);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }
    char* graph_filename = argv[1];
    char* output_filename = argv[3];
    
    istringstream ss(argv[2]);
    
    string str = ss.str();
    
    int k = stoi(str);
    
    // make a new Graph
    Graph * g = new Graph();
    
    // open graph file
    ifstream graphfile(graph_filename);
    string id1, id2;
    
    // read in all ids from graphfile
    while (graphfile >> id1 >> id2) {
        // add nodes and edges to graph
        g->addNodes(id1, id2);
    }
    
    // close graphfile
    graphfile.close();
    
    // open output file
    ofstream fout(output_filename);
    
    // get invitees
    vector<Node*> invitees = g->socialgathering(k);
    
    for (int i=0; i<invitees.size(); i++) {
        fout << invitees[i]->id;
        if (i != invitees.size()-1) {
            fout << "\n";
        }
    }

    // close output file
    fout.close();
    
    delete g;
    return 0;
}
