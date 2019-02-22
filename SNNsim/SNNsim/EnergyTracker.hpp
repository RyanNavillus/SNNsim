//
//  EnergyTracker.hpp
//  SNNsim
//
//  Created by Ryan Sullivan on 2/21/19.
//  Copyright © 2019 Ryan Sullivan. All rights reserved.
//

#ifndef EnergyTracker_hpp
#define EnergyTracker_hpp

#include <stdio.h>

class EnergyTracker {
public:
    static EnergyTracker& sharedInstance() {
        static EnergyTracker instance;
        return instance;
    }
private:
    // Privately declare constructor for sharedInstance method
    EnergyTracker(){};
public:
    // Publicly delete constructors to avoid duplication
    EnergyTracker(EnergyTracker const&) = delete;
    void operator = (EnergyTracker const&) = delete;
    
};

#endif /* EnergyTracker_hpp */
