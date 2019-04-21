//
//  Mesh.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include "Mesh.hpp"
#include <iostream>

using namespace std;

int Mesh::meshCount = 0;
Mesh::Mesh() {
    meshCount++;
}

Mesh::Mesh(Layer &model): Mesh() {
    Layer *currentLayer = &model;
    int layerCounter = 0; // Used to put each layer in Mesh.cores at index layerCounter
    
    // Iterate through each layer, creating neurons.
    while (currentLayer != nullptr) {
        for (int i = 0; i < currentLayer->nodes.size(); i++) {
            // Get current node
            auto currentNode = currentLayer->nodes[i];
            
            // Add neuron to the current layer's core
            cores[layerCounter].neurons.push_back(std::make_shared<Neuron>());
            
            // Save a reference to the neuron in the node to create connections later
            currentNode->neuron = cores[layerCounter].neurons.back();
            int p = 0;
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
                // Get the weight from the output neuron
                double weight = 0;
                for (int k = 0; k < currentNode.outputs[j]->inputs.size(); k++) {
                    if (currentNode.outputs[j]->inputs[k]->name == currentNode.name) {
                        weight = currentNode.outputs[j]->weights[k];
                    }
                }
                std::shared_ptr<InSynapse> inSynapse = std::make_shared<InSynapse>(*currentNode.outputs[j]->neuron, weight);
                currentNode.outputs[j]->neuron->inputSynapses.push_back(inSynapse);
                outputs.push_back(inSynapse);
            }
            
            // Create connection from input to set of all outputs
            // TODO: Ensure each Axon points to exactly 1 Core
            std::shared_ptr<OutSynapse> axonInput = std::make_shared<OutSynapse>(*currentNode.neuron);
            
            currentNode.neuron->outputSynapses.push_back(axonInput);
            
            // This code has important side effects. It should be rewritten
            Axon *axon = new Axon(axonInput, outputs);
        }
        currentLayer = currentLayer->nextLayer;
    }
}

std::vector<float> Mesh::run(std::vector<float> inputs) {
    
    return std::vector<float>();
}

void Mesh::printMesh() {
    for (int i = 0; i < 128; i++) {
        cores[i].printCore();
    }
}
