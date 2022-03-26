#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g = Graph(10);

    g.addArc(1, 3);
    g.addOrientedGraph(4, 2, 5);
    g.addOrientedGraph(4, 6, 3);

    cout << g.toString() << endl;
    cout << g.deg(4) << endl;
    cout << g.isPondere() << endl;
    cout << g.isOriented() << endl;

    return 0;
}
