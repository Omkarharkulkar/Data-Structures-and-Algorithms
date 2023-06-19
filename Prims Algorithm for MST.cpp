#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Function to find the vertex with minimum key value
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the minimum spanning tree
void printMST(vector<int>& parent, vector<vector<int> >& graph, int V) {
    cout << "Minimum Spanning Tree:" << endl;
    for (int v = 1; v < V; v++) {
        cout << parent[v] << " - " << v << " : " << graph[v][parent[v]] << endl;
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<int> >& graph, int V) {
    vector<int> parent(V); // Stores the parent of each vertex in the MST
    vector<int> key(V, INF); // Key values used to pick the minimum weight edge
    vector<bool> mstSet(V, false); // Set of vertices included in MST

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the resulting MST
    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int> > graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Find minimum spanning tree using Prim's algorithm
    primMST(graph, V);

    return 0;
}

