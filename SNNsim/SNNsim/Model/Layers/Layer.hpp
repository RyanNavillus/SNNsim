//
//  Layer.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <stdio.h>
#include "../Neuron.hpp"

class Neuron;

class Layer {
    std::vector<Neuron> neurons;
};

#endif /* Layer_hpp */
