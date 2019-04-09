//
//  Layer.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Layer.hpp"
#include <iostream>

void Layer::printNetwork() {
    std::cout << "Layer: " << name << "\n";
    std::cout << "nodes: {";
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << nodes[i]->name;
        if ( i != nodes.size()-1) {
            std:: cout << ",";
        }
    }
    std::cout << "} \n";
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i]->printNode();
    }
    std::cout << "\n";
    if (nextLayer) {
        nextLayer->printNetwork();
    }
}
