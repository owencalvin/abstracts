//
// Created by owen on 28/03/2022.
//

#include <climits>
#include "MinHeap.h"
#include "Utils.h"

MinHeap::MinHeap() {
    this->heap.emplace_back(INT_MIN, INT_MIN);
}

const pair<int, int> *MinHeap::insert(int priority, int value) {
    this->heap.emplace_back(INT_MAX, value);
    this->decreasePriority(this->heap.size() - 1, priority);
    return &this->heap.back();
}

const pair<int, int> *MinHeap::minimum() {
    return &this->heap[1];
}

pair<int, int> MinHeap::extractMinimum() {
    if (this->heap.empty()) {
        return this->heap[0];
    }

    auto min = this->heap[1];
    this->heap[1] = this->heap.back();
    this->heap.pop_back();

    this->siftUp();

    return min;
}

void MinHeap::decreasePriority(int index, int newPriority) {
    if (newPriority > this->heap[index].first) {
        cout << "Error: new value is smaller than the old one";
    }

    this->heap[index].first = newPriority;
    while (index > 1 && this->heap[index / 2].first > this->heap[index].first) {
        Utils::swap(this->heap[index], this->heap[index / 2]);
        index /= 2;
    }
}

void MinHeap::siftUp() {
    unsigned int index = 1;
    bool done = false;

    while (index * 2 < this->heap.size() && !done) {
        const unsigned int firstChildIndex = index * 2;
        const unsigned int secondChildIndex = firstChildIndex + 1;
        unsigned int maxChildIndex = firstChildIndex;

        if (secondChildIndex < this->heap.size()) {
            if (this->heap[secondChildIndex].first < this->heap[firstChildIndex].first) {
                maxChildIndex = secondChildIndex;
            }
        }

        if (this->heap[maxChildIndex].first < this->heap[index].first) {
            Utils::swap(this->heap[maxChildIndex], this->heap[index]);
            index = maxChildIndex;
        } else {
            done = true;
        }
    }
}

bool MinHeap::empty() {
    return this->heap.size() <= 1;
}
