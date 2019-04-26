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
    int potential;
    static int neuronCount;
    std::vector<std::shared_ptr<InSynapse>> inputSynapses;
    std::vector<std::shared_ptr<OutSynapse>> outputSynapses;
    // TODO: Add treshold to initializer
    Neuron();   // Create empty neuron. Layer construction will handle weights
    void evaluatePotential(float weight);
    void addInput(Neuron &input);
    void printNeuron();
    virtual void spike();
};

#endif /* Neuron_hpp */
