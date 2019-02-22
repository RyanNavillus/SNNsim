//
//  Core.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include <stdio.h>
#include <vector>
#include "Axon.hpp"
#include "Neuron.hpp"

class Axon;
class Neuron;

class Core {
private:
    std::vector<Neuron> neurons;
public:
    int timestep;
    std::vector<Axon> inputAxons;
    std::vector<Axon> outputAxons;
    
    void step();
};

#endif /* Core_hpp */
