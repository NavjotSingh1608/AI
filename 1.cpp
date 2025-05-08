#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;
    
public:
    // Add edge to undirected graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // Recursive DFS implementation
    void recursiveDFS(int node, unordered_set<int>& visited) {
        visited.insert(node);
        cout << node << " ";
        
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                recursiveDFS(neighbor, visited);
            }
        }
    }
    
    // Wrapper for recursive DFS
    void DFS(int startNode) {
        unordered_set<int> visited;
        cout << "Depth-First Search (Recursive): ";
        recursiveDFS(startNode, visited);
        cout << endl;
    }
    
    // Iterative BFS implementation
    void BFS(int startNode) {
        unordered_set<int> visited;
        queue<int> q;
        
        visited.insert(startNode);
        q.push(startNode);
        
        cout << "Breadth-First Search: ";
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    
    // Adding edges to create an undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    
    // Perform searches starting from node 0
    g.DFS(0);
    g.BFS(0);
    
    return 0;
}