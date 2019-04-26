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
#include "SpikeTrain.hpp"
#include "OutputNeuron.hpp"


class Core;
class Layer;
class SpikeTrain;
class OutputNeuron;

class Mesh {
public:
    Core cores[128];
    Layer *model;
    Mesh();
    Mesh(Layer &model); // This should maybe pass-by-copy, need to test if model goes out of scope
    void synchronize(Core *core); // just itrate over them all
    void loadWeights(std::vector<float> weights);
    void printMesh();
    std::vector<float> run(std::vector<SpikeTrain> spikeTrain);
    static int meshCount;
private:
    std::vector<std::shared_ptr<OutputNeuron>> outputs;
};

#endif /* Mesh_hpp */
