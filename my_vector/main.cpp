#include <iostream>

using namespace std;

class vector{
    public:
    vector(){
        allocatedSize = 3;
        nextIndex = 0;
        a = new int[allocatedSize];
    }

    void push_back(int data){
        if(nextIndex != allocatedSize){
            a[nextIndex] = data;
            nextIndex++;
        } else {
            cout << "Allocating more space..." << endl;
            // make more space for the data
            int* temp = new int[allocatedSize + 3];
            for(int i = 0; i < allocatedSize; i++){
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
            allocatedSize = allocatedSize + 3;
            a[nextIndex] = data;
            nextIndex++;
        }
    }

    void pop_back(){
        nextIndex--;
        if(nextIndex < 0){
            nextIndex = 0;
        }
    }

    unsigned int size() const {
        return nextIndex;
    }

    int& at(unsigned int index){
        return a[index];
    }

    private:
    int* a;
    unsigned int allocatedSize;
    unsigned int nextIndex;
};

int main(){
    vector v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    v.push_back(13);

    v.at(2) = 17;

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }

    return 0;
}