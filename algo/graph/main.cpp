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
    cout << Utils::matrixToStringCharVertex(g.getMatrix(), g.getSize()) << endl;
    cout << "Degree of A: " << g.degree('A') << endl;
    cout << "Is weighted: " << g.isWeighted() << endl;
    cout << "Is directed: " << g.isDirected() << endl;
    cout << "Is connected: " << g.isConnected() << endl;

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
    const Graph g_prim = Graphs::getPrimGraph();

    cout << "Second graph g_prim:" << endl;
    cout << g_prim << endl;

    cout << "Is weighted: " << g_prim.isWeighted() << endl;
    cout << "Is directed: " << g_prim.isDirected() << endl;
    cout << "Is connected: " << g_prim.isConnected() << endl;

    cout << endl << "Prim: ";
    g_prim.prim(Graph::printVertex);

    cout << endl << "Dijkstra: ";
    g_prim.dijkstra(Graph::printVertex);

    cout << endl << endl;
}

void printHenriqueGraph() {
    const Graph g_prim = Graphs::getPrimGraph();

    cout << "Second graph g_prim:" << endl;
    cout << g_prim << endl;

    cout << "Is weighted: " << g_prim.isWeighted() << endl;
    cout << "Is directed: " << g_prim.isDirected() << endl;
    cout << "Is connected: " << g_prim.isConnected() << endl;

    cout << endl << "Prim: ";
    g_prim.prim(Graph::printVertex);

    cout << endl << "Dijkstra: ";
    g_prim.dijkstra(Graph::printVertex);

    cout << endl << endl;
}

int main() {
    printBasicGraph();
    printPrimGraph();

    return 0;
}
