#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

int main(){
    Student s("Bob", 4.0);
    Student s2("Joe", 2.0);

    vector<Student> students;

    students.push_back(s);
    students.push_back(s2);

    cout << "Welcome to the Student Database Application." << endl;
    unsigned int userInput = 0;
    do{
        cout << "What do you want to do?" << endl;
        cout << "1: Print Student List" << endl;
        cout << "2: Add new student" << endl;
        cout << "3: Quit" << endl;
        cin >> userInput;

        string tempName;
        double tempGpa;
        switch(userInput){
            case 1:
                cout << "Total Number of Students: " << Student::getNumStudents() << endl;
                for(int i = 0; i < students.size(); i++){
                    students.at(i).print();
                }
                break;
            case 2:
                cout << "Enter the student's name: " << endl;
                cin >> tempName;
                cout << "Enter the student's GPA: " << endl;
                cin >> tempGpa;

                students.push_back(Student(tempName, tempGpa));
                break;
            case 3:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Unrecognized input." << endl;
                break;
        }
    } while(userInput != 3);

    return 0;
}