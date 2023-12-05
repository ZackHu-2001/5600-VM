//
// Created by zackHu on 2023/11/12.
//

#ifndef TLB_MMU_H
#define TLB_MMU_H


#include "Policy/Policy.h"
#include "TLB.h"

class MMU {
public:
    MMU(TLB* TLB_L1, TLB* TLB_L2, int pageSize, std::vector<int> *workload, int PT_walk_time);
    void start();
    void printResult(int l1AccessTime, int l2AccessTime, int pageLookUpTime);
private:
    TLB* TLB_L1;
    TLB* TLB_L2;
    int PT_walk_time;
    int pageSize;
    std::vector<int>* workload;
};


#endif //TLB_MMU_H
