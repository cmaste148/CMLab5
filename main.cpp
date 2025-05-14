/*
Lab 5
Name: Cody Masterson
Date: 5/12/2024
IDE: Clion
Version: 1.0
Description: Improving Lab2 with structs
*/

#include "CMLab5.hpp"
#include <iostream>
#include <fstream>

int main()
{

    introMessage();

    Student * students = new Student;
    bool flag;
    int count;
    std::ifstream infile;
    std::string fileName;
    std::cout << "Please enter the name of the file you would like to open" << std::endl;
    do
    {
        flag = false;
        std::cin >> fileName;
        infile.open(fileName);
        if (infile.good())
        {
            count = countFile(fileName);
            createArray(students, count, fileName);

        }
        else
        {
            flag = true;
            std::cout << "File name invalid, Try again" << std::endl;
        }

    } while (flag == true);


    std::cout << count;

    return 0;
}
