//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_POLICY_H
#define TLB_POLICY_H

#include <queue>

class Policy {
public:
    virtual bool search(std::queue<int> entries, int page, int entryCnt);
    virtual int replace(std::queue<int> *entries, int page, int entryCnt);
};


#endif //TLB_POLICY_H
