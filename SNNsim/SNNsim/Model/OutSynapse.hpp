//
//  OutSynapse.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef OutSynapse_hpp
#define OutSynapse_hpp

#include <stdio.h>
#include "Axon.hpp"
#include "Neuron.hpp"
#include "Synapse.hpp"

class Axon;
class Neuron;

class OutSynapse: public Synapse {
    Neuron &source;
    Axon *destination;
public:
    OutSynapse(Neuron &source, Neuron &dest);
};


#endif /* OutSynapse_hpp */
