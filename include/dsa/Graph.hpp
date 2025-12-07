#pragma once
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int vertices);

    void addEdge(int u, int v, int w = 1, bool undirected = true);

    vector<int> bfs(int start);
    vector<int> dfs(int start);
    vector<int> dijkstra(int start);
    
private:
    void dfsUtil(int node, vector<bool>& visited, vector<int>& result);
};
