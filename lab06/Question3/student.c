#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    int dim = sizeof(g->adj) / sizeof(int);

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < i - 1; j++) {
            if(g->adj[i][j] == 1) { // if a node i maps to another node j
                for(int k = 0; k < dim; k++) { // check all of j's connections
                    if(k != j && k != i && g->adj[j][k] == 1 && g->adj[i][k] == 1) { // if j connects to another node k of which connects to i
                        return 1; //... a triangle exists
                    }
                }
            }
        }
    }

    return 0;
}
