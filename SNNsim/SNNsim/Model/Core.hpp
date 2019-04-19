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
#include <string>
#include "Axon.hpp"
#include "Neuron.hpp"

class Axon;
class Neuron;

class Core {
public:
    std::string name;
    int timestep;
    std::vector<std::shared_ptr<Neuron>> neurons;
    std::vector<Axon> inputAxons;
    std::vector<Axon> outputAxons;
    
    static int coreCount;
    
    Core();
    void printCore();
    void step();
};

#endif /* Core_hpp */
