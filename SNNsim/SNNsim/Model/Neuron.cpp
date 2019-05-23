//
//  Neuron.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Neuron.hpp"
#include <iostream>

int Neuron::neuronCount = 0;

Neuron::Neuron(float threshold): threshold(threshold) {
    neuronCount++;
    potential = 0;
    this->name = "Neuron " + std::to_string(neuronCount);
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

void Neuron::increasePotential(float weight) {
    potential += weight;
}

void Neuron::evaluatePotential() {
    if (potential > threshold) {
        spike();
        potential = 0;
    } else {
        leak();
    }
}

void Neuron::leak() {
    potential -= 0.9;
}

void Neuron::spike() {
    //std::cout << "Spike: " << name << "\n";
    for (int i = 0; i < outputSynapses.size(); i++) {
        outputSynapses[i]->sendSpike();
    }
}

void Neuron::printNeuron() {
    std::cout << "\t" << name << " {" << threshold << "}" <<":\n";
    for (int i = 0; i < outputSynapses.size(); i++) {
        OutSynapse synapse = *outputSynapses[i];
        for (int j = 0; j < synapse.destination->destinations.size(); j++) {
            std::cout << "\t\t" << name << " -> " << synapse.destination->destinations[j]->destination.name << " {" << std::to_string(synapse.destination->destinations[j]->weight) << "}\n";
        }
    }
}
