//
//  BagMenuProg3B_wc.h
//  CS341_Midterm
//
//  Created by Ben Bernays on 10/26/15.
//  Copyright © 2015 Ben Bernays. All rights reserved.
//

#ifndef BagMenuProg3B_wc_h
#define BagMenuProg3B_wc_h
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


class Node {
public:
    Node () {}
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
    void getList ();
    Node* findNode (string);
    void  deleteNode (string);
private:
    Node* ListPointer;
};

#endif /* BagMenuProg3B_wc_h */
