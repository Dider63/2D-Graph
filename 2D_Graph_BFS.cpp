#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to add edge to adjacency list
void addEdge(vector<vector<int>> &adj, int source, int destination) {
    adj[source].push_back(destination);
    // If graph is undirected, also add reverse edge:
    // adj[destination].push_back(source);
}

// Function to print adjacency list
void printGraph(vector<vector<int>> &adj) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// BFS traversal
void BFS(vector<vector<int>> &adj, int source) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    cout << "\nBFS Traversal starting from " << source << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    printGraph(adj);

    int start;
    cout << "Enter source vertex for BFS: ";
    cin >> start;

    BFS(adj, start);

    return 0;
}
