//
//  Layer.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <stdio.h>
#include "../Neuron.hpp"
#include "Node.hpp"

class Node;

class Layer {
protected:
    std::vector<Node> nodes;

};

#endif /* Layer_hpp */
