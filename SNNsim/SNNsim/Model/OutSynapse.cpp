//
//  OutSynapse.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "OutSynapse.hpp"

OutSynapse::OutSynapse(Neuron &source): source(source) {
    // TEST: Idk if axon will go out of scope, the entire C++ community seems worthless with explaining best practices for these situations.

    
    // TODO: Initialize Axon from current core to destination core
    //Axon axon (dest);
    //destination = &axon;
}

void OutSynapse::sendSpike() {
    for (int i = 0; i < destination->destinations.size(); i++) {
        destination->destinations[i]->destination.evaluatePotential(destination->destinations[i]->weight);
    }
}

