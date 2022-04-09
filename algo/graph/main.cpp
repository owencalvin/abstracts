#include <iostream>
#include <vector>
#include "Graph.h"
#include "Graphs.h"

using namespace std;

void printBasicGraph() {
    const Graph g = Graphs::getBasicGraph();

    cout << "First graph g:";
    cout << g << endl;

    cout << "Degree of A: " << g.degree('A') << endl;

    cout << "Connected vertices: ";
    g.connectedVertices();
    cout << endl;

    cout << "Recursive depth first: ";
    g.recursiveDepthFirstSearch();

    cout << endl << "Iterative depth first: ";
    g.iterativeDepthFirstSearch();

    cout << endl << "Iterative breadth first: ";
    g.iterativeBreadthFirstSearch();

    cout << endl << "Iterative priority first (=== depth first): ";
    g.iterativePriorityFirstSearch(-1);

    cout << endl << "Iterative priority first (=== breadth first): ";
    g.iterativePriorityFirstSearch(1);

    cout << endl << endl << endl;
}

void printPrimGraph() {
    const Graph g = Graphs::getPrimGraph();

    cout << "Second graph g:";
    cout << g;

    cout << endl << "Prim: " << endl;
    g.prim(true);

    cout << endl << "Dijkstra: " << endl;
    g.dijkstra(true);

    cout << endl << endl << endl;
}

void printHenriqueGraph() {
    const Graph g = Graphs::getHenriqueGraph();

    cout << "Henrique graph g:";
    cout << g;

    cout << endl << endl << endl;
}

int main() {
    printBasicGraph();
    printPrimGraph();
    printHenriqueGraph();

    return 0;
}
