// intlist.cpp
// Implements class IntList
// Andy Gonzalez 4-26-2021

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    this->first = new Node;
    this->first->info = source.first->info;
    this->first->next = nullptr;
    Node* currnode = this->first;
    Node* copynode = source.first->next;
    while(copynode) {
        currnode->next = new Node;
        currnode = currnode->next;
        currnode->info = copynode->info;
        copynode = copynode->next;
        currnode->next = nullptr;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
     while (first) {
      Node* nextnode = first->next;
      delete first;
      first = nextnode;
     }
}


// return sum of values in list
int IntList::sum() const {
    int sum(0);
    Node* tempnode = first;
    while(tempnode) {
        sum += tempnode->info;
        tempnode = tempnode->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* searchnode = first;
    bool NodeValueFound = false;
    while(searchnode) {
        if(searchnode->info == value) {
            NodeValueFound = true;
            return NodeValueFound;
        }
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* MaxNode = first;
    int MaxValue = first->info;
    if(!MaxNode) {return 0;}
    while(MaxNode) {
        if (MaxValue > MaxNode->info) {
            MaxValue = MaxNode->info;
        }
        MaxNode = MaxNode->next;
    }

    return MaxValue;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double average(0.0);
    int sum(0);
    int LenOfList(0);
    Node* tempnode = first;
    if (!tempnode) {return 0;}
    while(tempnode) {
        LenOfList++;
        sum += tempnode->info;
        tempnode = tempnode->next;
    }
    average = sum/LenOfList;
    delete tempnode;
    return average;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node InsertNode;
    InsertNode.info = value;
    InsertNode.next = first->next;
    first = &InsertNode;
    
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source) {
        while (first) { //deletes original list
            Node* nextnode = first->next;
            delete first;
            first = nextnode;
        }
        this->first = new Node;
        this->first->info = source.first->info;
        this->first->next = nullptr;
        Node* currnode = this->first;
        Node* copynode = source.first->next;
        while(copynode) {
            currnode->next = new Node;
            currnode = currnode->next;
            currnode->info = copynode->info;
            copynode = copynode->next;
            currnode->next = nullptr;
        }
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
