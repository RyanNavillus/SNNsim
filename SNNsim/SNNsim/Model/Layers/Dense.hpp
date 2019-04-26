//
//  Dense.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/24/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Dense_hpp
#define Dense_hpp

#include <stdio.h>
#include "Layer.hpp"

class Layer;

class Dense: public Layer {
public:
    Dense(int nodes, std::vector<double> thresholds, std::string name = "");
    Dense(int nodes, Dense &inputLayer, std::vector<double> thresholds, std::vector<double> weights, std::string name = "");
    static void connect(Dense &inputLayer, Dense &nextLayer, std::vector<double> weights);
};
#endif /* Dense_hpp */
