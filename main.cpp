/* 
 * File:   main.cpp
 * Author: chachalaca
 *
 * Created on 10. červenec 2013, 9:20
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <list>
#include <fstream>


#include "LinkedList.h"
#include "Node.h"

using namespace std;

Node *node1;
Node *node2;
Node *node3;
string fnames;
short lfnames;
char* fname;
int i;
ifstream soubor;
/*
 * 
 */
int main(int argc, char** argv) {
    LinkedList *list = new LinkedList();
    
    ifstream infile;
    infile.open ("data.txt");
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a;
        if (!(iss >> a)) { break; } // error

        list->addLast(a);
    }
   
    list->selSort();
    
    for (int i = 1; i <= list->getSize(); i++) {
        cout << list->getValue(i)<<endl;

    }

    
    
}

