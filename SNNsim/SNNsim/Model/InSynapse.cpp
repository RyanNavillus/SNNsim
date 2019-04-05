//
//  InSynapse.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "InSynapse.hpp"

InSynapse::InSynapse(Neuron &source, Neuron &dest, double weight): destination(dest), weight(weight) {
    // TEST: Idk if axon will go out of scope, the entire C++ community seems worthless with explaining best practices for these situations.
    
    // TODO: Initialize Axon from current core to destination core
    Axon axon (source);
    InSynapse::source = &axon;
}
