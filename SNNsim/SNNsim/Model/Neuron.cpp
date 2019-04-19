//
//  Neuron.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Neuron.hpp"
#include <iostream>

int potential;
int WPLACEHOLDER = 0;
int SYNAPSESPIKEPLACEHOLDER = 1;

int Neuron::neuronCount = 0;

Neuron::Neuron() {
    neuronCount++;
    this->name = "N" + std::to_string(neuronCount);
}

void Neuron::addInput(Neuron &input) {
    // Check if a connection already exists to this node
    
    // Connect to the node
//    InSynapse in = InSynapse(input, *this);
//    inputSynapses.push_back(in);
//    
//    OutSynapse out = OutSynapse(input, *this);
//    input.outputSynapses.push_back(out);
}

bool Neuron::evaluatePotential() {
    // TODO: Implement potential
    for (int i = 0; i < inputSynapses.size(); i++) {
        potential += WPLACEHOLDER * SYNAPSESPIKEPLACEHOLDER;
    }
    return false;
}

void Neuron::printNeuron() {
    std::cout << "\t" << name << ":\n";
    for (int i = 0; i < outputSynapses.size(); i++) {
        OutSynapse synapse = *outputSynapses[i];
        for (int j = 0; j < synapse.destination->destinations.size(); j++) {
            std::cout << "\t\t" << name << "->" << synapse.destination->destinations[j]->destination.name << "\n";
        }
    }
}
