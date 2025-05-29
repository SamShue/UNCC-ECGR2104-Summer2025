#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    string questionText;
    cout << "Ask a question." << endl;
    cin >> questionText;

    int seed = 0;
    for(int i = 0; i < questionText.length(); i++){
        seed += questionText[i];
    }

    srand(seed);

    int r = rand() % 3;
/*
    if(r == 0){
        cout << "Yes." << endl;
    } else if(r == 1) {
        cout << "No." << endl;
    } else {
        cout << "Maybe." << endl;
    }
*/
    switch(r){
        case 0:
            cout << "Yes." << endl;
            break;
        case 1:
            cout << "No." << endl;
            break;
        case 2:
        default:
            cout << "Maybe." << endl;
            break;
    }

    return 0;
}