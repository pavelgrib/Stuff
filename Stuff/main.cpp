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
    
//    cout << prolog_tests::cell_status(2, 3, 1) << endl;
    prolog_tests pt;
//    prolog_tests::printVector(pt.escaped(80, 30));
    int count = 0;
    int pris_count = 0;
    int temp = 0;
    int temp2 = 0;
    int escaped = 0;
    for ( int i = 1; i <= 80; i++ ) {
        temp = pt.escape_from_cell(i);
        temp2 = pt.cell_status_db(i, 30, false);
        cout << i << ") " << temp2 << " " << temp << endl;
        count += temp2;
        pris_count += temp;
        escaped += temp*temp2;
    }
    cout << "count " << count << "; prisoners " << pris_count << "; escaped " << escaped << endl;
    
    
//    string s = "hello, world!";
//    size_t n = s.find(",");
//    size_t p = s.substr(n+2).find("!");
//    cout << s.substr(n + 2,p) << endl;
    
    return 0;
}


