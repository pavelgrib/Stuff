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

bool prolog_tests::cell_status_db(int cell, int N, bool status) {

    ifstream f("/Users/paul/Dropbox/Imperial/prolog/prisonDb.pl");
    
    if ( f.is_open() ) {
        string s, last, first;
        size_t n1, n2;
        int cell_no, yearsLeft;
        map<string, Prisoner*> prisoners_name;
        map<int, Prisoner*> prisoners_cell;
        while ( !f.eof() ) {
            getline(f, s);
            if ( s.find("prisoner") ) {
                n1 = s.find_first_of("(");
                n2 = s.find_first_of(",");
                if ( (n1 + n2) < s.length() ) {
                    last = s.substr(n1, (n2-n1));
                    n1 = s.substr(n2).find_first_of(",");
                    first = s.substr(n2, (n1-n2));
                    n2 = s.substr(n1).find_first_of(",");
                    istringstream buff(s.substr(n1, (n2-n1)));
                    buff >> cell_no;
                    buff.clear();
                    n1 = s.find_last_of(",");
                    n2 = s.find(")");
                    buff.str( s.substr(n1, (n2-n1)) );
                    buff >> yearsLeft;
                    string index = last + "," + first;
                    Prisoner* p = new Prisoner(last, first, yearsLeft, cell_no);
                    prisoners_name[index] = p;
//                  prisoners_cell[cell_no] = *p;
                }
            }
            
            if ( s.find("psychopath") ) {
                n1 = s.find_first_of("(");
                n2 = s.find_first_of(",");
                if ( (n1+n2) < s.length() ) {
                    last = s.substr(n1, (n2-n1));
                    n1 = s.substr(n2).find_first_of(",");
                    first = s.substr(n2, (n1-n2));
                    n2 = s.substr(n1).find_first_of(",");
                    map<string,Prisoner*>::iterator it = prisoners_name.find(last.append(",").append(first));
                    if ( it != prisoners_name.end() ) {
                        it->second->setPsycho(true);
                    }
                }
            }
        }
        map<int, Prisoner*>::iterator it2 = prisoners_cell.find(cell);
        bool shouldOpen = true;
        bool shouldEscape = true;
        while ( it2 != prisoners_cell.end() ) {
            if ( it2->second->is_psycho() ) shouldOpen = false;
            if ( it2->second->years_left() < 2 ) shouldEscape = false;
        }
        for ( int i = 0; i < N; i++ ) {
            status = (shouldOpen && (cell % (i + 1) == 0)) ? !status : status;
        }
    }
    return status;
}