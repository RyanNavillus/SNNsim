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
#include "Model/SpikeTrain.hpp"

/*Mesh Parser::parse(NetworkFile file) {
    return Mesh(); // Placeholder
}*/

Mesh Parser::parse(NetworkFile file) {
    // Testing
    // TODO: Delete
    return createXORMesh();
}

Mesh Parser::createXORMesh() {
    Dense L1 = Dense(2, {0,0}, "input");
    Dense L2 = Dense(2, L1, {1.9,0}, {1,1,1,1}, "hidden");
    Dense L3 = Dense(1, L2, {0}, {-1,1}, "output");
    
    Dense ANDNOT1 = Dense(2, {0,0}, "input");
    Dense ANDNOT2 = Dense(1, ANDNOT1, {1}, {2,-1}, "X1 and not X2");
    
    Dense AND1 = Dense(2, {0,0}, "input");
    Dense AND2 = Dense(1, AND1, {1}, {1,1}, "X1 and X2");
    
    Dense OR1 = Dense(2, {0,0}, "input");
    Dense OR2 = Dense(1, OR1, {2}, {2,2}, "X1 or X2");
    
    Dense XOR1 = Dense(2, {0,0}, "input");
    Dense XOR2 = Dense(2, XOR1, {0,0}, {2,-1,-1,2}, "hidden");
    Dense XOR3 = Dense(1, XOR2, {0}, {2,2}, "X1 xor X2");
    
    L1.printNetwork();
    
    Mesh mesh = Mesh(L1);
    std::cout << "\n";
    mesh.printMesh();
    std::cout << "\n";
    
    // Test 00
    mesh = Mesh(L1);
    std::vector<SpikeTrain> spikeTrain;
    spikeTrain = {
        SpikeTrain({0,0,0,0,0,0,0,0}),
        SpikeTrain({0,0,0,0,0,0,0,0})
    };
    
    std::vector<float> outputs = mesh.run(spikeTrain);
    std::cout << "(0,0): {";
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i];
        if (i < outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    
    // Test 10
    mesh = Mesh(L1);
    spikeTrain = {
        SpikeTrain({1,1,1,1,1,1,1,1}),
        SpikeTrain({0,0,0,0,0,0,0,0})
    };
    
    outputs = mesh.run(spikeTrain);
    std::cout << "(1,0): {";
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i];
        if (i < outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    
    // Test 01
    mesh = Mesh(L1);
    spikeTrain = {
        SpikeTrain({0,0,0,0,0,0,0,0}),
        SpikeTrain({1,1,1,1,1,1,1,1})
    };
    
    outputs = mesh.run(spikeTrain);
    std::cout << "(0,1): {";
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i];
        if (i < outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    
    // Test 11
    mesh = Mesh(L1);
    spikeTrain = {
        SpikeTrain({1,1,1,1,1,1,1,1}),
        SpikeTrain({1,1,1,1,1,1,1,1})
    };
    
    outputs = mesh.run(spikeTrain);
    std::cout << "(1,1): {";
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i];
        if (i < outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return mesh;
}


