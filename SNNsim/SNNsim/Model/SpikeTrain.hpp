//
//  SpikeTrain.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/22/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef SpikeTrain_hpp
#define SpikeTrain_hpp

#include <stdio.h>
#include <vector>

// A spike train of 1 second using rate encoding
// Maximum frequency: 200Hz

class SpikeTrain {
public:
    SpikeTrain(std::vector<bool> spikes);
    bool operator[](int i) { return spikes[i]; }
    std::vector<bool> spikes;
};

#endif /* SpikeTrain_hpp */
