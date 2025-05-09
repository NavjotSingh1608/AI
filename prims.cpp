#include <bits/stdc++.h>
using namespace std;

void prims(int n, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    int ans = 0;

    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        ans += wt;

        for (auto &[adjnode, edgewt] : adj[node]) {
            if (!vis[adjnode]) {
                pq.push({edgewt, adjnode});
            }
        }
    }

    cout << "Total weight of MST: " << ans << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n); // adj[u] = {v, weight}

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }

    prims(n, adj);

    return 0;
}
