//
// Created by L00711689 on 5/12/2025.
//

#include "CMLab5.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

void introMessage()
{
    std::cout << "Welcome, this program will accept a file with student names and lnumbers \n"
                 "and will sort them and allow you to check if a name was included in the list." << std::endl << std::endl;
}

int readFile(std::string names[], std::string lnums[], int max)
{
    bool flag;
    int count = 0;
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
            for (int i = 0; i < max; i++)
            {
                if (!infile.eof())
                {
                    infile >> names[i] >> lnums[i];
                    count++;
                }
            }
            infile.close();
        }
        else
        {
            flag = true;
            std::cout << "File name invalid, Try again" << std::endl;
        }

    } while (flag == true);

    return count;
}

void sortArrays(std::string names[], std::string lnums[], int count)
{
    // Code taken from lecture

    // insert next value into sorted
    // start of the array
    for(int i = 1; i < count; i++)
    {
        std::string name = names[i];
        std::string lnum = lnums[i];
        int j = i - 1;
        // now move items up to find the right place for name
        while (j >= 0 and names[j] > name)
        {
            names[j+1] = names[j];
            lnums[j+1] = lnums[j];
            j -= 1;
        }
        // found the place!
        // but decremented j once too many times ...
        names[j+1] = name;
        lnums[j+1] = lnum;
    }

}

void displayArrays(const std::string names[], const std::string lnums[], int count)
{
    std::cout << "   Names  |  Lnums  \n ---------|---------- " << std::endl;
    for ( int i = 0; i < count; i++)
    {
        std::cout << std::setw(9) << names[i]
        << " | " << lnums[i] << std::endl;
    }

}

bool binSearch(const std::string array[], int count, const std::string term)
{
    // Code adapted from Josephs' video to return bool rather than index

    bool found = false;
    int min = 0; int max = count - 1;

    while (max >= min)
    {
        int mid = (min + max) / 2;

        if (term.compare(array[mid]) < 0 )
        {
            max = mid - 1;
        }
        else if (term.compare(array[mid]) > 0)
        {
            min = mid + 1;
        }
        else
        {
            found = true;
            min = max + 1;
        }
    }
    return found;
}
