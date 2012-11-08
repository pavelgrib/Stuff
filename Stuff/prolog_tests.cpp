//
//  prolog_tests.cpp
//  Stuff
//
//  Created by paulg on 07/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#include "prolog_tests.h"

bool* prolog_tests::run_warders(int N, int W, bool* initial, int len) {
    bool* final = new bool[len];
    for ( int i = 0; i < len; i++ ) {
        final[i] = initial[i];
    }
    for (; N <= W; N++) {
        for ( int i = 0; i < len; i++ ) {
            if ( (i+1) % N == 0 ) {
                final[i] = ( final[i] ? false : true);
            }
        }
    }
    

    return final;
}

void prolog_tests::printBoolArray(bool* arr, int len) {
    for ( int i = 0; i < len; i++ ) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool prolog_tests::cell_status(int cell, int N, bool status) {
    for ( int i = 0; i < N; i++ ) {
        status = (cell % (i+1) == 0) ? !status : status;
    }
    return status;
}