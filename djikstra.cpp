#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // For undirected graph
    }

    dijkstra(adj, n);

    return 0;
}
