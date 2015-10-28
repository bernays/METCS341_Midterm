//
//  main.cpp
//  CS341_Midterm
//
//  Created by Ben Bernays on 10/26/15.
//  Copyright © 2015 Ben Bernays. All rights reserved.
//


// Created:
//    Node* Node::putNodeSorted
//      - This function puts node in sorted position (this is the solution to problem #2
//    Bool BagList::putANodeSorted
//      - This function calls the putNodeSorted from main() user still has ability to add to head of list
//    void BagList::getSortedList
//      - Implements problem 1 exactly as specified
//    void BagList::getSortedList2
//      - Creates sorted list without first converting to an array.
#include <iostream>

#include <string>
#include <iostream>
using namespace std;
class Node {
public:
    Node () {}
    Node* putNodeSorted (Node*, string);
    Node* putNode (Node*, string);
    string getNodeData ();
    Node* getNextPointer ();
    void putNextPointer (Node*);
private:
    string st;
    Node* nextPtr;
};
//#include "BagList.h"
class BagList {  //Container class
public:
    BagList ();
    bool putANode (string);
    bool putANodeSorted (string);
    void getList ();
    Node* findNode (string);
    void  deleteNode (string);
    void getSortedList2();
    void getSortedList();
    
    //bool swap(Node*, Node*);
private:
    Node* ListPointer;
};


Node* Node::getNextPointer (){
    return nextPtr;
}
void Node::putNextPointer (Node* x){
    this->nextPtr = x;
}

Node* Node::putNode (Node* x, string s) {
    Node* temp = NULL;
    if (temp = new Node()) {
        temp->nextPtr = x;
        temp->st = s;
    }
    return temp;
}


Node* Node::putNodeSorted (Node* x, string s) {
    Node* newNode = new Node();
    Node* currentPtr = x;
    
    Node* Head = x;
    newNode->nextPtr = NULL;
    newNode->st = s;
    
    if (Head == NULL){
        return newNode;
    }
    else {
        currentPtr = Head;
        Node* previousPtr;
        int j = 0;
        bool breakout = true;
        
        while(breakout){
            
            if(newNode->getNodeData() < currentPtr->getNodeData()){
                breakout = false;
            }
            
            if(breakout){
                previousPtr = currentPtr;
                currentPtr = currentPtr->getNextPointer();
            }
            if(!currentPtr){
                breakout = false;
            }
        }
        
        //Put at Head:
        if(currentPtr == Head){
            newNode->putNextPointer(Head);
            return newNode;
        }
        else{
            newNode->putNextPointer(currentPtr);
            previousPtr->putNextPointer(newNode);
            return Head;
        }
        
        
    }
    return Head;
    
}
string Node::getNodeData() {
    return st;
}




BagList::BagList ()
{ListPointer = NULL;}
bool BagList::putANode (string udata) {
    bool x = false;
    Node* temp1;
    Node A;
    temp1 = A.putNode (ListPointer, udata);
    if (temp1 != NULL)
    {	ListPointer = temp1;
        x = true;
    }
    return x;
}



bool BagList::putANodeSorted (string udata) {
    bool x = false;
    Node* temp1;
    Node A;
    temp1 = A.putNodeSorted (ListPointer, udata);
    if (temp1 != NULL)
    {	ListPointer = temp1;
        x = true;
    }
    return x;
}


void BagList::getList() { // return value shoould be a string of concatenated variables
    Node* temp;
    for (temp = ListPointer; temp != NULL;temp = temp->getNextPointer())
        cout << " User Data " << temp->getNodeData () << endl;
}


