//
//  prolog_tests.cpp
//  Stuff
//
//  Created by paulg on 07/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#include "prolog_tests.h"

prolog_tests::prolog_tests() : loaded(false) {}
prolog_tests::~prolog_tests() {}

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
    if ( !loaded ) this->load_db();

    list<Prisoner*> temp = prisonersInCell(cell);
    list<Prisoner*>::const_iterator it2;
    bool shouldOpen = true;

    for ( it2=temp.begin(); it2 != temp.end(); it2++ ) {
        if ( (*it2)->is_psycho() ) shouldOpen = false;
    }
    for ( int i = 0; i < N; i++ ) {
        status = (shouldOpen && (cell % (i + 1) == 0)) ? !status : status;
    }
    return status;
}

int prolog_tests::load_db() {
    ifstream f("/Users/paul/Dropbox/Imperial/prolog/prisonDb.pl");
    if ( f.is_open() ) {
        string s, last, first;
        size_t step, pos = 0;
        int cell_no, yearsLeft;
        while ( !f.eof() ) {
            getline(f, s);
            if ( s.find("prisoner") != string::npos ) {
                pos = s.find_first_of("'")+1;
                if ( pos != string::npos ) {
                    step = s.substr(pos).find_first_of("'");
                    last = s.substr(pos, step);
                    pos += step + 4;
                    step = s.substr(pos).find_first_of("'");
                    first = s.substr(pos, step);
                    pos += step + 3;
                    step = s.substr(pos).find_first_of(",");
                    istringstream buff(s.substr(pos, step));
                    buff >> cell_no;
                    buff.clear();
                    pos = s.find_last_of(",") + 2;
                    step = s.substr(pos).find(")");
                    buff.str( s.substr(pos, step) );
                    buff >> yearsLeft;
                    string index = last + first;
                    Prisoner* p = new Prisoner(last, first, yearsLeft, cell_no);
                    prisoner_cells[cell_no].push_back(p);
                    prisoner_names[index] = p;

                }
            }
            
            if ( s.find("psychopath") != string::npos ) {
                pos = s.find_first_of("'")+1;
                if ( pos != string::npos ) {
                    step = s.substr(pos).find_first_of("'");
                    last = s.substr(pos, step);
                    pos += step + 4;
                    step = s.substr(pos).find_first_of("'");
                    first = s.substr(pos, step);
                    map<string,Prisoner*>::iterator it = prisoner_names.find(last+first);
                    if ( it != prisoner_names.end() ) {
                        it->second->setPsycho(true);
//                        cout << "psycho: " << it->second->first_name() << " " << it->second->last_name() << endl;
                    }
                }
            }
        }
    }
    loaded = true;
    return (int)prisoner_names.size();
}

list<Prisoner*> prolog_tests::prisonersInCell(int cell) {
    if ( !loaded ) this->load_db();
    return prisoner_cells[cell];
}

vector<Prisoner*> prolog_tests::escaped(int N, int W) {
    if ( !loaded ) this->load_db();
    vector<Prisoner*> esc;
    
    list<Prisoner*>::const_iterator list_it;
    for ( int j = 1; j < N; j++ ) {
        if ( this->cell_status_db(j, W, false) ) {
            list<Prisoner*> temp = prisonersInCell(j);
            for ( list_it = temp.begin(); list_it != temp.end(); list_it++) {
                if ( (*list_it)->years_left() > 1 ) esc.push_back(*list_it);
            }
        }
    }
    return esc;
}

int prolog_tests::pris_in_cell(int cell) {
    return (int)prisonersInCell(cell).size();
}

void prolog_tests::printVector(vector<Prisoner*> vp) {
    vector<Prisoner*>::const_iterator v_it;
    int k = 1;
    for ( v_it = vp.begin(); v_it != vp.end(); v_it++ ) {
        cout << k << ") " << (*v_it)->last_name() << ", " << (*v_it)->first_name() << " in cell " << (*v_it)->cell_no() << endl;
        k++;
    }
}

int prolog_tests::escape_from_cell(int cell) {
    list<Prisoner*> l = prisonersInCell(cell);
    list<Prisoner*>::const_iterator list_it;
    int count = 0;
    for ( list_it = l.begin(); list_it != l.end(); list_it++ ) {
        if ( (*list_it)->years_left() > 1 ) count++;
    }
    return count;
}