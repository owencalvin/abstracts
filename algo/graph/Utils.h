//
// Created by owen on 28/03/2022.
//

#pragma once


class Utils {
public:
    template <class T>
    static void swap(T &a, T &b);
};

template<class T>
void Utils::swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
