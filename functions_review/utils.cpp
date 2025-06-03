#include "utils.h"

void swap(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
}

double volumeCylinder(double radius, double height){
    return circleArea(radius) * height;
}

double circleArea(double radius){
    return PI * radius * radius;
}

double circleVolume(double radius){
    return (4.0 / 3.0) *PI * radius * radius * radius;
}