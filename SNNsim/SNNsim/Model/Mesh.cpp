//
//  Mesh.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Mesh.hpp"

using namespace std;

Mesh::Mesh() {
    cores[0] = Core();
}

Mesh::Mesh(Layer &model) {
    cores[0] = Core();
    Layer *currentLayer = &model;
    while (currentLayer != nullptr) {
        for (int i = 0; i < currentLayer->nodes.size(); i++) {
            // Create Neuron for each Node
            Neuron neuron = Neuron();
            cores[0].neurons.push_back(neuron);
            
            Node currentNode = currentLayer->nodes[i];
            
            // Create connections to the previous layer
            for (int j = 0; j < currentNode.inputs.size(); j++) {
                int previousIndex = (cores[0].neurons.size() - 1) - (currentNode.inputs.size() - 1) - i;
                Neuron &inputNeuron = cores[0].neurons[previousIndex + j];
                cores[0].neurons[cores[0].neurons.size() - 1].addInput(inputNeuron);
                
            }
        }
        
        currentLayer = currentLayer->nextLayer;
    }
}
