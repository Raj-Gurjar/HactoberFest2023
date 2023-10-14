#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform topological sorting on a directed graph.
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];  // Create an adjacency list representation of the graph.

    // Fill the adjacency list.
    for (int i = 0; i < edges; i++) {
        int a = graph[i][0];
        int b = graph[i][1];
        adj[a].push_back(b);
    }

    vector<int> indegree(nodes, 0);  // Initialize an array to store the in-degrees of nodes.

    // Calculate in-degrees by iterating through the adjacency list.
    for (int i = 0; i < nodes; i++) {
        for (auto j : adj[i]) {
            indegree[j]++;
        }
    }

    queue<int> q;  // Initialize a queue for topological ordering.

    // Find nodes with an in-degree of 0 and push them into the queue.
    for (int i = 0; i < nodes; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;  // Initialize a vector to store the topological order.

    // Perform topological sorting using the queue.
    while (!q.empty()) {
        int curr_node = q.front();
        ans.push_back(curr_node);
        q.pop();

        // Update in-degrees and push nodes with in-degree 0 into the queue.
        for (auto neigh : adj[curr_node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    return ans;
}

int main() {
    int nodes, edges;

    // Read the number of nodes and edges.
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Initialize the 'graph' vector with 'edges' number of {a, b} vectors.
    vector<vector<int>> graph(edges, vector<int>(2));

    // Read edge information.
    cout << "Enter the edges (a b):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> graph[i][0] >> graph[i][1];
    }

    // Call the topologicalSort function to compute the topological ordering.
    vector<int> topologicalOrder = topologicalSort(graph, edges, nodes);

    // Print the topological ordering.
    cout << "Topological Order: ";
    for (int i = 0; i < topologicalOrder.size(); i++) {
        cout << topologicalOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
