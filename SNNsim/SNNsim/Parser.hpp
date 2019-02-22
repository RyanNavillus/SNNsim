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
    Mesh parse(NetworkFile file);
};

#endif /* Parser_hpp */
