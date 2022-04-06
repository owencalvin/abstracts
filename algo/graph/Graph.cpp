//
// Created by owen on 21/02/2022.
//

#include <vector>
#include <stack>
#include <queue>
#include "Graph.h"
#include "Utils.h"
#include "MinHeap.h"

using namespace std;

Graph::Graph(int size) {
    this->size = size;
    this->matrix = new int *[this->size];

    // Initialize the matrix and fill it with zeros
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

string Graph::toString() const {
    return Utils::matrixToString(this->matrix, this->size);
}

ostream &operator<<(ostream &os, const Graph &graph) {
    os << graph.toString();
    return os;
}

void Graph::addArc(int i, int j, int p) {
    this->matrix[i][j] = p;
    this->matrix[j][i] = p;
}

void Graph::addOrientedGraph(int i, int j, int p) {
    this->matrix[i][j] = p;
}

int Graph::degree(int i) const {
    int deg = 0;

    // Count the number of vertices that are connected the selected vertex
    // => If the weight of the arc between i and j is greater than zero then they are connected
    for (int j = 0; j < this->size; ++j) {
        if (this->matrix[i][j] > 0) {
            deg++;
        }
    }

    return deg;
}

bool Graph::isWeighted() const {
    // If only one of the arc in the matrix is greater or less than 1 (or -1) then the graph is considered as weighted
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (abs(this->matrix[i][j]) != 1) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isDirected() const {
    // If an arc point from A to B but not from B to A then the graph is directed
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (this->matrix[i][j] != this->matrix[j][i]) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isConnected() const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    int *priorityBase = new int(0);
    this->iterativePriorityFirstVertexVisit(0, visited, met, nullptr, priorityBase, -1);

    for (int i = 0; i < this->size; ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    delete[] visited;
    delete[] met;
    delete priorityBase;

    return true;
}

// region recursive depth-first search

void Graph::recursiveDepthFirstSearch() const {
    this->recursiveDepthFirstSearch(nullptr);
}

void Graph::recursiveDepthFirstSearch(void (*f)(int)) const {
    bool *visited = Utils::initArray<bool>(false, this->size);

    for (int i = 0; i < this->size; ++i) {
        this->recursiveDepthFirstVertexVisit(i, visited, f);
    }

    delete[] visited;
}

void Graph::recursiveDepthFirstVertexVisit(int vertex, bool *visited, void (*f)(int)) const {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;

    if (f != nullptr) {
        f(vertex);
    }

    for (int i = 0; i < this->size; i++) {
        if (this->matrix[vertex][i] != 0) {
            this->recursiveDepthFirstVertexVisit(i, visited, f);
        }
    }
}

// endregion

// region iterative depth-first search

void Graph::iterativeDepthFirstSearch() const {
    this->iterativeDepthFirstSearch(nullptr);
}

void Graph::iterativeDepthFirstSearch(void (*f)(int)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; ++i) {
        this->iterativeDepthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeDepthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int)) const {
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

        for (int i = 0; i < this->size; i++) {
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

void Graph::iterativeBreadthFirstSearch() const {
    this->iterativeDepthFirstSearch(nullptr);
}

void Graph::iterativeBreadthFirstSearch(void (*f)(int)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; ++i) {
        this->iterativeBreadthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeBreadthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int)) const {
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

        for (int i = 0; i < this->size; i++) {
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

void Graph::iterativePriorityFirstSearch(int priority) const {
    this->iterativePriorityFirstSearch(nullptr, priority);
}

void Graph::iterativePriorityFirstSearch(void (*f)(int), int priority) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);
    int *priorityBase = new int(0);

    for (int i = 0; i < this->size; ++i) {
        this->iterativePriorityFirstVertexVisit(i, visited, met, f, priorityBase, priority);
    }

    delete[] visited;
    delete[] met;
    delete priorityBase;
}

void Graph::iterativePriorityFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(int), int *priorityBase,
                                              int priority) const {
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

        for (int i = 0; i < this->size; i++) {
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

// region Prim

void Graph::prim() const {
    this->prim(nullptr);
}

void Graph::prim(void (*f)(int)) const {
    bool *visited = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; ++i) {
        this->primVertexVisit(i, visited, f);
    }
}

void Graph::primVertexVisit(int vertex, bool *visited, void (*f)(int)) const {
    if (visited[vertex]) {
        return;
    }

    MinHeap mh;
    mh.insert(INT_MAX, vertex);

    while (!mh.empty()) {
        vertex = mh.extractMinimum().second;
        visited[vertex] = true;

        if (f != nullptr) {
            f(vertex);
        }

        for (int i = 0; i < this->size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i]) {
                    int priority = this->matrix[vertex][i];
                    mh.insert(priority, i);
                }
            }
        }
    }
}

// endregion

// region Dijkstra

void Graph::dijkstra() const {
    this->dijkstra(nullptr);
}

void Graph::dijkstra(void (*f)(int)) const {
    bool *visited = Utils::initArray<bool>(false, this->size);

    dijkstraVertexVisit(0, visited, f);
}

void Graph::dijkstraVertexVisit(int vertex, bool *visited, void (*f)(int)) const {
    if (visited[vertex]) {
        return;
    }

    MinHeap mh;
    mh.insert(0, vertex);

    while (!mh.empty()) {
        pair<int, int> priority_vertex = mh.extractMinimum();
        int current_vertex_priority = mh.extractMinimum().first;
        vertex = priority_vertex.second;

        visited[vertex] = true;

        if (f != nullptr) {
            f(vertex);
        }

        for (int i = 0; i < this->size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i]) {
                    int priority = current_vertex_priority + this->matrix[vertex][i];
                    mh.insert(priority, i);
                }
            }
        }
    }
}

// endregion

// region Connected vertices

void Graph::connectedVertices() const {
    this->connectedVertices(nullptr);
}

void Graph::connectedVertices(void (*f)(vector<int>)) const {
    int *mark = Utils::initArray(0, this->size);
    int *n = new int(0);
    auto *q = new stack<int>;

    for (int i = 0; i < this->size; ++i) {
        if (mark[i] == 0) {
            this->visitConnectedVertex(i, mark, n, q, f);
        }
    }

    delete[] mark;
    delete q;
    delete n;
}

// FIX: Visit connected vertices
int Graph::visitConnectedVertex(int vertex, int mark[], int* n, stack<int> *q, void (*f)(vector<int>)) const {
    (*n)++;
    int minimum = *n;
    mark[vertex] = 1;
    q->push(vertex);

    for (int i = 0; i < this->size; i++) {
        if (this->matrix[vertex][i] != 0) {
            int M = mark[i];

            if (mark[i] == 0) {
                M = this->visitConnectedVertex(i, mark, n, q, f);
            }

            minimum = min(minimum, M);
        }
    }

    if (minimum == mark[vertex]) {
        vector<int> connectedVertices;

        int v = INT_MIN;
        while (v != vertex) {
            v = q->top();
            mark[v] = this->size + 1;
            connectedVertices.push_back(v);
            q->pop();
        }

        if (f != nullptr) {
            f(connectedVertices);
        }
    }

    return minimum;
}

// endregion
