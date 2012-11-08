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

class prolog_tests {
public:
    static bool* run_warders(int N, int W, bool* initial, int len);
    static void printBoolArray(bool* arr, int len);
    
    static bool cell_status(int cell, int N, bool status);
};

#endif /* defined(__Stuff__prolog_tests__) */
