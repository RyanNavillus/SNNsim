//
//  Dense.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Dense.hpp"

Dense::Dense(int nodes) {
    for (int i = 0; i < nodes; i++) {
        // For each node, create a neuron
    }
}

Dense::Dense(int nodes, Dense inputLayer) : Dense::Dense(nodes) {
    
}

void Dense::connect(Dense layer, Dense nextLayer, std::vector<double> weights) {
    
}
