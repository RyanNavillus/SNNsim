//
//  Neuron.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Neuron.hpp"

int potential;
int WPLACEHOLDER = 0;
int SYNAPSESPIKEPLACEHOLDER = 1;

Neuron::Neuron() {
    
}

bool Neuron::evaluatePotential() {
    for (int i = 0; i < inputSynapses.size(); i++) {
        potential += WPLACEHOLDER * SYNAPSESPIKEPLACEHOLDER;
    }
    return false;
}

