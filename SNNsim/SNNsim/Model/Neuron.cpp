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

//Neuron::Neuron() {
//
//}

void Neuron::addOutput(Neuron &output) {
    // Check if a connection already exists to this node
    
    // Connect to the node
    OutSynapse synapse = OutSynapse(*this, output);
    outputSynapses.push_back(synapse);
}

bool Neuron::evaluatePotential() {
    // TODO: Implement potential
    for (int i = 0; i < inputSynapses.size(); i++) {
        potential += WPLACEHOLDER * SYNAPSESPIKEPLACEHOLDER;
    }
    return false;
}

