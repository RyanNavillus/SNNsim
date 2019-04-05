//
//  Axon.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Axon.hpp"

Axon::Axon() {
    
}

Axon::Axon(Neuron destination) : source(std::pair<Core *, int>()), destination(std::pair<Core *, int>()) {
    
}
