//
//  Node.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 4/5/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Node.hpp"
#include <iostream>

int Node::nodeCount = 0;

Node::Node() {
    nodeCount++;
    this->name = std::to_string(nodeCount);
    this->neuron = nullptr;
}

void Node::printNode() {
    for (int i = 0; i < inputs.size(); i++) {
        std::cout << inputs[i].get()->name << "->" << name << " = " << std::to_string(weights[i]) << "\n";
    }
}
