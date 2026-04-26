/*
* Лабораторна робота №5 (Графи)
 * Обраний варіант:
 * Блок 0: Матриця суміжності (1) та Структура суміжності (2).
 * Блок 1: Перевірка ациклічності.
 * Блок 2: Обхід графа в глибину (DFS).
 * Блок 3: Алгоритм Дейкстри.
 * Блок 4: Алгоритм Кана (Топологічне сортування на основі DFS).
 * Блок 5: Кістякове дерево на основі DFS.
 * Блок 6: Мінімальне кістякове дерево (Kruskal).
 */

#include <iostream>
#include <ctime>
#include "Graph.h"
#include "Algorithms.h"

using namespace std;

void runDemo() {
    cout << "\n=== DEMO MODE ===\n";

    cout << "\n[Block 0] Creating directed graph (Adjacency List)...\n";
    AdjList g(6, true);
    g.addEdge(5, 2, 1); g.addEdge(5, 0, 2); g.addEdge(4, 0, 1);
    g.addEdge(4, 1, 3); g.addEdge(2, 3, 4); g.addEdge(3, 1, 1);
    g.print();

    cout << "\n[Block 0] Converting to Adjacency Matrix...\n";
    AdjMatrix gMatrix(6, true);
    copyGraph(&g, &gMatrix);
    gMatrix.print();

    cout << "\n[Block 1] Acyclicity check:\nResult: " << (isAcyclic(&g) ? "Graph is Acyclic" : "Graph contains cycles") << "\n";

    cout << "\n[Block 2] Depth First Search (DFS):\n";
    traverseDFS(&g, 5, false);
    traverseDFS(&g, 5, true);

    cout << "\n[Block 3] Dijkstra's Algorithm:\n";
    dijkstra(&g, 5, 1);
    cout << "---\n";
    dijkstra(&g, 5);
    cout << "---\n";
    dijkstraAllPairs(&g);

    cout << "\n[Block 4] Topological Sort:\n";
    topologicalSort(&g);

    cout << "\n[Block 5] Spanning Tree (via DFS):\n";
    double stWeight = spanningTreeDFS(&g, 5);
    cout << "Total Spanning Tree weight: " << stWeight << "\n";

    cout << "\n[Block 6] Minimum Spanning Tree (Kruskal):\n";
    cout << "(Building for the undirected version of the graph)\n";
    AdjMatrix undirG(6, false);
    copyGraph(&g, &undirG);
    cout << "MST Weight: " << kruskalMST(&undirG) << "\n";
}

void runBenchmark() {
    cout << "\n=== BENCHMARK MODE ===\n";
    int V = 30;

    AdjMatrix gMatrix(V, false);
    AdjList gList(V, false);

    cout << "Generating random graphs (Vertices=" << V << ", Edges=50)...\n";
    srand(time(0));
    generateRandomGraph(&gMatrix, 50);
    generateRandomGraph(&gList, 50);

    cout << "Measuring Dijkstra's Algorithm execution time (in " << CLOCKS_PER_SEC << " clock ticks per sec):\n";

    clock_t startM = clock();
    dijkstraAllPairs(&gMatrix);
    clock_t stopM = clock();
    cout << "-> Adjacency Matrix time: " << (stopM - startM) << "\n";

    clock_t startL = clock();
    dijkstraAllPairs(&gList);
    clock_t stopL = clock();
    cout << "-> Adjacency List time: " << (stopL - startL) << "\n";
}

void runInteractive() {
    cout << "\n=== INTERACTIVE MODE ===\n";
    int V;
    cout << "Enter number of graph vertices (max " << MAX_V << "): ";
    cin >> V;
    AdjList g(V, false);

    int choice = -1;
    while (choice != 0) {
        cout << "\n1. Add edge\n2. Print graph\n3. Check for cycles\n4. Find shortest path (Dijkstra)\n5. Find MST (Kruskal)\n0. Exit\nChoose action: ";
        cin >> choice;

        if (choice == 1) {
            int u, v; double w;
            cout << "Enter source, destination and weight (separated by space): ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.print();
        } else if (choice == 3) {
            cout << (isAcyclic(&g) ? "Graph is Acyclic" : "Graph contains cycles") << "\n";
        } else if (choice == 4) {
            int u, v;
            cout << "Enter start and end vertices: ";
            cin >> u >> v;
            dijkstra(&g, u, v);
        } else if (choice == 5) {
            cout << "MST Weight: " << kruskalMST(&g) << "\n";
        }
    }
}

int main() {
    int mode;
    cout << "Choose program mode:\n1. Demo\n2. Interactive\n3. Benchmark (Speed)\nYour choice: ";
    cin >> mode;

    if (mode == 1) runDemo();
    else if (mode == 2) runInteractive();
    else if (mode == 3) runBenchmark();
    else cout << "Unknown mode.\n";

    return 0;
}