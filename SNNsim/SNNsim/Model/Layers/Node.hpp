//
//  Node.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 4/5/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "../Neuron.hpp"

class Neuron;

class Node {
public:
    std::vector<std::shared_ptr<Node>> inputs;
    std::vector<std::shared_ptr<Node>> outputs;
    std::vector<double> weights;
    double threshold;
    std::string name = "";
    std::shared_ptr<Neuron> neuron;
    static int nodeCount;
    
    Node();
    void printNode();
};

#endif /* Node_hpp */
