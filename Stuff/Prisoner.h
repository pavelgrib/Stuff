//
//  Prisoner.h
//  Stuff
//
//  Created by paulg on 09/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#ifndef __Stuff__Prisoner__
#define __Stuff__Prisoner__

#include <iostream>
#include <string>

using namespace std;

class Prisoner {
    int yearsLeft;
    int cell;
    string lastName;
    string firstName;
    bool psycho;

public:
    Prisoner();
    Prisoner(const string& last, const string& first, int yrsLeft, int cell);
    ~Prisoner();
    void setPsycho(bool isPsycho);

    inline bool is_psycho() const { return psycho; }
    inline int years_left() const { return yearsLeft; }
    inline string first_name() const { return firstName; }
    inline string last_name() const { return lastName; }
    inline int cell_no() const { return cell; }
};

#endif /* defined(__Stuff__Prisoner__) */

