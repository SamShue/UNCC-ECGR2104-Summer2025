#include <iostream>

using namespace std;

struct Complex {
    double real;
    double imag;

    Complex(){
        real = 0.0;
        imag = 0.0;
    }

    Complex(double real, double imag){
        this->real = real;
        this->imag = imag;
    }

    void print(){
        cout << real << " + " << imag << "i" << endl;
    }

    Complex add(const Complex& other){
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    Complex operator+(const Complex& other){
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    Complex operator+(double other){
        Complex result;
        result.real = real + other;
        result.imag = imag;
        return result;
    }

    Complex operator-(const Complex& other){
        return Complex(real - other.real, imag - other.imag);
    }

    bool operator==(const Complex& other){
        return real == other.real && imag == other.imag;
    }
};

int main(){
    // 6 + 5i
    // 2 + 2i
    // 8 + 7i
    Complex c1(6, 5);
    Complex c2(2, 2);

    //Complex c3 = c1.add(c2);
    Complex c3 = c1 + c2;
    c3 = c3 - c1;
    c3 = c1 + 2.0;

    if(c3 == c2){
        cout << "equal" << endl;
    }

    c3.print();

    return 0;
}