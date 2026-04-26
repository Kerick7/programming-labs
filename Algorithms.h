#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

bool isAcyclicHelper(Graph* g, int v, bool visited[], bool recStack[], int parent) {
    visited[v] = true; recStack[v] = true;
    int count = g->getNeighborsCount(v);
    for (int i = 0; i < count; i++) {
        int to = g->getNeighbor(v, i).to;
        if (!visited[to]) {
            if (!isAcyclicHelper(g, to, visited, recStack, v)) return false;
        } else if (g->getIsDirected() ? recStack[to] : to != parent) return false;
    }
    recStack[v] = false; return true;
}

bool isAcyclic(Graph* g) {
    bool visited[MAX_V] = {false}; bool recStack[MAX_V] = {false};
    for (int i = 0; i < g->getV(); i++) {
        if (!visited[i]) if (!isAcyclicHelper(g, i, visited, recStack, -1)) return false;
    }
    return true;
}

void dfsHelper(Graph* g, int v, bool visited[], bool sortByWeight) {
    visited[v] = true; cout << v << " ";
    int count = g->getNeighborsCount(v);
    Edge neighbors[MAX_V];
    for (int i = 0; i < count; i++) neighbors[i] = g->getNeighbor(v, i);

    // Bubble sort neighbors if needed
    if (sortByWeight) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (neighbors[j].weight > neighbors[j+1].weight) {
                    Edge temp = neighbors[j]; neighbors[j] = neighbors[j+1]; neighbors[j+1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < count; i++) {
        if (!visited[neighbors[i].to]) dfsHelper(g, neighbors[i].to, visited, sortByWeight);
    }
}

void traverseDFS(Graph* g, int start, bool sortByWeight) {
    bool visited[MAX_V] = {false};
    cout << "DFS (Start: " << start << ", Sorted by weight: " << (sortByWeight ? "Yes" : "No") << "): ";
    dfsHelper(g, start, visited, sortByWeight);
    cout << "\n";
}

void dijkstraCore(Graph* g, int start, double dist[]) {
    int V = g->getV(); bool visited[MAX_V];
    for (int i = 0; i < V; i++) { dist[i] = INF; visited[i] = false; }
    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        double minDist = INF; int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] <= minDist) { minDist = dist[i]; u = i; }
        }
        if (u == -1) break;
        visited[u] = true;

        int nCnt = g->getNeighborsCount(u);
        for (int i = 0; i < nCnt; i++) {
            Edge e = g->getNeighbor(u, i);
            if (!visited[e.to] && dist[u] != INF && dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
            }
        }
    }
}

void dijkstra(Graph* g, int start, int end = -1) {
    double dist[MAX_V];
    dijkstraCore(g, start, dist);

    if (end != -1) {
        cout << "Path from " << start << " to " << end << ": " << (dist[end] == INF ? -1 : dist[end]) << "\n";
    } else {
        cout << "Paths from " << start << " to all others:\n";
        for (int i = 0; i < g->getV(); i++) cout << "To " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}

void dijkstraAllPairs(Graph* g) {
    int V = g->getV();
    cout << "Paths between ALL vertices (All-to-All):\n";
    for (int i = 0; i < V; i++) {
        double dist[MAX_V];
        dijkstraCore(g, i, dist);
        cout << "From " << i << ": ";
        for (int j = 0; j < V; j++) cout << (dist[j] == INF ? -1 : dist[j]) << " ";
        cout << "\n";
    }
}

void topoHelper(Graph* g, int v, bool visited[], int stack[], int& topIndex) {
    visited[v] = true;
    int count = g->getNeighborsCount(v);
    for (int i = 0; i < count; i++) {
        int to = g->getNeighbor(v, i).to;
        if (!visited[to]) topoHelper(g, to, visited, stack, topIndex);
    }
    topIndex++;
    stack[topIndex] = v;
}

void topologicalSort(Graph* g) {
    if (!g->getIsDirected()) {
        cout << "Topological sort is only possible for directed graphs!\n"; return;
    }
    bool visited[MAX_V] = {false};
    int stack[MAX_V];
    int topIndex = -1;
    for (int i = 0; i < g->getV(); i++) {
        if (!visited[i]) topoHelper(g, i, visited, stack, topIndex);
    }
    cout << "Topological Sort: ";
    while (topIndex >= 0) {
        cout << stack[topIndex] << " ";
        topIndex--;
    }
    cout << "\n";
}

void stHelper(Graph* g, int u, bool visited[], double& totalWeight) {
    visited[u] = true;
    int count = g->getNeighborsCount(u);
    for (int i = 0; i < count; i++) {
        Edge e = g->getNeighbor(u, i);
        if (!visited[e.to]) {
            cout << u << " - " << e.to << " [w: " << e.weight << "]\n";
            totalWeight += e.weight;
            stHelper(g, e.to, visited, totalWeight);
        }
    }
}

double spanningTreeDFS(Graph* g, int start) {
    bool visited[MAX_V] = {false};
    double totalWeight = 0;
    stHelper(g, start, visited, totalWeight);
    return totalWeight;
}

int findParent(int i, int parent[]) {
    if (parent[i] == i) return i;
    return findParent(parent[i], parent);
}

double kruskalMST(Graph* g) {
    FullEdge edges[MAX_V * MAX_V];
    int edgeCount = g->getAllEdges(edges);

    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                FullEdge temp = edges[j]; edges[j] = edges[j+1]; edges[j+1] = temp;
            }
        }
    }

    int parent[MAX_V];
    for (int i = 0; i < g->getV(); i++) parent[i] = i;

    double mstWeight = 0;
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].from; int v = edges[i].to; double w = edges[i].weight;
        int root_u = findParent(u, parent);
        int root_v = findParent(v, parent);

        if (root_u != root_v) {
            parent[root_u] = root_v;
            mstWeight += w;
            cout << u << " - " << v << " [w: " << w << "]\n";
        }
    }
    return mstWeight;
}

#endif // ALGORITHMS_H