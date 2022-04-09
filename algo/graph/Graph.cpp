//
// Created by owen on 21/02/2022.
//

#include <vector>
#include <stack>
#include <queue>
#include <sstream>
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
    for (int i = 0; i < this->size; i++) {
        delete[] this->matrix[i];
    }
}

int Graph::getSize() const {
    return this->size;
}

int **Graph::getMatrix() const {
    return this->matrix;
}

string Graph::toStringIntVertex() const {
    return Utils::matrixToStringIntVertex(this->matrix, this->size);
}

string Graph::toStringCharVertex() const {
    return Utils::matrixToStringCharVertex(this->matrix, this->size);
}

string Graph::getInfos() const {
    stringstream ss;

    ss << Utils::matrixToStringCharVertex(this->matrix, this->size);
    ss << "Size: " << to_string(this->getSize()) << endl;
    ss << "Is weighted: " << Utils::boolToYesNo(this->isWeighted()) << endl;
    ss << "Is directed: " << Utils::boolToYesNo(this->isDirected()) << endl;
    ss << "Is connected: " <<  Utils::boolToYesNo(this->isConnected());

    return ss.str();
}

ostream &operator<<(ostream &os, const Graph &graph) {
    os << graph.getInfos();
    return os;
}

void Graph::addArc(char i, char j, int p) {
    const unsigned int iInt = Utils::getIndexInAlphabet(i);
    const unsigned int jInt = Utils::getIndexInAlphabet(j);

    this->matrix[iInt][jInt] = p;
    this->matrix[jInt][iInt] = p;
}

void Graph::addOrientedGraph(char i, char j, int p) {
    const unsigned int iInt = Utils::getIndexInAlphabet(i);
    const unsigned int jInt = Utils::getIndexInAlphabet(j);

    this->matrix[iInt][jInt] = p;
}

int Graph::degree(char i) const {
    const unsigned int iInt = Utils::getIndexInAlphabet(i);

    int deg = 0;

    // Count the number of vertices that are connected the selected vertex
    // => If the weight of the arc between i and j is greater than zero then they are connected
    for (int j = 0; j < this->size; ++j) {
        if (this->matrix[iInt][j] > 0) {
            deg++;
        }
    }

    return deg;
}

