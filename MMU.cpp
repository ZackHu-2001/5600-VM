//
// Created by zackHu on 2023/11/12.
//

#include <iostream>
#include <iomanip>
#include "MMU.h"

MMU::MMU(TLB* TLB_L1, TLB* TLB_L2, int pageSize, std::vector<int> *workload) :
TLB_L1(TLB_L1), TLB_L2(TLB_L2), pageSize(pageSize),workload(workload) {}

void MMU::start() {
    int l1AccessTime = 0;
    int l2AccessTime = 0;
    int pageLookUpTime = 0;
    int workloadCnt = workload->size();

    while (!workload->empty()) {

        int currentPage = workload->at(0);
        workload->erase(workload->begin());

        std::cout << std::endl << std::endl << "Current access page: " << currentPage << std::endl;
        std::cout << "L1 TLB: " << TLB_L1->toString() << std::endl;
        std::cout << "L2 TLB: " << TLB_L2->toString() << std::endl << std::endl;

        // l1 look up
        l1AccessTime += 1;
        if (TLB_L1->search(currentPage)) {
            std::cout << "Page found in L1 TLB." << std::endl;
            continue;

        } else {
            l2AccessTime += 1;
            if (TLB_L2->search(currentPage)) {
                std::cout << "Page found in L2 TLB." << std::endl;
                continue;

            } else {
                // simulate RAM look up
                pageLookUpTime += 1;

                std::cout << "TLB miss! Look up page table in RAM and update TLB." << std::endl;
                TLB_L2->replaceOrAdd(TLB_L1->replaceOrAdd(currentPage));
                std::cout << "L1 TLB: " << TLB_L1->toString() << std::endl;
                std::cout << "L2 TLB: " << TLB_L2->toString() << std::endl;
            }
        }

    }
    double L1TLBMissRate = static_cast<double>(l2AccessTime)/workloadCnt;
    double L2TLBMissRate = static_cast<double>(pageLookUpTime)/l2AccessTime;

    std::cout << std::endl << "Work load reached the end. Statistics of this run: " << std::endl;
    std::cout << "Total page accessed       : " << workloadCnt << std::endl;
    std::cout << "Page table look up time   : " << pageLookUpTime << std::endl;

    std::cout << "L1 access time            : " << l1AccessTime << std::endl;
    std::cout << "L2 access time            : " << l2AccessTime << std::endl;
    std::cout << "L1 TLB miss rate          : ";
    std::cout << std::fixed << std::setprecision(2) << L1TLBMissRate * 100 << "%" << std::endl;

    std::cout << "L2 TLB miss rate          : ";
    std::cout << std::fixed << std::setprecision(2) << L2TLBMissRate * 100 << "%" << std::endl;



}

