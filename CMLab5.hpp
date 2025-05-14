//
// Created by L00711689 on 5/12/2025.
//

#ifndef CMLAB5_HPP
#define CMLAB5_HPP

#include <string>

const int SIZE = 20;

void introMessage(); // Display program description
int readFile(std::string[], std::string[], int); // Read file and add elements to arrays
void sortArrays(std::string[], std::string[], int); // Insertion sort name array and match LNum array
void displayArrays(const std::string[], const std::string[], int); // Display arrays to console
bool binSearch(const std::string[], int, std::string); // Perform a binary search

#endif //CMLAB5_HPP
