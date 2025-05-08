/*
Author - Shantanu Wable
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<int>> adjMatrix;        // Stores distances between cities (0 if no road)
    int vertexCount;                      // Total number of cities
    map<string, int> cities;              // City name -> index
    map<int, string> inv_cities;          // Index -> city name

    // Adds a road (edge) between two cities with a given distance
    void add(string city1, string city2, int dist) {
        adjMatrix[cities[city1]][cities[city2]] = dist;
        adjMatrix[cities[city2]][cities[city1]] = dist; // undirected
    }

    // Finds the city with the smallest key value not yet in MST
    int minimum_key(vector<int>& key, vector<bool>& mst) {
        int minValue = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < vertexCount; i++) {
            if (!mst[i] && key[i] < minValue) {
                minValue = key[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

public:
    Graph() {
        vector<string> cityList = {"Pune", "Mumbai", "Nashik", "Nagpur"};
        vertexCount = cityList.size();

        // Create a square matrix and fill it with 0s
        adjMatrix = vector<vector<int>>(vertexCount, vector<int>(vertexCount, 0));

        // Assign index to each city
        for (int i = 0; i < vertexCount; i++) {
            cities[cityList[i]] = i;
            inv_cities[i] = cityList[i];
        }

        // Add roads between cities
        add("Pune", "Mumbai", 10);
        add("Pune", "Nashik", 15);
        add("Mumbai", "Nashik", 5);
        add("Mumbai", "Nagpur", 20);
        add("Nashik", "Nagpur", 30);
    }

    void prim() {
        vector<int> parent(vertexCount);        // Stores the parent of each city in MST
        vector<int> key(vertexCount, INT_MAX);  // Minimum distance to include in MST
        vector<bool> mst(vertexCount, false);   // Keeps track of cities included in MST

        key[0] = 0;         // Start from first city
        parent[0] = -1;     // First city has no parent

        for (int count = 0; count < vertexCount - 1; count++) {
            // Pick city with smallest key not yet included
            int u = minimum_key(key, mst);
            mst[u] = true;  // Include it in MST

            // Update keys of its neighbors
            for (int v = 0; v < vertexCount; v++){
                if (adjMatrix[u][v] && !mst[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // Print the Minimum Spanning Tree
        cout << "MST of given graph:\n";
        cout << "\nEdge \t Weight\n";
        for (int i = 1; i < vertexCount; i++) {
            cout << inv_cities[parent[i]] << " <-> " << inv_cities[i]
                 << " \t " << adjMatrix[i][parent[i]] << endl;
        }
    }
};

int main() {
    Graph g;
    g.prim();  // Run Prim's Algorithm
    return 0;
}
