//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_CLOCK_H
#define TLB_CLOCK_H

#include "Policy.h"

class CLOCK : public Policy {
public:
    CLOCK() = default;
    bool search(std::queue<int> *entries, int page, int entryCnt) override;
    int replace(std::queue<int> *entries, int page, int entryCnt) override;
};



#endif //TLB_CLOCK_H
