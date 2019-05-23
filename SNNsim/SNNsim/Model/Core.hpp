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
private:
    std::vector<std::shared_ptr<Neuron>> neurons;
    
public:
    std::string name;
    int timestep;
    std::vector<Axon> inputAxons;
    std::vector<Axon> outputAxons;
    
    static int coreCount;
    
    Core();
    void printCore();
    void step();
    void addNeuron(std::shared_ptr<Neuron>);
    // TODO:: Create a private method for interacting with inputAxons and outputAxons
    // to track fan-in and fan-out state
};

#endif /* Core_hpp */
