#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define N 3

vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};

void printBoard(const vector<vector<int>>& board) {
    for (auto& r : board) {
        for (auto& num : r) cout << num << " ";
        cout << endl;
    }
    cout << "----------" << endl;
}

bool isGoalState(const vector<vector<int>>& board) {
    return board == goal;
}

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool dfs(vector<vector<int>>& board, int x, int y, int depth, int limit, set<vector<vector<int>>>& visited) {
    if (isGoalState(board)) {
        cout << "Goal reached at depth " << depth << endl;
        printBoard(board);
        return true;
    }
    if (depth >= limit) return false;

    visited.insert(board);

    for (int i = 0; i < 4; i++) {
        int newX = x + row[i];
        int newY = y + col[i];
        if (isValid(newX, newY)) {
            auto newBoard = board;
            swap(newBoard[x][y], newBoard[newX][newY]);
            if (visited.find(newBoard) == visited.end()) {
                if (dfs(newBoard, newX, newY, depth + 1, limit, visited))
                    return true;
            }
        }
    }
    return false;
}

bool IDDFS(vector<vector<int>>& start, int x, int y, int maxLimit) {
    for (int limit = 0; limit <= maxLimit; limit++) {
        set<vector<vector<int>>> visited;
        cout << "Searching at depth limit: " << limit << endl;
        if (dfs(start, x, y, 0, limit, visited))
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> start = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    int x = 1, y = 1;
    int maxDepth = 20;

    cout << "Initial State:" << endl;
    printBoard(start);

    if (!IDDFS(start, x, y, maxDepth)) {
        cout << "No solution found within depth " << maxDepth << endl;
    }

    return 0;
}