void BagList::getSortedList(){
    Node * temphead = ListPointer;
    if(!temphead) return;
    Node* temp;
    int counter = 0;
    while (temphead)
    {
        temphead = temphead->getNextPointer();
        counter++;
    }
    
    string* StringArray = new string[counter]; // access to space for 5 ints in the program's Heap.
    int k = 0;
    for (temp = ListPointer; temp != NULL;temp = temp->getNextPointer()){
        StringArray[k] = temp->getNodeData();
        k++;
    }
    {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k - i - 1; ++j)
                if (StringArray[j] < StringArray[j + 1])
                {
                    string temp = StringArray[j];
                    StringArray[j] = StringArray[j + 1];
                    StringArray[j + 1] = temp;
                }
    }
    Node* newListPointer = NULL;
    Node* temp1;
    Node A;
    
    for (int i = 0; i < k; ++i){
        temp1 = A.putNode (newListPointer, StringArray[i]);
        if (temp1 != NULL){
            newListPointer = temp1;}
    }
    delete[] StringArray;
    ListPointer = newListPointer;
    
}





void BagList::getSortedList2(){
    Node* temp1;
    Node A;
    Node* newListPointer = NULL;
    Node* temp;
    while(ListPointer){
        Node* minimum = ListPointer;
        string strMin = minimum->getNodeData();
        for (temp = ListPointer; temp != NULL;temp = temp->getNextPointer()){
            if(temp->getNodeData() < strMin){
                strMin = temp->getNodeData();
            }
        }
        minimum = findNode (strMin);
        temp1 = A.putNode (newListPointer, strMin);
        if (temp1 != NULL){
            newListPointer = temp1;}
        deleteNode(strMin);
    }
    ListPointer = newListPointer;
    
}




Node* BagList::findNode (string udata){
    Node* temp;
    for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata;
         temp = temp->getNextPointer());
    return temp;
}
void BagList::deleteNode (string udata) {  // suggested by Yelena Oulenova
    Node* delPtr = findNode (udata);
    if (delPtr != NULL) {
        if (ListPointer == delPtr)
            ListPointer = delPtr->getNextPointer();
        else { 	Node* previousPtr;
            Node* temp = ListPointer;
            for (previousPtr = NULL; temp != delPtr;previousPtr = temp, temp = temp->getNextPointer());
            previousPtr->putNextPointer(delPtr->getNextPointer());
        }
        delete delPtr;
        delPtr = NULL; //clears any previous reference retained in this variable
        cout << "Node deleted: " << udata << endl;
    }
    else
        cout << "Node not found: " << udata << endl;
}


int main () {
    BagList A;  // declare a Container object
    string udata;
    bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Delete, Exit, Find, InsertSorted, Sort, List: ";
        cin >> sel;
        if (!cin.eof()) {
            switch (sel) {
                case 'A': case 'a': {
                    cout << "Enter a string of characters or control-z to end ";
                    cin >> udata;
                    if (!cin.eof())
                        cont = A.putANode(udata); // put in message instead of using cont.
                    break;
                }
                case 'D': case 'd': {
                    cout << "Please Enter User Data value to delete: ";
                    cin >> udata;
                    if (!cin.eof())
                        A.deleteNode (udata);
                    break;
                }
                case 'E': case 'e': {
                    cont = false;
                    cout <<endl<< "Program Exiting"<<endl;
                    break;
                }
                case 'F': case 'f': {
                    cout << "Please Enter User Data value to find: ";
                    cin >> udata;
                    if (!cin.eof())
                        if (A.findNode(udata))
                            cout << "Node " << udata << " found" << endl;
                        else
                            cout << "Node " << udata << " not found" << endl;
                    break;
                }
                case 'I': case 'i': {
                    cout << "Enter a string of characters or control-z to end ";
                    cin >> udata;
                    if (!cin.eof())
                        cont = A.putANodeSorted(udata); // put in message instead of using cont.
                    break;
                }
                case 'L': case 'l': {
                    cout << "List of nodes" << endl;
                    A.getList();
                    cout << endl;
                    break;
                }
                case 'S': case 's': {
                    cout << "Sorted list of nodes" << endl;
                    A.getSortedList();
                    A.getList();
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Invalid function entered." << endl;
                    break;
                }
            }
        }

        
    }
    cout <<endl<< "Program Exiting"<<endl;
    return 0;
}