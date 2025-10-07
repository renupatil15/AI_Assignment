#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


void bfs(int start, const vector<vector<int>>& graph) 
{
    queue<int> q;
    unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) 
	{
        int node = q.front();
        q.pop();

        cout << node << " ";

     
        for (int neighbor : graph[node]) 
		{
            if (visited.find(neighbor) == visited.end()) 
			{
                q.push(neighbor);
                visited.insert(neighbor);
            }
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

    cout << "BFS starting from node 0: ";
    bfs(0, graph);
    cout << endl;

    return 0;
}
