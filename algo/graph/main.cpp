#include <iostream>
#include "Graph.h"

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

    cout << g.toString() << endl;
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
    g.iterativePriorityFirstSearch(printVertex, 1);

    cout << endl << "Iterative priority first (=== breadth first): ";
    g.iterativePriorityFirstSearch(printVertex, -1);

    return 0;
}
