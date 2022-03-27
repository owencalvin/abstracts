//
// Created by owen on 21/02/2022.
//

#pragma once

#include "Vertex.h"

using namespace std;

class Graph {
private:
    int **matrix;
    int size = 0;

    void recursiveDepthFirstVertexVisit(int vertex, bool visited[], void (*f)(int));

    void iterativeDepthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int));

    void iterativeBreadthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int));

    void iterativePriorityFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(int), int *priorityBase,
                                           int priority);

    bool *getFalseVertexArray();

public:
    ~Graph();

    Graph(int size);

    string toString();

    void addArc(int i, int j, int p = 1);

    void addOrientedGraph(int i, int j, int p = 1);

    int degree(int i);

    bool isConnected();

    bool isDirected();

    bool isWeighted();

    /**
     * Recursive implementation of the depth first search in a graph
     */
    void recursiveDepthFirstSearch();

    /**
     * Recursive implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void recursiveDepthFirstSearch(void (*f)(int));

    /**
     * Iterative implementation of the depth first search in a graph
     */
    void iterativeDepthFirstSearch();

    /**
     * Iterative implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeDepthFirstSearch(void (*f)(int));

    /**
     * Iterative implementation of the breadth first search in a graph
     */
    void iterativeBreadthFirstSearch();

    /**
     * Iterative implementation of the breadth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeBreadthFirstSearch(void (*f)(int));

    /**
     * Iterative generic implementation to search in a graph, based on priority
     * A generic implementation of breadth first and depth first search
     * @param priority 1 for depth first search and -1 for breadth first search
     */
    void iterativePriorityFirstSearch(int priority = 1);

    /**
     * Iterative generic implementation to search in a graph, based on priority
     * A generic implementation of breadth first search and depth first search
     * @param f The function that operate on the vertex (example: printing the vertex)
     * @param priority 1 for depth first search and -1 for breadth first search
     */
    void iterativePriorityFirstSearch(void (*f)(int), int priority = 1);
};
