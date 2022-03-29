//
// Created by owen on 28/03/2022.
//

#pragma once

#include <vector>

using namespace std;

class MinHeap {
private:
    vector<pair<int, int>> heap;

public:
    MinHeap();

    bool empty();

    const pair<int, int>* top();

    const pair<int, int>* back();

    const pair<int, int>* insert(int priority, int value);

    const pair<int, int>* minimum();

    pair<int, int> extractMinimum();

    void decreasePriority(int index, int newPriority);

    void siftUp();
};
