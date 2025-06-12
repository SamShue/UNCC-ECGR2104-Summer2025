#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
    public:
    std::string name;

    Student(std::string name, double gpa);
    void setGpa(double gpa);
    double getGpa() const;
    void print() const;
    static int getNumStudents();

    private:
    double gpa;
    int id;

    static int numStudents;
};

#endif