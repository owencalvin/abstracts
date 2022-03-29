#include <iostream>
#include "Graph.h"
#include "MinHeap.h"
#include "Utils.h"

using namespace std;


void printVertex(int i) {
    cout << to_string(i) << " ";
}

int main() {
    Graph g = Graph(11);
    g.addArc(0, 1);
    g.addArc(0, 5);
    g.addArc(0, 6);
    g.addArc(0, 2);
    g.addArc(5, 3);
    g.addArc(5, 4);
    g.addArc(6, 4);
    g.addArc(8, 9);
    g.addArc(8, 10);

    cout << "First graph g:" << endl;
    cout << g << endl;
    cout << "Degree of 0: " << g.degree(0) << endl;
    cout << "Is weighted: " << g.isWeighted() << endl;
    cout << "Is directed: " << g.isDirected() << endl;

    cout << "Recursive depth first: ";
    g.recursiveDepthFirstSearch(printVertex);

    cout << endl << "Iterative depth first: ";
    g.iterativeDepthFirstSearch(printVertex);

    cout << endl << "Iterative breadth first: ";
    g.iterativeBreadthFirstSearch(printVertex);

    cout << endl << "Iterative priority first (=== depth first): ";
    g.iterativePriorityFirstSearch(printVertex, -1);

    cout << endl << "Iterative priority first (=== breadth first): ";
    g.iterativePriorityFirstSearch(printVertex, 1);

    cout << endl << endl;

    Graph g_prim = Graph(11);
    g.addArc(0, 1, 1);
    g.addArc(0, 5, 4);
    g.addArc(0, 6, 2);
    g.addArc(0, 2, 2);
    g.addArc(2, 9, 1);
    g.addArc(3, 4, 1);
    g.addArc(5, 3, 1);
    g.addArc(5, 4, 3);
    g.addArc(6, 2, 1);
    g.addArc(6, 4, 1);
    g.addArc(7, 2, 3);
    g.addArc(7, 10, 1);
    g.addArc(8, 9, 3);
    g.addArc(8, 10, 1);
    g.addArc(9, 10, 1);

    cout << "Second graph g_prim:" << endl;
    cout << g << endl;
    cout << "Is weighted: " << g.isWeighted() << endl;
    cout << "Is directed: " << g.isDirected() << endl;
    cout << endl << "Prim: ";
    g.prim(printVertex);
    cout << endl << "Dijkstra: ";
    g.dijkstra(printVertex);

    cout << endl;

    return 0;
}
