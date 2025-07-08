#include <iostream>
#include <cstdlib>
#include "utils.h"

using namespace std;

int main(){
    int x = 15;
    int* p = &x;

    char s[] = {'2', '0', '.', '6', ' ', '\0'};

    cout << s << endl;

    string s2 = "20.6";

    cin >> s2;

    double d = stof(s2);

    int a[] = {1, 2, 3, 4};

    cout << s << endl;

    return 0;
    
}