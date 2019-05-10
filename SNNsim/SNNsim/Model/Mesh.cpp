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
    this->model = &model;
    Layer *currentLayer = &model;
    int layerCounter = 0; // Used to put each layer in Mesh.cores at index layerCounter
    
    // Iterate through each layer, creating neurons.
    while (currentLayer != nullptr) {
        for (int i = 0; i < currentLayer->nodes.size(); i++) {
            if (currentLayer->nextLayer == nullptr) {
                // Save node as an output
                auto currentNode = currentLayer->nodes[i];
                cores[127].neurons.push_back(std::make_shared<OutputNeuron>(currentNode->threshold));
                currentNode->neuron = cores[127].neurons.back();
                outputs.push_back((std::dynamic_pointer_cast<OutputNeuron>(currentNode->neuron)));
                continue;
            }
            
            // Get current node
            auto currentNode = currentLayer->nodes[i];
            
            // Add neuron to the current layer's core
            cores[layerCounter].neurons.push_back(std::make_shared<Neuron>(currentNode->threshold));
            
            // Save a reference to the neuron in the node to create connections later
            currentNode->neuron = cores[layerCounter].neurons.back();
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
            
            // Create an axon to connect input neuron to it's one or many output neurons
            // by attaching outputSynapses to inputSynapses.
            Axon::connect(axonInput, outputs);

        }
        currentLayer = currentLayer->nextLayer;
    }
}

std::vector<float> Mesh::run(std::vector<SpikeTrain> spikeTrains) {
    Layer *inputLayer = model;
    assert(spikeTrains.size() > 0);
    assert(inputLayer->nodes.size() == spikeTrains.size());
    
    int length = (int)spikeTrains[0].spikes.size();
    assert(length > 0);
    
    // TODO: Find the maximum spike train length. Pad any shorter trains with 0's
    
    // For each spike in the train, for each input neuron, if there is a spike, evaluate it
    // int i can be thought up as the current time step
    // int j selects the correct input neuron and corresponding spike train
    for (int i = 0; i < length; i++) {
        // Send spike through first layer
        for (int j = 0; j < inputLayer->nodes.size(); j++) {
            if (spikeTrains[j].spikes[i] == 1) {
                inputLayer->nodes[j]->neuron->increasePotential(1.0);
            }
        }
        
        Layer *currentLayer = model;
        while (currentLayer != nullptr) {
            for (int j = 0; j < currentLayer->nodes.size(); j++) {
                currentLayer->nodes[j]->neuron->evaluatePotential();
            }
            currentLayer = currentLayer->nextLayer;
        }
    }
   
    // After iterating, the final output node can be evaluated to find the output
    
    std::vector<float> outputValues;
    for (int i = 0; i < outputs.size(); i++) {
        outputValues.push_back(outputs[i]->spikeCount / (float)length);
    }
    
    return outputValues;
}

void Mesh::printMesh() {
    for (int i = 0; i < 128; i++) {
        cores[i].printCore();
    }
}
