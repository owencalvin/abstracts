#include <iostream>
#include <vector>
#include "Graph.h"
#include "Graphs.h"
#include "Utils.h"

using namespace std;

void printBasicGraph() {
    const Graph g = Graphs::getBasicGraph();

    cout << "First graph g:" << endl;
    cout << g << endl;

    cout << "Degree of A: " << g.degree('A') << endl;

    cout << "Connected vertices: ";
    g.connectedVertices(Graph::printVertices);
    cout << endl;

    cout << "Recursive depth first: ";
    g.recursiveDepthFirstSearch(Graph::printVertex);

    cout << endl << "Iterative depth first: ";
    g.iterativeDepthFirstSearch(Graph::printVertex);

    cout << endl << "Iterative breadth first: ";
    g.iterativeBreadthFirstSearch(Graph::printVertex);

    cout << endl << "Iterative priority first (=== depth first): ";
    g.iterativePriorityFirstSearch(Graph::printVertex, -1);

    cout << endl << "Iterative priority first (=== breadth first): ";
    g.iterativePriorityFirstSearch(Graph::printVertex, 1);

    cout << endl << endl;
}

void printPrimGraph() {
    const Graph g = Graphs::getPrimGraph();

    cout << "Second graph g:" << endl;
    cout << g;

    cout << endl << "Prim: ";
    g.prim(Graph::printVertex);

    cout << endl << "Dijkstra: ";
    g.dijkstra(Graph::printVertex);

    cout << endl << endl;
}

void printHenriqueGraph() {
    const Graph g = Graphs::getHenriqueGraph();

    cout << "Henrique graph g:" << endl;
    cout << g;
}

int main() {
    printBasicGraph();
    printPrimGraph();
    printHenriqueGraph();

    return 0;
}
