#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int up = findUPar(u);
        int vp = findUPar(v);

        if (up == vp) return;

        if (size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};

void kruskal(int n, vector<pair<int, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end()); 

    DSU ds(n);
    int mst_weight = 0;

    cout << "Edges in MST:\n";
    for (auto edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.findUPar(u) != ds.findUPar(v)) {
            ds.unionBySize(u, v);
            mst_weight += wt;
            cout << u << " - " << v << " : " << wt << "\n";
        }
    }

    cout << "Total weight of MST: " << mst_weight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges; 

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    kruskal(n, edges);

    return 0;
}
