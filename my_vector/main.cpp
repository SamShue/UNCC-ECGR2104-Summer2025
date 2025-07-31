#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class vector{
    public:
    vector(){
        allocatedSize = 3;
        nextIndex = 0;
        a = new T[allocatedSize];
    }

    ~vector(){
        cout << "Destructor called!" << endl;
        delete[] a;
    }

    vector(const vector& other){
        cout << "Copy constructor called!" << endl;
        nextIndex = other.nextIndex;
        allocatedSize = other.allocatedSize;
        a = new T[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = other.a[i];
        }
    }

    void operator=(const vector& other){
        cout << "Copy assignment operator called!" << endl;
        delete[] a;
        nextIndex = other.nextIndex;
        allocatedSize = other.allocatedSize;
        a = new T[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = other.a[i];
        }
    }

    void push_back(int data){
        if(nextIndex != allocatedSize){
            a[nextIndex] = data;
            nextIndex++;
        } else {
            cout << "Allocating more space..." << endl;
            // make more space for the data
            T* temp = new T[allocatedSize + 3];
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

    T& at(unsigned int index){
        if(index >= nextIndex){
            throw out_of_range("Accessed index that is out of range.");
        }

        return a[index];
    }

    private:
    T* a;
    unsigned int allocatedSize;
    unsigned int nextIndex;
};


void function(){
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    v.push_back(13);

    v.at(2) = 17;

    vector v2 = v;

    v2.at(0) = 3;

    v = v2;

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }

    cout << v.at(37) << endl;
}

int main(){

    try{
        function();
        function();
    } 
    catch(const out_of_range& e){
        cout << e.what() << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    return 0;
}