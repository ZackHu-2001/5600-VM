//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_RAND_H
#define TLB_RAND_H

#include "Policy.h"

class RAND : public Policy {
public:
    RAND() = default;
    bool search(std::queue<int> entries, int page, int entryCnt) override;
    int replace(std::queue<int> *entries, int page, int entryCnt) override;
};



#endif //TLB_RAND_H
