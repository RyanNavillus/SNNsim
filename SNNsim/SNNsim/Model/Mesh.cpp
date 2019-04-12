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
    Layer *currentLayer = &model;
    int layerCounter = 0; // Used to put each layer in Mesh.cores at index layerCounter
    
    // Iterate through each layer, creating neurons.
    while (currentLayer != nullptr) {
        cores[layerCounter] = Core();
        for (int i = 0; i < currentLayer->nodes.size(); i++) {
            // Get current node
            Node currentNode = *(currentLayer->nodes[i]);
            
            // Create neuron for node
            Neuron neuron = Neuron();
            
            // Add neuron to the current layer's core
            cores[layerCounter].neurons.push_back(neuron);
            
            // Save a reference to the neuron in the node to create connections later
            currentNode.neuron = &cores[layerCounter].neurons.back();
        }
        currentLayer = currentLayer->nextLayer;
        layerCounter++;
    }
    
    // Iterate again, this time adding in connections
    currentLayer = &model;
    while (currentLayer != nullptr) {
        for (int i = 0; i < currentLayer->nodes.size(); i++) {
            Node currentNode = *(currentLayer->nodes[i]);
            
            // Collect all outputs
            std::vector<std::shared_ptr<InSynapse>> outputs {};
            for (int j = 0; j < currentNode.outputs.size(); j++) {
                std::shared_ptr<InSynapse> inSynapse = std::make_shared<InSynapse>(*currentNode.outputs[j]->neuron);
                currentNode.outputs[i]->neuron->inputSynapses.push_back(inSynapse);
                outputs.push_back(inSynapse);
            }
            
            // Create connection from input to set of all outputs
            // TODO: Ensure each Axon points to exactly 1 Core
            std::shared_ptr<OutSynapse> axonInput = std::make_shared<OutSynapse>(*currentNode.neuron);
            
            currentNode.neuron->outputSynapses.push_back(axonInput);
            
            Axon axon (axonInput, outputs);
            
        }
    }
}

void Mesh::printMesh() {
    for (int i = 0; i < 128; i++) {
        cores[i].printCore();
    }
}
