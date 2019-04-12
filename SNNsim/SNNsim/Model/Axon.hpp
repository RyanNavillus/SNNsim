//
//  Axon.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Axon_hpp
#define Axon_hpp

#include <stdio.h>
#include <utility>
#include "Core.hpp"
#include "Neuron.hpp"
#include "InSynapse.hpp"
#include "OutSynapse.hpp"

class Core;
class Neuron;
class InSynapse;
class OutSynapse;

class Axon {
public:
    std::shared_ptr<OutSynapse> source;
    std::vector<std::shared_ptr<InSynapse>> destinations;
    int wgt;
    int dly;
    int tag;
    
    Axon();
    Axon(std::shared_ptr<OutSynapse> source, std::vector<std::shared_ptr<InSynapse>> destinations = std::vector<std::shared_ptr<InSynapse>>());
};

#endif /* Axon_hpp */
