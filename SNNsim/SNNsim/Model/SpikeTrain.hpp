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

// A spike train of 1 second using rate encoding
// Maximum frequency: 200Hz

typedef struct SpikeTrain {
    bool& operator[](int i) { return spikes[i]; }
    bool spikes[3];
} SpikeTrain;

#endif /* SpikeTrain_hpp */
