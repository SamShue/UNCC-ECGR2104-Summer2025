#include <iostream>

using namespace std;

int main(){

    try{
        string error_code = "5";

        cout << "Hello " << endl;

        throw error_code;

        cout << "World!" << endl;
    } catch(int e){
        cout << "Caught the integer " << e << endl;
    }

    return 0;
}