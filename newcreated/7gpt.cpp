#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge between two offices
struct Edge {
    int to;
    int cost;
};

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int startNode) {
    int numNodes = graph.size();

    // Priority queue to store edges with their costs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a vector to store the minimum costs of each node
    vector<int> minCost(numNodes, INT_MAX);

    // Create a vector to store the parent of each node in the MST
    vector<int> parent(numNodes, -1);

    // Create a vector to track visited nodes
    vector<bool> visited(numNodes, false);

    // Start with the specified node
    pq.push(make_pair(0, startNode));
    minCost[startNode] = 0;

    // Run Prim's algorithm until all nodes are visited
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        // Traverse the adjacent edges of the current node
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int cost = edge.cost;

            // Update minimum cost and add the edge to the priority queue if it has a smaller cost
            if (!visited[v] && cost < minCost[v]) {
                minCost[v] = cost;
                parent[v] = u;
                pq.push(make_pair(cost, v));
            }
        }
    }

    // Print the minimum cost set of phone lines
    cout << "Minimum Cost Set of Phone Lines:\n";
    for (int i = 1; i < numNodes; ++i) {
        cout << "Office " << parent[i] << " - Office " << i << ": " << minCost[i] << "\n";
    }
}

int main() {
    int numOffices, numConnections;
    cout << "Enter the number of offices: ";
    cin >> numOffices;

    cout << "Enter the number of connections: ";
    cin >> numConnections;

    vector<vector<Edge>> graph(numOffices);

    cout << "Enter the connections and their costs:\n";
    for (int i = 0; i < numConnections; ++i) {
        int office1, office2, cost;
        cin >> office1 >> office2 >> cost;

        // Add edges for both directions since the graph is undirected
        graph[office1].push_back({ office2, cost });
        graph[office2].push_back({ office1, cost });
    }

    int startNode;
    cout << "Enter the starting office: ";
    cin >> startNode;

    primMST(graph, startNode);

    return 0;
}
