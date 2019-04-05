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
        this->nodes.push_back(Node());
    }
}

Dense::Dense(int nodes, Dense inputLayer) : Dense::Dense(nodes) {
    // Check if neurons were constructed correctly
    assert(nodes == this->nodes.size());
    
    // TODO: Choose default weights when connecting
    
    // Create connections from the input layer
    Dense::connect(inputLayer, *this, std::vector<double>());
}

Dense::Dense(int nodes, Dense inputLayer, std::vector<double> weights) : Dense::Dense(nodes) {
    // Check if neurons were constructed correctly
    assert(nodes == this->nodes.size());
    
    // Create connections from the input layer
    Dense::connect(inputLayer, *this, weights);
}

void Dense::connect(Dense inputLayer, Dense nextLayer, std::vector<double> weights) {
    // Check for the correct number of weights
    assert(weights.size() == inputLayer.nodes.size() * nextLayer.nodes.size());
    
    // TODO: Implement layer connections
    
    // TODO: Connect every node inputLayer to every node in outputLayer
    for (int i = 0; i < nodes.size(); i++) {
        
    }
    
}
