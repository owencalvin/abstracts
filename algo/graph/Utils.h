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
    /**
     * Get a string representation of a 2D matrix
     * @param matrix The matrix (2D int array)
     * @param size The size of the matrix
     * @return The string representation of the matrix
     */
    static string matrixToString(int **matrix, int size);

    /**
     * Init an array of type T with a default value for each element
     * @tparam T The array type
     * @param default_value The default value
     * @param size The array size
     * @return The array of type T with the specified size filled with the default value
     */
    template<class T>
    static T *initArray(T default_value, int size);

    /**
     * Swap two variables of type T
     * @tparam T The type of the variables
     * @param a The first variable to swap
     * @param b The second variable to swap
     */
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
