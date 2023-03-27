#include <vector>
#include<iostream>

using namespace std;

bool dfs(vector<vector<int>>& edges, int vertex, vector<bool>& visited) {
    if (visited[vertex] == 1) return true;

    visited[vertex] = true;
  
    for (int neighbor : edges[vertex]) {
        if (dfs(edges, neighbor, visited) == 1) return true;   
    }

    visited[vertex] = false;
    return false;
}

bool cycleInGraph(vector<vector<int>> edges) {

    vector<bool> visited(edges.size(), false);
  
    for (int vertex = 0; vertex < edges.size(); vertex++) {
      
        if (visited[vertex] == 0) {
          
            if (dfs(edges, vertex, visited)== 1) return true;
        }
    }

    return false;
}
