//
// Created by L00711689 on 5/12/2025.
//

#ifndef CMLAB5_HPP
#define CMLAB5_HPP

#include <string>

const int SIZE = 20;

struct Student;


void introMessage(); // Display program description
int countFile(const std::string &); // Read file
void createArray(Student [], int& , std::string&);
void sortArrays(std::string[], std::string[], int); // Insertion sort name array and match LNum array
void displayArrays(const Student [], int); // Display arrays to console
bool binSearch(const std::string[], int, std::string); // Perform a binary search
bool compareName(Student, Student);
bool compareLnum(Student, Student);

#endif //CMLAB5_HPP
