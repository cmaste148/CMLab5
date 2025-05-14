//
// Created by L00711689 on 5/12/2025.
//

#include "CMLab5.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

struct Student
{

public:
    std::string name;
    std::string lnum;
    float gpa;

    std::string getName() const
    {
        return name;
    }
    void setName(const std::string &name)
    {
        this->name = name;
    }
    std::string getLnum() const
    {
        return lnum;
    }
    void setLnum(const std::string &lnum)
    {
        this->lnum = lnum;
    }
    float getGpa() const
    {
        return gpa;
    }
    void setGpa(float gpa)
    {
        this->gpa = gpa;
    }
};

void introMessage()
{
    std::cout << "Welcome, this program will accept a file with student names, lnumbers and GPS's \n"
                 "and will sort them and allow you to check if a name was included in the list." << std::endl << std::endl;
}

int countFile(std::string const &fileName)
{
    int count = 0;
    std::ifstream infile;

    std::string temp;
    infile.open(fileName);
    for (int i = 0; i < 100; i++)
    {
        if (!infile.eof())
        {
            infile >> temp;
            count++;
        }
    }
    infile.close();


    return count / 3;
}

void createArray(Student students[], int &count, std::string &fileName)
{
    Student student;
    std::ifstream infile;
    infile.open(fileName);
    for (int i = 0; i < count; i++)
    {
        if (!infile.eof())
        {
            infile >> student.name >> student.lnum >> student.gpa;
        }
        students [i] = student;
    }
    infile.close();

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

void displayArrays(const Student students[], int count)
{
    std::cout << "   Names  |  Lnums  |   GPA   \n ---------|----------|---------- " << std::endl;
    for ( int i = 0; i < count; i++)
    {
        std::cout << std::setw(9) << students[i].getName()
        << " | " << students[i].getLnum() << " | " << students[i].getGpa() << std::endl;
    }

}

bool binSearch(const std::string array[], int count, const std::string &term)
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

bool compareName(Student &start, Student &end)
{
   return start.name < end.name;
}

bool compareLnum(Student &start, Student &end)
{
    return start.lnum < end.lnum;
}
