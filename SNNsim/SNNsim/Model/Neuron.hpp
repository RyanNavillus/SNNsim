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
#include "InSynapse.hpp"
#include "OutSynapse.hpp"

class InSynapse;
class OutSynapse;

class Neuron {
public:
    int threshold;
    
    bool evaluatePotential();
private:
    std::vector<InSynapse> inputSynapses;
    std::vector<OutSynapse> outputSynapses;
};

#endif /* Neuron_hpp */
