//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_LRU_H
#define TLB_LRU_H

#include "Policy.h"

class LRU : public Policy {
public:
    LRU() = default;
    bool search(std::queue<int> *entries, int page, int entryCnt) override;
    int replace(std::queue<int> *entries, int page, int entryCnt) override;
};



#endif //TLB_LRU_H
