//
// Created by owen on 21/02/2022.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

using namespace std;

class Graph {
private:
    int **matrix;
    int size = 0;

public:
    ~Graph();

    Graph(int size);

    string toString();

    void addArc(int i, int j, int p = 1);

    void addOrientedGraph(int i, int j, int p = 1);

    int deg(int i);

    bool isConnex();

    bool isOriented();

    bool isPondere();

    void vspr();

    void depthFirstSearch();
};


#endif //GRAPH_GRAPH_H
