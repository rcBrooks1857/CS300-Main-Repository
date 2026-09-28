#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* prev;
    Node* next;
};

void insertFront(Node*& head, Node*& tail, int value) {
    
    Node* newNode = new Node;

    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr){
        head->prev = newNode;
    }
    else{
        tail = newNode;
    }
        head = newNode;
}

void insertBack(Node*& head, Node*& tail, int value){
    
    Node* newNode = new Node;


    newNode->value = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr){
        tail->next = newNode;
    }
    else{
        head = newNode;
    }
        tail = newNode;
}

void remove(Node*& head, Node*& tail, int value){

    Node* current = head;

    while (current != nullptr && current->value != value){
        current = current->next;
    }

    if (current == nullptr){
        return;
    }

    if (current->prev != nullptr){
        current->prev->next = current->next;
    }

    else{
        head = current->next;
    }

    if (current->next != nullptr){
        current->next->prev = current->prev;
    }

    else{
        tail = current->prev;
    }
    
    delete current;
}

Node* search(Node* head, int value){

    Node* current = head;

    while (current != nullptr){
        if (current->value == value){
            return current;
        }
        
        current = current->next;
    }

    return nullptr;
}

void printForward(Node* head){
    
    Node* current = head;

    while (current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void printBackward(Node* tail){

    Node* current = tail;

    while (current != nullptr){
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

void clearList(Node*& head, Node*& tail){

    Node* current = head;

    while (current != nullptr){
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertBack(head, tail, 10);
    insertBack(head, tail, 20);
    insertBack(head, tail, 30);


    printForward(head); // 10 20 30
    printBackward(tail); // 30 20 10

    insertFront(head, tail, 5);
    printForward(head); // 5 10 20 30
    printBackward(tail); // 30 20 10 5
    remove(head, tail, 20);
    printForward(head); // 5 10 30
    printBackward(tail); // 30 10 5
    
    if (search(head, 10) != nullptr)
        std::cout << "10 found" << std::endl;
    else
        std::cout << "10 not found" << std::endl;
    if (search(head, 100) != nullptr)
        std::cout << "100 found" << std::endl;
    else
        std::cout << "100 not found" << std::endl;
    clearList(head, tail);
    return 0;
}
