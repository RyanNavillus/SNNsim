//
//  OutputNeuron.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 4/26/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "OutputNeuron.hpp"

void OutputNeuron::spike() {
    spikeCount++;
    Neuron::spike();
}
