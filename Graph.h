#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX_V = 50;
const double INF = 999999.0;

struct Edge {
    int to;
    double weight;
};

struct FullEdge {
    int from;
    int to;
    double weight;
};

class Graph {
protected:
    int V;
    bool isDirected;
public:
    Graph(int vertices, bool directed) { V = vertices; isDirected = directed; }
    virtual ~Graph() {}

    virtual void addEdge(int u, int v, double weight) = 0;
    virtual void print() = 0;

    virtual int getNeighborsCount(int u) = 0;
    virtual Edge getNeighbor(int u, int index) = 0;
    virtual int getAllEdges(FullEdge edgesArray[]) = 0;

    int getV() { return V; }
    bool getIsDirected() { return isDirected; }
};

class AdjMatrix : public Graph {
private:
    double matrix[MAX_V][MAX_V];
public:
    AdjMatrix(int vertices, bool directed) : Graph(vertices, directed) {
        for (int i = 0; i < MAX_V; i++) {
            for (int j = 0; j < MAX_V; j++) {
                if (i == j) matrix[i][j] = 0;
                else matrix[i][j] = INF;
            }
        }
    }
    void addEdge(int u, int v, double weight) override {
        matrix[u][v] = weight;
        if (!isDirected) matrix[v][u] = weight;
    }
    void print() override {
        cout << "--- Adjacency Matrix ---\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][j] == INF) cout << setw(6) << "INF";
                else cout << setw(6) << matrix[i][j];
            }
            cout << "\n";
        }
    }
    int getNeighborsCount(int u) override {
        int count = 0;
        for (int i = 0; i < V; i++) if (i != u && matrix[u][i] != INF) count++;
        return count;
    }
    Edge getNeighbor(int u, int index) override {
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (i != u && matrix[u][i] != INF) {
                if (count == index) { Edge e; e.to = i; e.weight = matrix[u][i]; return e; }
                count++;
            }
        }
        Edge emptyEdge; emptyEdge.to = -1; emptyEdge.weight = 0; return emptyEdge;
    }
    int getAllEdges(FullEdge edgesArray[]) override {
        int count = 0;
        for (int i = 0; i < V; i++) {
            int startJ = isDirected ? 0 : i + 1;
            for (int j = startJ; j < V; j++) {
                if (i != j && matrix[i][j] != INF) {
                    edgesArray[count].from = i; edgesArray[count].to = j; edgesArray[count].weight = matrix[i][j]; count++;
                }
            }
        }
        return count;
    }
};

class AdjList : public Graph {
private:
    Edge adj[MAX_V][MAX_V];
    int adjCount[MAX_V];
public:
    AdjList(int vertices, bool directed) : Graph(vertices, directed) {
        for (int i = 0; i < MAX_V; i++) adjCount[i] = 0;
    }
    void addEdge(int u, int v, double weight) override {
        adj[u][adjCount[u]].to = v; adj[u][adjCount[u]].weight = weight; adjCount[u]++;
        if (!isDirected) {
            adj[v][adjCount[v]].to = u; adj[v][adjCount[v]].weight = weight; adjCount[v]++;
        }
    }
    void print() override {
        cout << "--- Adjacency List ---\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j = 0; j < adjCount[i]; j++) {
                cout << "[" << adj[i][j].to << " | w:" << adj[i][j].weight << "] ";
            }
            cout << "\n";
        }
    }
    int getNeighborsCount(int u) override { return adjCount[u]; }
    Edge getNeighbor(int u, int index) override { return adj[u][index]; }
    int getAllEdges(FullEdge edgesArray[]) override {
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adjCount[i]; j++) {
                int to = adj[i][j].to;
                if (isDirected || i < to) {
                    edgesArray[count].from = i; edgesArray[count].to = to; edgesArray[count].weight = adj[i][j].weight; count++;
                }
            }
        }
        return count;
    }
};

void copyGraph(Graph* source, Graph* dest) {
    FullEdge edges[MAX_V * MAX_V];
    int count = source->getAllEdges(edges);
    for(int i = 0; i < count; i++) {
        dest->addEdge(edges[i].from, edges[i].to, edges[i].weight);
    }
}

void generateRandomGraph(Graph* g, int E) {
    int edgesAdded = 0;
    while (edgesAdded < E) {
        int u = rand() % g->getV();
        int v = rand() % g->getV();
        if (u != v) {
            g->addEdge(u, v, (rand() % 20) + 1);
            edgesAdded++;
        }
    }
}

#endif // GRAPH_H
