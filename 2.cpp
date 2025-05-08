#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int g, h;        //g: Number of steps taken so far.
                     //h: Heuristic (how far we are from the goal).
    Node* parent;    //Points to the parent state (used for backtracking the solution path).
    
    Node(vector<vector<int>> s, int g_cost, int h_cost, Node* p = nullptr)
        : state(s), g(g_cost), h(h_cost), parent(p) {}
    
    int f() const { return g + h; } // f(n) = g(n) + h(n)
    
    bool operator>(const Node& other) const { return f() > other.f(); }
};

vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,-1}};

//counts how many tiles are not in their correct place
int heuristic(const vector<vector<int>>& state) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] != -1 && state[i][j] != goal[i][j]) {
                count++;
            }
        }
    }
    return count;
}
//Finding the Blank (Empty) Tile
pair<int, int> findBlank(const vector<vector<int>>& state) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] == -1) return {i, j};
        }
    }
    return {-1, -1};
}

// Generating Next Possible States
vector<vector<vector<int>>> getSuccessors(const vector<vector<int>>& state) {
    vector<vector<vector<int>>> successors;
    pair<int, int> pos = findBlank(state);
    int x = pos.first, y = pos.second;
    vector<pair<int, int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};   //Generates 4 possible moves (up, down, left, right).
    
    for (auto move : moves) {
        int dx=move.first,dy=move.second;
        int newX = x + dx, newY = y + dy;
        if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
            vector<vector<int>> newState = state;
            swap(newState[x][y], newState[newX][newY]);  // Swaps the blank tile with a neighboring tile to create new valid states.
            successors.push_back(newState);  // Only valid moves (within bounds) are added to successors.
        }
    }
    return successors;
}

void printPath(Node* node) {
    if (!node) return;
    printPath(node->parent);  //Recursively prints the path from the initial state to the goal state using the parent pointers.
    cout << "Step:\n";
    for (auto row : node->state) {
        for (int num : row) cout << (num == -1 ? "_ " : to_string(num) + " ");
        cout << "\n";
    }
    cout << "\n";
}

//Solving the Puzzle using A* Search
void solve8Puzzle(vector<vector<int>> initial) {
    priority_queue<Node, vector<Node>, greater<Node>> pq; //A min-heap priority queue is used (based on f() value).
    set<vector<vector<int>>> visited; //visited keeps track of already-explored states to prevent revisits.
    
    pq.emplace(initial, 0, heuristic(initial), nullptr); //Insert the initial node with g = 0, and heuristic h.
    
    while (!pq.empty()) {
        Node current = pq.top();
         pq.pop();
        if (current.state == goal) {   //If it is the goal, print the solution and exit.
            cout << "Solution found!\n";
            printPath(&current);
            return;
        }
        visited.insert(current.state);  //Otherwise, mark this state as visited.
        
        for (auto next : getSuccessors(current.state)) {
            if (visited.find(next) == visited.end()) {  // If a successor is not visited, calculate its g + 1 and h, then push it into the priority queue.
                pq.emplace(next, current.g + 1, heuristic(next), new Node(current));
            }
        }
    }
    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>>initial={{1,2,-1},{4,5,3},{7,8,6}};
    solve8Puzzle(initial);
    return 0;
}
