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
    TLB(int entryCnt, Policy* policy, int access_time);
    int replaceOrAdd(int page);
    bool search(int page);
    int getAccessTime();
    std::string toString();
private:
    Policy* policy;
    int entryCnt;
    int access_time;
    std::queue<int> entries;
};


#endif //TLB_TLB_H
