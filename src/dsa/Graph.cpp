#include "dsa/Graph.hpp"

Graph::Graph(int vertices) : V(vertices), adj(vertices) {}

void Graph::addEdge(int u, int v, int w, bool undirected) {
    adj[u].push_back({v, w});
    if (undirected)
        adj[v].push_back({u, w});
}

vector<int> Graph::bfs(int start) {
    vector<int> result;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);

        for (auto& nbr : adj[node]) {
            if (!visited[nbr.first]) {
                visited[nbr.first] = true;
                q.push(nbr.first);
            }
        }
    }

    return result;
}

void Graph::dfsUtil(int node, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (auto& nbr : adj[node]) {
        if (!visited[nbr.first]) {
            dfsUtil(nbr.first, visited, result);
        }
    }
}

vector<int> Graph::dfs(int start) {
    vector<int> result;
    vector<bool> visited(V, false);
    dfsUtil(start, visited, result);
    return result;
}

vector<int> Graph::dijkstra(int start) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int d = top.first;
        int node = top.second;

        for (auto& nbr : adj[node]) {
            int next = nbr.first;
            int w = nbr.second;

            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}
