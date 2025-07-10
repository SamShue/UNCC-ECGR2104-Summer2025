#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push_back(Node*& head, int data){
    if(head == nullptr){
        // if head is nullptr, then list is empty and we are adding the first element
        head = new Node;

        //(*head).data = data;
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

void pop_back(Node*& head){
    if(head == nullptr){
        return;
    }

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

unsigned int size(Node* head){
    unsigned int num_elements = 0;
    while(head != nullptr){
        num_elements++;
        head = head->next;
    }
    return num_elements;
}

int& at(Node* head, unsigned int index){
    unsigned int current_index = 0;
    while(current_index != index){
        current_index++;
        head = head->next;
    }
    return head->data;
}

int main(){
    Node* head = nullptr;

    push_back(head, 5);
    push_back(head, 7);
    push_back(head, 9);
    push_back(head, 13);

    pop_back(head);

    cout << "List size: " << size(head) << endl;

    for(int i = 0; i < size(head); i++){
        cout << at(head, i) << endl;
    }

    return 0;
}