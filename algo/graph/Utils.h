//
// Created by owen on 28/03/2022.
//

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Utils {
public:
    static string matrixToString(int **matrix, int size);

    template<class T>
    static T *initArray(T default_value, int size);

    template<class T>
    static void swap(T &a, T &b);
};

template<class T>
T *Utils::initArray(T default_value, int size) {
    T *arr = new T[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = default_value;
    }

    return arr;
}

template<class T>
void Utils::swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
