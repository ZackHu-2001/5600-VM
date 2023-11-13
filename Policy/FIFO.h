//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_FIFO_H
#define TLB_FIFO_H

#include "Policy.h"

class FIFO : public Policy {
public:
    FIFO() = default;
    bool search(std::queue<int> entries, int page, int entryCnt) override;
    int replace(std::queue<int> *entries, int page, int entryCnt) override;
};


#endif //TLB_FIFO_H
