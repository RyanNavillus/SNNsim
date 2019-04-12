//
//  Neuron.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <string>
#include "InSynapse.hpp"
#include "OutSynapse.hpp"

class InSynapse;
class OutSynapse;

class Neuron {
public:
    std::string name;
    int threshold;
    static int neuronCount;
    std::vector<std::shared_ptr<InSynapse>> inputSynapses;
    std::vector<std::shared_ptr<OutSynapse>> outputSynapses;
    
    Neuron();   // Create empty neuron. Layer construction will handle weights
    bool evaluatePotential();
    void addInput(Neuron &input);
    void printNeuron();

};

#endif /* Neuron_hpp */
