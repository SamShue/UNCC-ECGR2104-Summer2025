#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    string filename;

    for(int i = 0; i < argc; i++){
        string s(argv[i]);

        if(s == "--help"){
            cout << "Here is how you use this program..." << endl;
            return 0;
        }

        if(s == "-i"){
            string temp(argv[i + 1]);
            filename = temp;
        }
    }

    ofstream outFile;

    outFile.open(filename);

    outFile << "Hello World!" << endl;
    outFile << "This is a second line." << endl;
    outFile << "This is a third line." << endl;

    outFile.close();

    ifstream inFile;

    inFile.open("example.txt");

    string fileContents;

    while(!inFile.eof()){
        getline(inFile, fileContents);
        cout << fileContents << endl;
    }

    inFile.close();

    return 0;
}