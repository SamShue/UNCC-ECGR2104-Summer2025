#include <iostream>

using namespace std;

int main(){
    int x = 0xF;
    int* p = &x;

    cout << &x << endl;
    cout << *p << endl;
    cout << p << endl;

    *p = 10;

    cout << x << endl;

    return 0;
    
}