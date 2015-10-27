// John Maslanka  BagMenuProg3-withContainer.cpp Baglist Demo  10/17/2010
// Note: This application contains a delete method to remove a Node from the
//       linked list. This program tests the return value from the new operator.

// Edit:	09/30/2009 Create Bagmenu top-level access to BagList application.
// Edit:	10/17/2010 Complete rewrite of delete method to decouple it from
//          the main.
//			Also fixed bug which caused the end of the list to be lost when a
//			memberin the middle was deleted.
//          Also, suggestions from student Yelena Oulanova to do delete cleanly.
// Edit:	02/15/2012 Changed some method names to more closely
//			reflect the actions of their procedures
// Edit:	02/20/2012 Changed User input from double to string type

using namespace std;

#include "BagMenuProg3B_wc.h"

Node* Node::getNextPointer (){
    return nextPtr;
}
void Node::putNextPointer (Node* x){
    this->nextPtr = x;
}
Node* Node::putNode (Node* x, string s) {
    Node* temp = new Node();
    Node* temp2 = x;

    Node* ListPointer = x;
    
    if (ListPointer == NULL){
        if (temp) {
            temp->nextPtr = NULL;
            temp->st = s;
            return temp;

        }
    }
    else {
        temp2 = x;
        Node* previousPtr;
        int j = 0;
        previousPtr = NULL;
        bool breakout = true;
        while(temp2->getNextPointer() && breakout){
            if(s < temp2->getNodeData()) breakout = false;
            previousPtr = temp2;
            temp2 = temp2->getNextPointer();

            j++;
        };
        if( j<1){
            //previousPtr->putNextPointer(this);
            if (temp) {
                temp->nextPtr = temp2;
                temp->st = s;
            }
            return temp;

        }

        if( j>0){
            previousPtr->putNextPointer(temp);
            if (temp) {
                if(temp2->getNextPointer()){
                    temp->nextPtr =temp2;

                }
                else{
                    temp->nextPtr = temp2;

                }
                temp->st = s;
            }

        }
    }

    return x;

    
    
    
    
    

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

void BagList::getList() { // return value shoould be a string of concatenated variables
    Node* temp;
    for (temp = ListPointer; temp != NULL;temp = temp->getNextPointer())
        cout << " User Data " << temp->getNodeData () << endl;
}


void BagList::getSortedList(){
    Node * temphead = ListPointer;
    Node* temp;
    int counter = 0;
    while (temphead)
    {
        temphead = temphead->getNextPointer();
        counter++;
    }
    
    string* StringArray;
    StringArray = new string[counter]; // access to space for 5 ints in the program's Heap.
    int k = 0;
    for (temp = ListPointer; temp != NULL;temp = temp->getNextPointer()){
        StringArray[k] = temp->getNodeData();
        k++;
    }
    for (int i = 0; i < k; ++i)
        cout << StringArray[i] << endl;

    
    cout << "SORTED: " <<endl;
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
    delete StringArray;
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