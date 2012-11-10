//
//  prolog_tests.h
//  Stuff
//
//  Created by paulg on 07/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#ifndef __Stuff__prolog_tests__
#define __Stuff__prolog_tests__

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "Prisoner.h"

using namespace std;

class prolog_tests {
    map<int, list<Prisoner*>> prisoner_cells;
    map<string, Prisoner*> prisoner_names;
    bool loaded;
public:
    prolog_tests();
    ~prolog_tests();
    static bool* run_warders(int N, int W, bool* initial, int len);
    static void printBoolArray(bool* arr, int len);
    
    static bool cell_status(int cell, int N, bool status);
    bool cell_status_db(int cell, int N, bool status);
    int load_db();
    vector<Prisoner*> escaped(int N, int W);
    list<Prisoner*> prisonersInCell(int cell);
    int pris_in_cell(int cell);
    static void printVector(vector<Prisoner*> vp);
    int escape_from_cell(int cell);
};

#endif /* defined(__Stuff__prolog_tests__) */
