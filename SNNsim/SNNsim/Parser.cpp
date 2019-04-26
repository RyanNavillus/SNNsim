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
    Dense L1 = Dense(2, "input");
    Dense L2 = Dense(2, L1, {1,2,3,4}, "hidden");
    Dense L3 = Dense(1, L2, {1,2}, "output");
    
    L1.printNetwork();
    
    Mesh mesh = Mesh(L1);
    std::cout << "\n";
    mesh.printMesh();
    
    std::vector<SpikeTrain> spikeTrain;
    spikeTrain = {
        SpikeTrain({0}),
        SpikeTrain({1})
    };
    
    std::vector<float> outputs = mesh.run(spikeTrain);
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i] << ", " << "\n";
    }
    
    return mesh;
}
