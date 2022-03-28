//
// Created by owen on 21/02/2022.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "Graph.h"
#include "MinHeap.h"

using namespace std;

Graph::Graph(int size) {
    this->size = size;
    this->matrix = new int *[this->size];

    for (int i = 0; i < this->size; i++) {
        this->matrix[i] = new int[this->size];

        for (int j = 0; j < this->size; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < this->size; ++i) {
        delete[] this->matrix[i];
    }
}

bool *Graph::getFalseVertexArray() {
    bool *arr = new bool[this->size];

    for (int i = 0; i < this->size; ++i) {
        arr[i] = false;
    }

    return arr;
}

string Graph::toString() {
    stringstream ss;

    ss << std::endl << "     ";

    for (int i = 0; i < this->size; ++i) {
        ss << i << "  ";
    }

    ss << std::endl << "   --";

    for (int i = 0; i < this->size; ++i) {
        ss << "---";
    }

    ss << std::endl;

    for (int i = 0; i < this->size; ++i) {
        ss << i << " |  ";

        for (int j = 0; j < this->size; ++j) {
            ss << matrix[i][j] << "  ";
        }
        ss << std::endl;
    }

    return ss.str();
}

void Graph::addArc(int i, int j, int p) {
    this->matrix[i][j] = p;
    this->matrix[j][i] = p;
}

void Graph::addOrientedGraph(int i, int j, int p) {
    this->matrix[i][j] = p;
}

int Graph::degree(int i) {
    int deg = 0;

    for (int j = 0; j < this->size; ++j) {
        if (this->matrix[i][j] > 0) {
            deg++;
        }
    }

    return deg;
}

bool Graph::isWeighted() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (abs(this->matrix[i][j]) > 1) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isDirected() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (this->matrix[i][j] != this->matrix[j][i]) {
                return true;
            }
        }
    }

    return false;
}

// region recursive depth-first search

void Graph::recursiveDepthFirstSearch() {
    this->recursiveDepthFirstSearch(nullptr);
}

void Graph::recursiveDepthFirstSearch(void (*f)(int)) {
    bool *visited = this->getFalseVertexArray();

    for (int i = 0; i < this->size; ++i) {
        this->recursiveDepthFirstVertexVisit(i, visited, f);
    }

    delete[] visited;
}

void Graph::recursiveDepthFirstVertexVisit(int vertex, bool *visited, void (*f)(int)) {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;

    if (f != nullptr) {
        f(vertex);
    }

    for (int i = 0; i < size; i++) {
        if (this->matrix[vertex][i] != 0) {
            this->recursiveDepthFirstVertexVisit(i, visited, f);
        }
    }
}

// endregion

// region iterative depth-first search

void Graph::iterativeDepthFirstSearch() {
    this->iterativeDepthFirstSearch(nullptr);
}

void Graph::iterativeDepthFirstSearch(void (*f)(int)) {
    bool *visited = this->getFalseVertexArray();
    bool *met = this->getFalseVertexArray();

    for (int i = 0; i < this->size; ++i) {
        this->iterativeDepthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeDepthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int)) {
    if (visited[vertex]) {
        return;
    }

    met[vertex] = true;
    stack<int> s;
    s.push(vertex);

    while (!s.empty()) {
        vertex = s.top();
        s.pop();
        visited[vertex] = true;

        if (f != nullptr) {
            f(vertex);
        }

        for (int i = 0; i < size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i] && !met[i]) {
                    met[i] = true;
                    s.push(i);
                }
            }
        }
    }
}

// endregion

// region iterative breadth-first search

void Graph::iterativeBreadthFirstSearch() {
    this->iterativeDepthFirstSearch(nullptr);
}

void Graph::iterativeBreadthFirstSearch(void (*f)(int)) {
    bool *visited = this->getFalseVertexArray();
    bool *met = this->getFalseVertexArray();

    for (int i = 0; i < this->size; ++i) {
        this->iterativeBreadthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeBreadthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int)) {
    if (visited[vertex]) {
        return;
    }

    queue<int> q;
    met[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        visited[vertex] = true;

        if (f != nullptr) {
            f(vertex);
        }

        for (int i = 0; i < size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i] && !met[i]) {
                    met[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

// endregion

// region iterative priority-first search

void Graph::iterativePriorityFirstSearch(int priority) {
    this->iterativePriorityFirstSearch(nullptr);
}

void Graph::iterativePriorityFirstSearch(void (*f)(int), int priority) {
    bool *visited = this->getFalseVertexArray();
    bool *met = this->getFalseVertexArray();
    int *priorityBase = new int(0);

    for (int i = 0; i < this->size; ++i) {
        this->iterativePriorityFirstVertexVisit(i, visited, met, f, priorityBase, priority);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativePriorityFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int), int* priorityBase, int priority) {
    if (visited[vertex]) {
        return;
    }

    // priority_queue<pair<int, int>> q;
    MinHeap mh;

    met[vertex] = true;
    *priorityBase += priority;
    // q.push(make_pair(*priorityBase, vertex));
    mh.insert(*priorityBase, vertex);

    // while (!q.empty()) {
    while (!mh.empty()) {
        // vertex = q.top().second;
        vertex = mh.extractMinimum().second;
        // q.pop();
        visited[vertex] = true;

        if (f != nullptr) {
            f(vertex);
        }

        for (int i = 0; i < size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i] && !met[i]) {
                    met[i] = true;
                    *priorityBase += priority;
                    // q.push(make_pair(*priorityBase, i));
                    mh.insert(*priorityBase, i);
                }
            }
        }
    }
}

// endregion
