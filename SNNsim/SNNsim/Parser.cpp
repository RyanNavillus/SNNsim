//
//  Parser.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include <iostream>
#include "Parser.hpp"
#include <string>
#include "Model/Layers/Dense.hpp"

/*Mesh Parser::parse(NetworkFile file) {
    return Mesh(); // Placeholder
}*/

Mesh Parser::parse(NetworkFile file) {
    // Testing
    // TODO: Delete
    return createXORMesh();
}

Mesh Parser::createXORMesh() {
        //Replace this with Layer class to handle connection logic
        Mesh mesh = Mesh();
//        std::vector<Neuron> inInputs;
//        Neuron input1 = Neuron(inInputs);
//        Neuron input2 = Neuron(inInputs);
//        std::vector<Neuron> hiddenInputs;
//        hiddenInputs.push_back(input1);
//        hiddenInputs.push_back(input2);
//        Neuron hidden1 = Neuron(hiddenInputs);
//        Neuron hidden2 = Neuron(hiddenInputs);
//        std::vector<Neuron> outputInputs;
//        outputInputs.push_back(hidden1);
//        outputInputs.push_back(hidden2);
//        Neuron output = Neuron(outputInputs);
//
//        mesh.cores[0].neurons.push_back(input1);
//        mesh.cores[0].neurons.push_back(input2);
//        mesh.cores[0].neurons.push_back(hidden1);
//        mesh.cores[0].neurons.push_back(hidden2);
//        mesh.cores[0].neurons.push_back(output);
    
    Dense L1 = Dense(2, "input");
    Dense L2 = Dense(2, L1, {1,2,3,4}, "hidden");
    Dense L3 = Dense(1, L2, {1,2}, "output");
    L1.printNetwork();
    return mesh;
}
