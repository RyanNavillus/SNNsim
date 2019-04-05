//
//  InSynapse.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef InSynapse_hpp
#define InSynapse_hpp

#include <stdio.h>
#include "Synapse.hpp"
#include "Axon.hpp"
#include "Neuron.hpp"

class Axon;
class Neuron;

class InSynapse: public Synapse {
    Axon *source;
    Neuron &destination;
    double weight;
    
public:
    InSynapse(Neuron &source, Neuron &dest, double weight = 0);
};

#endif /* InSynapse_hpp */
