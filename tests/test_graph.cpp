#include <iostream>
#include <vector>
#include <cassert>

#include "../include/dsa/Graph.hpp"

using namespace std;

int main() {
    cout << "=== GRAPH MODULE TEST ===" << endl;

    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    // ----------- TEST BFS ----------- //
    vector<int> bfsResult = g.bfs(0);
    cout << "BFS from node 0: ";
    for (int x : bfsResult) cout << x << " ";
    cout << endl;

    assert(bfsResult[0] == 0);
    assert(bfsResult[1] == 1 || bfsResult[1] == 2); // Order can vary slightly


    // ----------- TEST DFS ----------- //
    vector<int> dfsResult = g.dfs(0);
    cout << "DFS from node 0: ";
    for (int x : dfsResult) cout << x << " ";
    cout << endl;

    assert(dfsResult[0] == 0);


    // ----------- TEST DIJKSTRA ----------- //
    vector<int> dijkstraResult = g.dijkstra(0);

    cout << "Dijkstra from node 0 (distances): ";
    for (int x : dijkstraResult) cout << x << " ";
    cout << endl;

    // Expected shortest distances:
    // 0 → 0 = 0
    // 0 → 1 = 2
    // 0 → 2 = 3  (0→1→2)
    // 0 → 3 = 9  (0→1→3)
    // 0 → 4 = 6  (0→1→2→4)

    assert(dijkstraResult[0] == 0);
    assert(dijkstraResult[1] == 2);
    assert(dijkstraResult[2] == 3);
    assert(dijkstraResult[4] == 6);

    cout << "\nALL GRAPH TESTS PASSED SUCCESSFULLY 🎉" << endl;

    return 0;
}
