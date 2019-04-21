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
#include "Layers/Layer.hpp"

class Core;
class Layer;

class Mesh {
public:
    Core cores[128];
    Mesh();
    Mesh(Layer &model);
    void synchronize(Core *core); // just itrate over them all
    void loadWeights(std::vector<float> weights);
    void printMesh();
    std::vector<float> run(std::vector<float> inputs);
    static int meshCount;
private:
    
};

#endif /* Mesh_hpp */
