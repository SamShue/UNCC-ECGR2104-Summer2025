#include "student.h"

using namespace std;

int Student::numStudents = 0;

int Student::getNumStudents() {
    return numStudents;
}

Student::Student(string name, double gpa){
    this->name = name;
    setGpa(gpa);
    id = 800000000 + numStudents;
    numStudents++;
}

void Student::setGpa(double gpa){
    if(gpa > 4.0 || gpa < 0.0){
        cout << "Invalid GPA assignment." << endl;
        gpa = -1.0;
        return;
    }

    this->gpa = gpa;
}

double Student::getGpa() const {
    return gpa;
}

void Student::print() const {
    cout << name << " " << gpa << " " << " " << id << endl;
}