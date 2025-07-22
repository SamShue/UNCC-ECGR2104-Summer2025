#include <iostream>

using namespace std;

class Person {
    public:
    string name;

    Person(string name);
    virtual void print() const = 0;
    static int getNumPeople();

    protected:
    int id;
    static int numPeople;
};

int Person::numPeople = 0;

Person::Person(string name){
    this->name = name;
    id = 800000000 + numPeople;
    numPeople++;
}

int Person::getNumPeople() {
    return numPeople;
}

class Student : public Person {
    public:
    Student(string name, double gpa);
    void setGpa(double gpa);
    double getGpa() const;
    void print() const;

    private:
    double gpa;
};

void Student::print() const {
    cout << name << " " << gpa << " " << id << endl;
}

Student::Student(string name, double gpa) : Person(name) {
    setGpa(gpa);
}

void Student::setGpa(double gpa){
    if(gpa > 4.0 || gpa < 0.0){
        cout << "Invalid GPA assignment." << endl;
        this->gpa = -1.0;
        return;
    }

    this->gpa = gpa;
}

double Student::getGpa() const {
    return gpa;
}

class Faculty : public Person {
    public:
    Faculty(string name, double salary);
    void setSalary(double salary);
    double getSalary() const;
    void print() const;

    private:
    double salary;
};

void Faculty::print() const {
    cout << name << " " << salary << " " << id << endl;
}

Faculty::Faculty(string name, double salary) : Person(name) {
    setSalary(salary);
}

void Faculty::setSalary(double salary){
    if(salary < 0.0){
        cout << "Invalid salary assignment." << endl;
        this->salary = -1.0;
        return;
    }

    this->salary = salary;
}

double Faculty::getSalary() const {
    return salary;
}

int main(){
    Student s("Bob", 3.4);
    Faculty f("Sam", 72000);

    s.print();
    f.print();

    return 0;
}