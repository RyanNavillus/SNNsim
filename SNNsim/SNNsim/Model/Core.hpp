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
    int fanIn = 0;
    int fanOut = 0;
    
public:
    static int coreCount;

    std::string name;
    int timestep; // Unused
    
    Core();
    void printCore();
    void step(); // Unused
    void addNeuron(std::shared_ptr<Neuron>);
    // TODO:: Create a private method for interacting with inputAxons and outputAxons
    // to track fan-in and fan-out state
};

#endif /* Core_hpp */
