//
//  Mesh.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "Core.hpp"

class Core;

class Mesh {
private:
    Core cores[128];
    
    void synchronize(Core *core);
    void loadWeights(std::vector<float> weights);
    std::vector<float> run(std::vector<float> inputs);
    
};

#endif /* Mesh_hpp */
