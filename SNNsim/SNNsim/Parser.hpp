//
//  Parser.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include "Mesh.hpp"
#include "NetworkFile.hpp"

class Parser {
public:
    static Mesh parse(NetworkFile file) {
        
        return createXORMesh();
    }
private:
    static Mesh createXORMesh() {
        //Replace this with Layer class to handle connection logic
        Mesh mesh = Mesh();
        std::vector<Neuron> inInputs;
        Neuron input1 = Neuron(inInputs);
        Neuron input2 = Neuron(inInputs);
        std::vector<Neuron> hiddenInputs;
        hiddenInputs.push_back(input1);
        hiddenInputs.push_back(input2);
        Neuron hidden1 = Neuron(hiddenInputs);
        Neuron hidden2 = Neuron(hiddenInputs);
        std::vector<Neuron> outputInputs;
        outputInputs.push_back(hidden1);
        outputInputs.push_back(hidden2);
        Neuron output = Neuron(outputInputs);
        
        mesh.cores[0].neurons.push_back(input1);
        mesh.cores[0].neurons.push_back(input2);
        mesh.cores[0].neurons.push_back(hidden1);
        mesh.cores[0].neurons.push_back(hidden2);
        mesh.cores[0].neurons.push_back(output);

        return mesh;
    }
};

#endif /* Parser_hpp */
