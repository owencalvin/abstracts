//
// Created by owen on 28/03/2022.
//

#include <sstream>
#include "Utils.h"

string Utils::matrixToStringIntVertex(int **matrix, int size) {
    int size_str_length = to_string(size).length();
    stringstream ss;

    ss << endl << "     ";

    stringstream first_line;
    for (int i = 0; i < size; ++i) {
        first_line << setfill('0') << setw(size_str_length) << i << "  ";
    }

    ss << first_line.str() << std::endl << "  ";

    ss << setfill(' ') << setw(size_str_length) << "";
    ss << setfill('-') << setw(first_line.str().length()) << "";

    ss << endl;

    for (int i = 0; i < size; ++i) {
        ss << setfill('0') << setw(size_str_length) << i << " |  ";

        for (int j = 0; j < size; ++j) {
            ss << matrix[i][j] << "  ";
            ss << setfill(' ') << setw(size_str_length);
        }

        ss << endl;
    }

    return ss.str();
}

string Utils::matrixToStringCharVertex(int **matrix, int size) {
    int size_str_length = to_string(size).length();
    stringstream ss;

    ss << endl << "      ";

    stringstream first_line;
    for (int i = 0; i < size; ++i) {
        first_line << Utils::getLetterFromAlphabetIndex(i) << "   ";
    }

    ss << first_line.str() << std::endl << "    ";
    ss << setfill('-') << setw(first_line.str().length()) << "";

    ss << endl << " ";

    for (int i = 0; i < size; ++i) {
        ss << Utils::getLetterFromAlphabetIndex(i) << " |  ";

        for (int j = 0; j < size; ++j) {
            ss << matrix[i][j] << "  ";
            ss << setfill(' ') << setw(size_str_length);
        }

        ss << endl;
    }

    return ss.str();
}

int Utils::getIndexInAlphabet(char letter) {
    return tolower(letter) - 'a';
}

char Utils::getLetterFromAlphabetIndex(int letterIndex) {
    return toupper((char) (letterIndex + 'a'));
}
