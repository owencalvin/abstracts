//
// Created by owen on 08.04.22.
//

#include "Graph.h"

class Graphs {
public:
    static Graph getBasicGraph() {
        Graph g = Graph(11);

        g.addArc('A', 'B');
        g.addArc('A', 'F');
        g.addArc('A', 'G');
        g.addArc('A', 'C');
        g.addArc('F', 'D');
        g.addArc('F', 'E');
        g.addArc('G', 'E');
        g.addArc('I', 'J');
        g.addArc('I', 'K');

        return g;
    }

    static Graph getPrimGraph() {
        Graph g = Graph(11);

        g.addArc('A', 'B', 1);
        g.addArc('A', 'F', 4);
        g.addArc('A', 'G', 2);
        g.addArc('A', 'C', 2);
        g.addArc('C', 'J', 1);
        g.addArc('D', 'E', 1);
        g.addArc('F', 'D', 1);
        g.addArc('F', 'E', 3);
        g.addArc('G', 'C', 1);
        g.addArc('G', 'E', 1);
        g.addArc('H', 'C', 3);
        g.addArc('H', 'K', 1);
        g.addArc('I', 'J', 3);
        g.addArc('I', 'K', 1);
        g.addArc('J', 'K', 1);

        return g;
    }

    static Graph getHenriqueGraph() {
        Graph g = Graph(12);

        g.addArc('A', 'G', 2);
        g.addArc('A', 'J', 4);
        g.addArc('A', 'L', 3);
        g.addArc('B', 'H', 2);
        g.addArc('B', 'K', 1);
        g.addArc('D', 'E', 4);
        g.addArc('D', 'J', 5);
        g.addArc('D', 'F', 1);
        g.addArc('E', 'F', 2);
        g.addArc('E', 'G', 3);
        g.addArc('H', 'I', 1);
        g.addArc('J', 'L', 2);

        return g;
    }
};
