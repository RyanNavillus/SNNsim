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
    float threshold;
    float potential;
    static int neuronCount;
    std::vector<std::shared_ptr<InSynapse>> inputSynapses;
    std::vector<std::shared_ptr<OutSynapse>> outputSynapses;
    // TODO: Add treshold to initializer
    Neuron(float threshold = 0);   // Create empty neuron. Layer construction will handle weights
    void increasePotential(float weight);
    void evaluatePotential();
    void addInput(Neuron &input);
    void printNeuron();
    virtual void spike();

private:
    void leak();
};

#endif /* Neuron_hpp */
