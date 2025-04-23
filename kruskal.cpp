#include<bits/stdc++.h>
using namespace std;

class DSU{
public :
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionbysize(int u, int v){
        int up = findUPar(u);
        int vp = findUPar(v);

        if(up == vp) return ;

        if(size[up] > size[vp]){
            parent[vp] = up;
            size[up] += size[vp];
        }else{
            parent[up] = parent[vp];
            size[vp] += size[up];
        }
    }
};


void kruskal(vector<pair<int,pair<int,int>>> edges, int n){
    sort(edges.begin(),edges.end());
    int maxWt = 0;

    DSU ds(n);
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)){
            maxWt += wt;
            ds.unionbysize(u,v);
        }
    }

    cout << "Total weight " << maxWt << endl;
}

int main(){
    int n = 6;
    vector<pair<int, pair<int, int>>> edges;

    // edges: {weight, {u, v}}
    edges.push_back({4, {1, 2}});
    edges.push_back({4, {1, 3}});
    edges.push_back({2, {2, 3}});
    edges.push_back({5, {2, 4}});
    edges.push_back({5, {3, 4}});
    edges.push_back({1, {4, 5}});
    edges.push_back({3, {5, 6}});
    edges.push_back({7, {4, 6}});

    kruskal(edges,n);
}