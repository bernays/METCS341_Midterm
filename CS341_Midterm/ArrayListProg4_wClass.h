//
//  ArrayListProg4_wClass.h
//  CS341_Midterm
//
//  Created by Ben Bernays on 10/27/15.
//  Copyright © 2015 Ben Bernays. All rights reserved.
//

#ifndef ArrayListProg4_wClass_h
#define ArrayListProg4_wClass_h

#define XMAXSIZE 10
using namespace std;

class Array {
public:
    Array() {listIdx = -1;}
    bool addElement (string);
    bool deleteElement (string);
    bool deleteElements (string);
    bool findElement (string);
    string listElements ();
private:
    string X [XMAXSIZE];
    int listIdx;
};
#endif /* ArrayListProg4_wClass_h */
