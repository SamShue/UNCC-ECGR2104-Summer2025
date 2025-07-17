#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList{
    public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& other);
    void operator=(const SinglyLinkedList& other);

    void push_back(int data);
    void pop_back();
    unsigned int size() const;
    int& at(unsigned int index) const;
    void insert(unsigned int index, int data);
    void remove(unsigned int index);

    private:
    Node* head;
    unsigned int num_elements;
};

SinglyLinkedList::SinglyLinkedList(){
    head = nullptr;
    num_elements = 0;
}

SinglyLinkedList::~SinglyLinkedList(){
    while(head != nullptr) {
        Node* nextElement = head->next;
        delete head;
        head = nextElement;
    }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other){
    head = nullptr;
    num_elements = other.num_elements;
    
    for(int i = 0; i < other.size(); i++){
        push_back(other.at(i));
    }
    
    /*
    Node* otherCurrentIndex = other.head;

    if(other.size() == 0) {
        return;
    }

    head = new Node;
    head->data = otherCurrentIndex->data;
    head->next = nullptr;
    Node* currentIndex = head->next;

    while(otherCurrentIndex->next != nullptr){
        currentIndex = new Node;
        currentIndex->data = otherCurrentIndex->data;
        currentIndex->next = nullptr;

        otherCurrentIndex = otherCurrentIndex->next;
        currentIndex = currentIndex->next;
    }
    */
}

void SinglyLinkedList::operator=(const SinglyLinkedList& other){
    while(head != nullptr) {
        Node* nextElement = head->next;
        delete head;
        head = nextElement;
    }

    head = nullptr;
    num_elements = other.num_elements;
    
    for(int i = 0; i < other.size(); i++){
        push_back(other.at(i));
    }
}

void SinglyLinkedList::push_back(int data){
    num_elements++;

    if(head == nullptr){
        // if head is nullptr, then list is empty and we are adding the first element
        head = new Node;

        (*head).data = data;
        head->data = data;



        head->next = nullptr;
        return;
    }

    /*
    addr        data   next
    0xFF00      5      0xFF0F
    0xFF0F      7      0xFF08
    0xFF08      9      0xFF0B
    0xFF0B      13     nullptr
    heap====================
                head addr
    0xFFF8      0xFF00
    stack===================

    head = 0xFF00
    currentNode = 0xFF08
    */

    Node* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    //(*currentNode).next = new Node;
    currentNode->next = new Node;
    (currentNode->next)->data = data;
    currentNode->next->next = nullptr;

    /*
    currentNode->next = new Node;
    currentNode = currentNode->next;
    currentNode->data = data;
    currentNode->next = nullptr;
    */
}

void SinglyLinkedList::pop_back(){
    if(head == nullptr){
        return;
    }

    num_elements--;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* currentNode = head;
    while(currentNode->next->next != nullptr){
        currentNode = currentNode->next;
    }

    delete currentNode->next;
    currentNode->next = nullptr;
}

unsigned int SinglyLinkedList::size() const {
    return num_elements;
}

int& SinglyLinkedList::at(unsigned int index) const {
    unsigned int current_index = 0;
    Node* currentNode = head;
    while(current_index != index){
        current_index++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

void SinglyLinkedList::insert(unsigned int index, int data){
    num_elements++;

    if(index == 0){
        Node* backupAddr = head->next;
        head = new Node;
        head->data = data;
        head->next = backupAddr;
        return;
    }

    Node* currentNode = head;
    unsigned int current_index = 0;
    while(current_index != (index - 1)){
        current_index++;
        currentNode = currentNode->next;
    }

    Node* backupAddr = currentNode->next;
    currentNode->next = new Node;
    currentNode->next->data = data;
    currentNode->next->next = backupAddr;
}

void SinglyLinkedList::remove(unsigned int index){
    num_elements--;

    if(index == 0){
        Node* backupAddr = head->next;
        delete head;
        head = backupAddr;
        return;
    }

    Node* currentNode = head;
    unsigned int current_index = 0;
    while(current_index != (index - 1)){
        current_index++;
        currentNode = currentNode->next;
    }

    Node* backupAddr = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete backupAddr;
}

int main(){
    SinglyLinkedList sll;

    sll.push_back(5);
    sll.push_back(7);
    sll.push_back(9);
    sll.push_back(13);

    sll.remove(1);
    sll.insert(2, 19);

    sll.pop_back();

    SinglyLinkedList sll2 = sll;

    cout << "List size: " << sll.size() << endl;

    for(int i = 0; i < sll.size(); i++){
        cout << sll.at(i) << endl;
    }

    return 0;
}