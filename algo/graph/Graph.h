//
// Created by owen on 21/02/2022.
//

#pragma once

#include <ostream>
#include <stack>

using namespace std;

class Graph {
private:
    int **matrix;
    int size = 0;

    void recursiveDepthFirstVertexVisit(int vertex, bool visited[], void (*f)(int)) const;

    void iterativeDepthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int)) const;

    void iterativeBreadthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int)) const;

    void iterativePriorityFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int), int *priorityBase,
                                           int priority) const;

    void primVertexVisit(int vertex, bool visited[], void (*f)(int)) const;

    void dijkstraVertexVisit(int vertex, bool visited[], void (*f)(int)) const;

    int visitConnectedVertex(int vertex, int mark[], int* n, stack<int> *q, void (*f)(vector<int>)) const;

public:
    ~Graph();

    explicit Graph(int size);

    string toString() const;

    friend ostream &operator<<(ostream &os, const Graph &graph);

    /**
     * Add an arc between to vertices, from i to j and from j to i
     * @param i The first vertex
     * @param j The second vertex
     * @param p The weight of the arc
     */
    void addArc(int i, int j, int p = 1);

    /**
     * Add an arc that is oriented, from i to j but not from j to i
     * @param i The first vertex
     * @param j The second vertex
     * @param p The weight of the arc
     */
    void addOrientedGraph(int i, int j, int p = 1);

    /**
     * Get the degree of a vertex
     * @param i The vertex ID
     * @return The degree of the vertex
     */
    int degree(int i) const;

    /**
     * TODO: If the graph do not link all the vertex then the graph is not connected
     * @return True if the graph is connected
     */
    bool isConnected() const;

    /**
     * If an arc point from A to B but not from B to A then the graph is directed
     * @return True if the graph is directed
     */
    bool isDirected() const;


    /**
     * If only one of the arc in the matrix is greater or less than 1 (or -1) then the graph is considered as weighted
     * @return True if the arc is weighted
     */
    bool isWeighted() const;

    /**
     * Recursive implementation of the depth first search in a graph
     */
    void recursiveDepthFirstSearch() const;

    /**
     * Recursive implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void recursiveDepthFirstSearch(void (*f)(int)) const;

    /**
     * Iterative implementation of the depth first search in a graph
     */
    void iterativeDepthFirstSearch() const;

    /**
     * Iterative implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeDepthFirstSearch(void (*f)(int)) const;

    /**
     * Iterative implementation of the breadth first search in a graph
     */
    void iterativeBreadthFirstSearch() const;

    /**
     * Iterative implementation of the breadth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeBreadthFirstSearch(void (*f)(int)) const;

    /**
     * Iterative generic implementation to search in a graph, based on priority
     * A generic implementation of breadth first and depth first search
     * @param priority -1 for depth first search and 1 for breadth first search
     */
    void iterativePriorityFirstSearch(int priority = -1) const;

    /**
     * Iterative generic implementation to search in a graph, based on priority
     * A generic implementation of breadth first search and depth first search
     * @param f The function that operate on the vertex (example: printing the vertex)
     * @param priority -1 for depth first search and 1 for breadth first search
     */
    void iterativePriorityFirstSearch(void (*f)(int), int priority = -1) const;

    /**
     * Prim tree algorithm
     */
    void prim() const;

    /**
     * Prim tree algorithm
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void prim(void (*f)(int)) const;

    /**
     * Dijkstra tree algorithm
     */
    void dijkstra() const;

    /**
     * Dijkstra tree algorithm
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void dijkstra(void (*f)(int)) const;

    /**
     * Operate on a group of connected vertices
     */
    void connectedVertices() const;

    /**
     * Operate on a group of connected vertices
     * @param f The function that operate on the connected vertices
     */
    void connectedVertices(void (*f)(vector<int>)) const;
};
