//
//  main.cpp
//  Stuff
//
//  Created by paulg on 07/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#include <iostream>
#include "prolog_tests.h"

using namespace std;

int main(int argc, const char * argv[])
{
//    int N, W, len;
//    std::cin >> N >> W >> len;
//    bool* arr = new bool[len];
//    int temp;
//    for ( int i = 0; i < len; i++ ) {
//        std::cin >> temp;
//        arr[i] = (bool) temp;
//    }
    
//    bool* out = prolog_tests::run_warders(N, W, arr, len);
    
    cout << prolog_tests::cell_status(2, 3, 1) << endl;
    return 0;
}

