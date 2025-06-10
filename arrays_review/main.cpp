#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> name = {"Bob", "Joe"};
    vector<double> gpa = {4.0, 3.0};
    vector<int> id = {801123124, 801123125};

    name.push_back("Sam");
    gpa.push_back(2.4);
    id.push_back(801123123);

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
                for(int i = 0; i < name.size(); i++){
                    cout << "Name: " << name.at(i) << ", GPA: " << gpa.at(i) << ", ID: " << id.at(i) << endl;
                }
                break;
            case 2:
                cout << "Enter the student's name: " << endl;
                cin >> tempName;
                cout << "Enter the student's GPA: " << endl;
                cin >> tempGpa;
                cout << "Enter the student's ID: " << endl;
                cin >> tempId;

                name.push_back(tempName);
                gpa.push_back(tempGpa);
                id.push_back(tempId);
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