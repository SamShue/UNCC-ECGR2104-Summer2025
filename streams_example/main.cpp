#include <iostream>

using namespace std;

int main(){
    int x;
    double y;

    cin >> x;
    cin >> y;

    cout << x << endl;
    cout << y << endl;

    /*
    string month;
    int day;
    char comma;
    int year;

    cout << "Enter in today's date in the format Month X, XXXX" << endl;
    
    //                    [J u l y _ 3 1 , _ 2 0 2 5]
    //                    [3 1 , _ 2 0 2 5]                 cin >> month; month -> J u l y \0
    //                    [, _ 2 0 2 5]                     cin >> day; day -> 31
    //                    [_ 2 0 2 5]                       cin >> comma; comma -> ,
    //                    []                                cin >> year; year -> 2025

    cin >> month;
    cin >> day;
    cin >> comma;
    cin >> year;

    cout << month << day << comma << year << endl;
    */
    return 0;
}