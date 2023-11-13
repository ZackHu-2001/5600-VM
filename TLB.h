//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_TLB_H
#define TLB_TLB_H

#include "Policy/Policy.h"
#include <queue>
#include <string>

class TLB {
public:
    TLB(int entryCnt, Policy* policy);
    int replaceOrAdd(int page);
    bool search(int page);
    std::string toString();
private:
    Policy* policy;
    std::queue<int> entries;
    int entryCnt;
};


#endif //TLB_TLB_H
