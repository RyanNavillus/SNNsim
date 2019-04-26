//
//  OutputNeuron.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 4/26/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef OutputNeuron_hpp
#define OutputNeuron_hpp

#include <stdio.h>
#include "Neuron.hpp"

class Neuron;

#endif /* OutputNeuron_hpp */

class OutputNeuron : public Neuron {
public:
    int spikeCount;
    void spike() override;
};
