//
//  Dense.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Dense.hpp"
#include <iostream>

Dense::Dense(int nodes) {
    for (int i = 0; i < nodes; i++) {
        // For each node, create a neuron
        neurons.push_back(Neuron());
    }
}

// TODO: Allow user to initialize with layer weights
Dense::Dense(int nodes, Dense inputLayer) : Dense::Dense(nodes) {
    // Check if neurons were constructed correctly
    assert(nodes == neurons.size());
    
    // Choose default weights when connecting
    Dense::connect(inputLayer, *this, std::vector<double>());
}

void Dense::connect(Dense inpuTayer, Dense nextLayer, std::vector<double> weights) {
    // TODO: Implement layer connections
    
}
