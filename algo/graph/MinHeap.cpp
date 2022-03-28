//
// Created by owen on 28/03/2022.
//

#include <climits>
#include "MinHeap.h"
#include "Utils.h"

MinHeap::MinHeap() {
    this->heap.push_back(make_pair(INT_MIN, INT_MIN));
}

const pair<int, int> *MinHeap::insert(int priority, int value) {
    this->heap.push_back(make_pair(priority, value));
    this->decreasePriority(this->heap.size() - 1, priority);
    return &this->heap.back();
}

const pair<int, int> *MinHeap::minimum() {
    return &this->heap[1];
}

const pair<int, int> MinHeap::extractMinimum() {
    if (this->heap.empty()) {
        return make_pair(INT_MIN, INT_MIN);
    }

    auto min = this->heap[1];
    this->heap[1] = this->heap.back();
    this->heap.pop_back();

    this->siftUp();

    return min;
}

const pair<int, int> *MinHeap::decreasePriority(int index, int newPriority) {
    if (index < 0) {
        return nullptr;
    }

    if (newPriority > this->heap[index].first) {
        return nullptr;
    }

    while (index > 1 && this->heap[index / 2] > this->heap[index]) {
        Utils::swap(this->heap[index], this->heap[index / 2]);
        index /= 2;
    }
}

void MinHeap::siftUp() {
    int index = 0;
    bool done = false;

    while (index * 2 <= this->heap.size() && !done) {
        int maxChildIndex = index * 2;

        if (maxChildIndex + 1 < this->heap.size()) {
            maxChildIndex++;
        }

        if (this->heap[maxChildIndex] < this->heap[index]) {
            Utils::swap(this->heap[maxChildIndex], this->heap[index]);
            index = maxChildIndex;
        } else {
            done = true;
        }
    }
}

const bool MinHeap::empty() {
    return this->heap.size() <= 1;
}

const pair<int, int> *MinHeap::top() {
    return this->minimum();
}

const pair<int, int> *MinHeap::back() {
    return &this->heap.back();
}
