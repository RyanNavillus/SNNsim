//
//  Axon.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Axon.hpp"

Axon::Axon(std::shared_ptr<OutSynapse> source, std::vector<std::shared_ptr<InSynapse>> destinations): source(source), destinations(destinations) {
}

// Create an axon to connect input neuron to it's one or many output neurons
// by attaching outputSynapses to inputSynapses.
void Axon::connect(std::shared_ptr<OutSynapse> source, std::vector<std::shared_ptr<InSynapse>> destinations) {
    Axon *axon = new Axon(source, destinations);
    axon->source->destination = axon;
    for (int i = 0; i < axon->destinations.size(); i++) {
        axon->destinations[i]->source = axon;
    }
}
