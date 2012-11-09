//
//  Prisoner.cpp
//  Stuff
//
//  Created by paulg on 09/11/2012.
//  Copyright (c) 2012 paulg. All rights reserved.
//

#include "Prisoner.h"

Prisoner::Prisoner(const string& last, const string& first, int yrsLeft, int cell) : lastName(last), firstName(first), yearsLeft(yrsLeft), cell(cell), psycho(false) { }

Prisoner::~Prisoner() { }

void Prisoner::setPsycho(bool isPsycho) {
    psycho = isPsycho;
}
