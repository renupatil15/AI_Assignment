#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

struct Node {
    int x, y;
    int g, h; 
    Node* parent;

    int f() const { return g + h; } 
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f() > b->f();
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int rows, int cols, vector<vector<int>>& grid) {
    return (x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 0);
}

void aStar(vector<vector<int>>& grid, pair<int,int> start, pair<int,int> goal) {
    int rows = grid.size(), cols = grid[0].size();

    priority_queue<Node*, vector<Node*>, Compare> openList;
    map<pair<int,int>, bool> closedList;

    Node* startNode = new Node{start.first, start.second, 0,
                               heuristic(start.first, start.second, goal.first, goal.second), nullptr};

    openList.push(startNode);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->x == goal.first && current->y == goal.second) {
            cout << "Path found: ";
            vector<pair<int,int>> path;
            while (current != nullptr) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
    
            for (int i = path.size() - 1; i >= 0; i--)
                cout << "(" << path[i].first << "," << path[i].second << ") ";
            cout << endl;
            return;
        }

        closedList[{current->x, current->y}] = true;

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (isValid(nx, ny, rows, cols, grid) && !closedList[{nx, ny}]) {
                Node* neighbor = new Node{nx, ny, current->g + 1,
                    heuristic(nx, ny, goal.first, goal.second), current};
                openList.push(neighbor);
            }
        }
    }
    cout << "No path found!" << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int,int> start = {0, 0};
    pair<int,int> goal = {4, 4};

    aStar(grid, start, goal);

    return 0;
}
