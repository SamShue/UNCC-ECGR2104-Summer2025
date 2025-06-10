#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
    string name;

    Student(){
        name = "";
        gpa = -1.0;
        id = -1;
    }

    Student(string n, double g, int i){
        name = n;
        setGpa(g);
        setId(i);
    }
    
    void setId(int i){
        if(i < 800000000){
            cout << "Invalid ID assignment." << endl;
            id = -1;
            return;
        }

        id = i;
    }

    int getId() const {
        return id;
    }

    void setGpa(double g){
        if(g > 4.0 || g < 0.0){
            cout << "Invalid GPA assignment." << endl;
            gpa = -1.0;
            return;
        }

        gpa = g;
    }

    double getGpa() const {
        return gpa;
    }

    void print() const {
        cout << name << " " << gpa << " " << " " << id << endl;
    }

    private:
    double gpa;
    int id;
};

int main(){
    Student s("Bob", 4.0, 801123124);
    Student s2("Joe", 2.0, 801123125);

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
        int tempId;
        double tempGpa;
        Student temp;
        switch(userInput){
            case 1:
                for(int i = 0; i < students.size(); i++){
                    students.at(i).print();
                }
                break;
            case 2:
                cout << "Enter the student's name: " << endl;
                cin >> tempName;
                cout << "Enter the student's GPA: " << endl;
                cin >> tempGpa;
                cout << "Enter the student's ID: " << endl;
                cin >> tempId;
                
                temp.name = tempName;
                temp.setId(tempId);
                temp.setGpa(tempGpa);

                students.push_back(temp);
                break;
            case 3:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Unrecognized input." << endl;
                break;
        }
    } while(userInput != 3);
    
    /*
    // Array solution:
    const unsigned int SIZE = 1000;
    unsigned int num_students = 1;
    string name[SIZE];
    double gpa[SIZE];
    int id[SIZE];

    name[0] = "Sam";
    gpa[0] = 2.4;
    id[0] = 801123123;

    cout << "Welcome to the Student Database Application." << endl;
    unsigned int userInput = 0;
    do{
        cout << "What do you want to do?" << endl;
        cout << "1: Print Student List" << endl;
        cout << "2: Add new student" << endl;
        cout << "3: Quit" << endl;
        cin >> userInput;

        string tempName;
        int tempId;
        double tempGpa;
        switch(userInput){
            case 1:
                for(int i = 0; i < num_students; i++){
                    cout << "Name: " << name[i] << ", GPA: " << gpa[i] << ", ID: " << id[i] << endl;
                }
                break;
            case 2:
                if(num_students == SIZE){
                    cout << "Out of memory! Unable to add new student." << endl;
                    break;
                }
                cout << "Enter the student's name: " << endl;
                cin >> tempName;
                cout << "Enter the student's GPA: " << endl;
                cin >> tempGpa;
                cout << "Enter the student's ID: " << endl;
                cin >> tempId;

                name[num_students] = tempName;
                gpa[num_students] = tempGpa;
                id[num_students] = tempId;

                num_students++;
                break;
            case 3:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Unrecognized input." << endl;
                break;
        }
    } while(userInput != 3);
    */

    return 0;
}