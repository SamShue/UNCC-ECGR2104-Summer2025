#include <iostream>
#include "utils.h"

using namespace std;

int main(){
    double radius = 4.0;
    double height = 6.0;

    swap(radius, height);

    cout << "radius: " << radius << endl;
    cout << "height: " << height << endl;

    double v = volumeCylinder(radius, height);

    cout << "The volume of the cylinder is " << v << "!" << endl;

    return 0;
}