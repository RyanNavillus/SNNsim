//
//  main.cpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#include <iostream>
#include "Parser.hpp"
#include "NetworkFile.hpp"
#include "Mesh.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";

    FILE * file;
    file = fopen ("Samples/XORNetwork.txt" , "r");
    NetworkFile networkFile(file);
    Mesh mesh = Parser::parse(networkFile);
    return 0;
}

