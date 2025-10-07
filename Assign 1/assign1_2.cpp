#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, unordered_set<int>& visited) 
{
    cout << node << " ";
    visited.insert(node);

    for (int neighbor : graph[node]) 
	{
        if (visited.find(neighbor) == visited.end()) 
		{
            dfs(neighbor, graph, visited);
        }
    }
}
int main() 
{
    vector<vector<int>> graph = 
	{
        {1, 2},    
        {3, 4},   
        {5},      
        {},        
        {},        
        {}        
    };

    unordered_set<int> visited;
    cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}
