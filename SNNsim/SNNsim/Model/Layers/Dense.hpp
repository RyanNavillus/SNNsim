//
//  Dense.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Dense_hpp
#define Dense_hpp

#include <stdio.h>
#include "Layer.hpp"

class Neuron;
class Layer;

class Dense: Layer {
public:
    Dense(int nodes);
    Dense(int nodes, Dense inputLayer);
    void connect(Dense layer, Dense nextLayer, std::vector<double> weights);
};
#endif /* Dense_hpp */
