#include <iostream>

using namespace std;

int main(){
    // 1st = 15 human years
    // 2nd = 9 human years (24 year old human after 2 years)
    // 3rd - inf = 5 human years

    int dogYears;
    int humanYears;

    cout << dogYears << endl;

    do {
        cout << "Enter in your dog's age:" << endl;
        cin >> dogYears;
        if(dogYears < 1){
            cout << "Invalid age." << endl;
        }
    } while(dogYears < 1);

    if(dogYears == 1){
        humanYears = 15;
    }else if(dogYears == 2){
        humanYears = 24;
    }else{
        humanYears = 24 + (dogYears - 2)*5;
    }

    cout << "Your dog's age in human years is " << humanYears << "!" << endl;

    return 0;
}