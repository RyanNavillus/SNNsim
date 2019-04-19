//
//  Core.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Core.hpp"
#include <iostream>
int Core::coreCount = 0;

Core::Core() {
    coreCount++;
    this->name = "C" + std::to_string(coreCount);
}

void Core::printCore() {
    if (neurons.size() == 0) {
        return;
    }
    
    std::cout << name << ":\n";
    for (int i = 0; i < neurons.size(); i++) {
        neurons[i]->printNeuron();
    }
}
