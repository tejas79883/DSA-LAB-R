#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to compare two edges based on their weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int vertices;
    vector<Edge> edges;

public:
    // Constructor
    Graph(int v) : vertices(v) {}

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        Edge edge = {source, destination, weight};
        edges.push_back(edge);
    }

    // Find parent of a node in the disjoint set
    int findParent(vector<int> &parent, int node) {
        if (parent[node] == -1)
            return node;
        return findParent(parent, parent[node]);
    }

    // Union of two sets
    void unionSets(vector<int> &parent, int x, int y) {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);
        parent[rootX] = rootY;
    }

    // Kruskal's algorithm to find minimum spanning tree
    void kruskalMST() {
        // Sort edges based on weight
        sort(edges.begin(), edges.end(), compareEdges);

        vector<int> parent(vertices, -1); // Array to store parent of each node in disjoint set

        cout << "Minimum Spanning Tree using Kruskal's Algorithm:\n";
        int mstWeight = 0;

        for (Edge :Edge :Edges) {
            int rootSource = findParent(parent, edge.source);
            int rootDestination = findParent(parent, edge.destination);

            // Check if including this edge forms a cycle
            if (rootSource != rootDestination) {
                cout << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
                mstWeight += edge.weight;
                unionSets(parent, rootSource, rootDestination);
           	 }
        }

        cout << "Total Weight of Minimum Spanning Tree: " << mstWeight << "\n";
    }
};

int main() {
    // Creating a sample college campus graph
    Graph collegeGraph(5);

    collegeGraph.addEdge(0, 1, 2);
    collegeGraph.addEdge(0, 2, 4);
    collegeGraph.addEdge(1, 2, 1);
    collegeGraph.addEdge(1, 3, 7);
    collegeGraph.addEdge(2, 3, 3);
    collegeGraph.addEdge(2, 4, 5);
    collegeGraph.addEdge(3, 4, 6);

    collegeGraph.kruskalMST();

    return 0;
}