bool Graph::isWeighted() const {
    // If only one of the arc in the matrix is greater or less than 1 (or -1) then the graph is considered as weighted
    for (int i = 0; i < this->size; i++) {
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
    for (int i = 0; i < this->size; i++) {
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

    for (int i = 0; i < this->size; i++) {
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

void Graph::recursiveDepthFirstSearch(void (*f)(char)) const {
    bool *visited = Utils::initArray<bool>(false, this->size);

    for (int i = 0; i < this->size; i++) {
        this->recursiveDepthFirstVertexVisit(i, visited, f);
    }

    delete[] visited;
}

void Graph::recursiveDepthFirstVertexVisit(int vertex, bool *visited, void (*f)(char)) const {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;

    if (f != nullptr) {
        f(Utils::getLetterFromAlphabetIndex(vertex));
    }

    for (int i = 0; i < this->size; i++) {
        if (this->matrix[vertex][i] != 0) {
            this->recursiveDepthFirstVertexVisit(i, visited, f);
        }
    }
}

// endregion

// region iterative depth-first search

void Graph::iterativeDepthFirstSearch(void (*f)(char)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; i++) {
        this->iterativeDepthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeDepthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(char)) const {
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
            f(Utils::getLetterFromAlphabetIndex(vertex));
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

void Graph::iterativeBreadthFirstSearch(void (*f)(char)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; i++) {
        this->iterativeBreadthFirstVertexVisit(i, visited, met, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::iterativeBreadthFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(char)) const {
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
            f(Utils::getLetterFromAlphabetIndex(vertex));
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

void Graph::iterativePriorityFirstSearch(int priority, void (*f)(char)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);
    int *priorityBase = new int(0);

    for (int i = 0; i < this->size; i++) {
        this->iterativePriorityFirstVertexVisit(i, visited, met, f, priorityBase, priority);
    }

    delete[] visited;
    delete[] met;
    delete priorityBase;
}

void Graph::iterativePriorityFirstVertexVisit(int vertex, bool *visited, bool *met, void (*f)(char), int *priorityBase,
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
            f(Utils::getLetterFromAlphabetIndex(vertex));
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

void Graph::prim(bool debug, void (*f)(char)) const {
    bool *visited = Utils::initArray(false, this->size);
    bool *met = Utils::initArray(false, this->size);

    for (int i = 0; i < this->size; i++) {
        this->primVertexVisit(i, visited, met, debug, f);
    }

    delete[] visited;
    delete[] met;
}

void Graph::primVertexVisit(int vertex, bool *visited, bool *met, bool debug, void (*f)(char)) const {
    if (visited[vertex]) {
        return;
    }

    MinHeap mh;
    mh.insert(INT32_MAX, vertex);

    while (!mh.empty()) {
        pair<int, int> priority_pair = mh.extractMinimum();
        vertex = priority_pair.second;
        int* priority = &priority_pair.first;

        visited[vertex] = true;

        if (f != nullptr) {
            f(Utils::getLetterFromAlphabetIndex(vertex));
        }

        for (int i = 0; i < this->size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i]) {
                    int newPriority = this->matrix[vertex][i];

                    if (!met[i]) {
                        mh.insert(newPriority, i);
                        met[i] = true;
                    } else if (newPriority < *priority) {
                        mh.decreasePriority(mh.getIndexByValue(i), newPriority - 1);
                    }
                }
            }
        }

        if (debug) {
            cout << mh;
        }
    }
}

// endregion

// region Dijkstra

void Graph::dijkstra(bool debug, void (*f)(char)) const {
    bool *visited = Utils::initArray<bool>(false, this->size);
    bool *met = Utils::initArray<bool>(false, this->size);

    dijkstraVertexVisit(0, visited, met, debug, f);

    delete[] visited;
    delete[] met;
}

void Graph::dijkstraVertexVisit(int vertex, bool *visited, bool* met, bool debug, void (*f)(char)) const {
    if (visited[vertex]) {
        return;
    }

    MinHeap mh;
    mh.insert(0, vertex);

    while (!mh.empty()) {
        pair<int, int> priority_pair = mh.extractMinimum();
        vertex = priority_pair.second;
        int* priority = &priority_pair.first;

        visited[vertex] = true;

        if (f != nullptr) {
            f(Utils::getLetterFromAlphabetIndex(vertex));
        }

        for (int i = 0; i < this->size; i++) {
            if (this->matrix[vertex][i] != 0) {
                if (!visited[i]) {
                    int currentPriority = this->matrix[vertex][i];
                    int newPriority = *priority + this->matrix[vertex][i];

                    if (!met[i]) {
                        mh.insert(newPriority, i);
                        met[i] = true;
                    } else if (newPriority < currentPriority) {
                        mh.decreasePriority(mh.getIndexByValue(i), newPriority - 1);
                    }
                }
            }
        }

        if (debug) {
            cout << mh;
        }
    }
}

// endregion

// region Connected vertices

void Graph::connectedVertices() const {
    this->connectedVertices(Graph::printVertices);
}

void Graph::connectedVertices(void (*f)(vector<char>)) const {
    int *mark = Utils::initArray(0, this->size);
    int *n = new int(0);
    auto *q = new stack<int>;

    for (int i = 0; i < this->size; i++) {
        if (mark[i] == 0) {
            this->visitConnectedVertex(i, mark, n, q, f);
        }
    }

    delete[] mark;
    delete q;
    delete n;
}

// FIX: Visit connected vertices
int Graph::visitConnectedVertex(int vertex, int mark[], int *n, stack<int> *q, void (*f)(vector<char>)) const {
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
        vector<char> connectedVertices;

        int v = INT32_MIN;
        while (v != vertex) {
            v = q->top();
            mark[v] = this->size + 1;
            connectedVertices.push_back(Utils::getLetterFromAlphabetIndex(v));
            q->pop();
        }

        if (f != nullptr) {
            f(connectedVertices);
        }
    }

    return minimum;
}

// endregion
