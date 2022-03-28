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

    const bool empty();

    const pair<int, int>* top();

    const pair<int, int>* back();

    const pair<int, int>* insert(int value, int priority);

    const pair<int, int>* minimum();

    const pair<int, int> extractMinimum();

    const pair<int, int>* decreasePriority(int index, int newPriority);

    void siftUp();
};
