//
//  Axon.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Axon.hpp"

Axon::Axon(OutSynapse &source, std::vector<std::shared_ptr<InSynapse>> destinations): source(source), destinations(destinations) {
    source.destination = this;
    
    for (int i = 0; i < destinations.size(); i++) {
        destinations[i]->source = this;
    }
}

/*Axon::Axon(Neuron destination) : source(std::pair<Core *, int>()), destination(std::pair<Core *, int>()) {
    
}*/
