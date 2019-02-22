//
//  Axon.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef Axon_hpp
#define Axon_hpp

#include <stdio.h>
#include <utility>
#include "Core.hpp"

class Core;

class Axon {
public:
    std::pair<Core *, int> source;
    std::pair<Core *, int> destination;
    int wgt;
    int dly;
    int tag;
    
};

#endif /* Axon_hpp */
