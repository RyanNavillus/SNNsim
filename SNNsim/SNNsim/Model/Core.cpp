//
//  Core.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Core.hpp"
#include <iostream>
int Core::coreCount = 0;

Core::Core() {
    coreCount++;
    this->name = "Core " + std::to_string(coreCount);
}



void Core::printCore() {
    if (neurons.size() == 0) {
        return;
    }
    
    std::cout << name << ":\n";
    std::cout << "\tFan in: " << fanIn << ":\n";
    std::cout << "\tFan out: " << fanOut << ":\n";
    
    for (int i = 0; i < neurons.size(); i++) {
        neurons[i]->printNeuron();
    }
}

void Core::addNeuron(std::shared_ptr<Neuron> neuron) {
    //assert(neurons.size() < 1024);
    neurons.push_back(neuron);
    neuron->core = std::make_shared<Core>(*this);
    if (neurons.size() > 1024) {
        std::cout << name << ": The total number of neurons assigned to any core may not exceed 1,024 (Ncx).\n";
    }
    
    // TODO: Track Fan in
    // Should be the number of unique axons
    fanIn += neuron->inputSynapses.size();
    
    // TODO: Track Fan out
    // This assumes that each axon points to exactly one core
    fanOut += neuron->outputSynapses.size();
}

