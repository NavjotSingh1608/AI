#include<bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<pair<int,int>>> &edges){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});

    vector<int> vis(n+1,0);

    int wt = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int dis = it.first, node = it.second;
        if(vis[node] == 1) continue;

        wt += dis;
        vis[node] = 1;

        for(auto it : edges[node]){
            if(!vis[it.first]){
                pq.push({it.second,it.first});
            }
        }
    }

    return wt;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Add undirected edges: u -- v with weight w
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "Minimum Spanning Tree cost: " << spanningTree(V, adj) << endl;

    return 0;
}
