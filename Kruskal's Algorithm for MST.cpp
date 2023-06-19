#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent, rank;
};

// Find set of an element
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Union of two sets
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges based on weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find minimum spanning tree using Kruskal's algorithm
void KruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result; // Stores the resulting MST
    int e = 0; // Index variable for the sorted edges

    // Sort all edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding edges to the MST until V-1 edges are added
    int i = 0;
    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not form a cycle, include it in the MST
        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }

    // Print the resulting MST
    cout << "Minimum Spanning Tree:" << endl;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " -- " << result[i].dest << " : " << result[i].weight << endl;
    }

    delete[] subsets;
}

int main() {
    Graph graph;
    cout << "Enter the number of vertices: ";
    cin >> graph.V;

    cout << "Enter the number of edges: ";
    cin >> graph.E;

    cout << "Enter " << graph.E << " edges and their weights (source, destination, weight):" << endl;
    for (int i = 0; i < graph.E; i++) {
        Edge edge;
        cin >> edge.src >> edge.dest >> edge.weight;
        graph.edges.push_back(edge);
    }

    // Find minimum spanning tree using Kruskal's algorithm
    KruskalMST(graph);

    return 0;
}

