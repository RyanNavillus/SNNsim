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

class Node {
public:
    Node();
    std::vector<Node> inputs;
    std::vector<double> weights;
    std::string name = "";
    static int nodeCount;
    void printNode();
};

#endif /* Node_hpp */
