//
// Created by owen on 21/02/2022.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

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

int Graph::deg(int i) {
    int deg = 0;

    for (int j = 0; j < this->size; ++j) {
        if (this->matrix[i][j] > 0) {
            deg++;
        }
    }

    return deg;
}

bool Graph::isPondere() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (abs(this->matrix[i][j]) > 1) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isOriented() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (this->matrix[i][j] != this->matrix[j][i]) {
                return true;
            }
        }
    }

    return false;
}

void Graph::vspr() {

}

void Graph::depthFirstSearch() {
    int visited[this->size];

    for (int i = 0; i < this->size; ++i) {
        
    }
}
