//
// Created by owen on 28/03/2022.
//

#include <climits>
#include <iostream>
#include "MinHeap.h"
#include "Utils.h"

MinHeap::MinHeap() {
    this->heap.push_back(make_pair(INT_MIN, INT_MIN));
}

const pair<int, int> *MinHeap::insert(int priority, int value) {
    this->heap.push_back(make_pair(INT_MAX, value));
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

const bool MinHeap::empty() {
    return this->heap.size() <= 1;
}

const pair<int, int> *MinHeap::top() {
    return this->minimum();
}

const pair<int, int> *MinHeap::back() {
    return &this->heap.back();
}
