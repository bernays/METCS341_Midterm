//
//  main.cpp
//  CS341_Midterm
//
//  Created by Ben Bernays on 10/26/15.
//  Copyright © 2015 Ben Bernays. All rights reserved.
//

#include <iostream>
#include "BagMenuProg3B_wc.h"
#include <string>
#include <iostream>
using namespace std;


int main () {
    BagList A;  // declare a Container object
    string udata;
    bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Delete, Exit, Find, List: ";
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
                case 'L': case 'l': {
                    cout << "List of nodes" << endl;
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
    //	system ("PAUSE");
    return 0;
}
