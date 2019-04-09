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
    std::cout << "size: " << std::to_string(nodes.size()) << "\n";
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].printNode();
    }
    if (nextLayer) {
        nextLayer->printNetwork();
    }
}
