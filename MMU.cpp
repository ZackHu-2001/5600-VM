//
// Created by zackHu on 2023/11/12.
//

#include <iostream>
#include <iomanip>
#include "MMU.h"

MMU::MMU(TLB* TLB_L1, TLB* TLB_L2, int pageSize, std::vector<int> *workload, int PT_walk_time) :
TLB_L1(TLB_L1), TLB_L2(TLB_L2), pageSize(pageSize), workload(workload), PT_walk_time(PT_walk_time) {}

void MMU::start() {
    int l1AccessTime = 0;
    int l2AccessTime = 0;
    int pageLookUpTime = 0;

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
    printResult(l1AccessTime, l2AccessTime, pageLookUpTime);
}

void MMU::printResult(int l1AccessTime, int l2AccessTime, int pageLookUpTime) {

    int workloadCnt = workload->size();
    double L1TLBMissRate = static_cast<double>(l2AccessTime)/workloadCnt;
    double L2TLBMissRate = static_cast<double>(pageLookUpTime)/l2AccessTime;

    std::cout << std::endl << "Work load reached the end. Statistics of this run: " << std::endl;
    std::cout << "Total page accessed       : " << workloadCnt << std::endl;
    std::cout << "Page table look up count  : " << pageLookUpTime << std::endl;
    std::cout << "L1 access count           : " << l1AccessTime << std::endl;
    std::cout << "L2 access count           : " << l2AccessTime << std::endl << std::endl;

    std::cout << "Page table walk time      : " << PT_walk_time << " (ns)" << std::endl;
    std::cout << "L1 access time            : " << TLB_L1->getAccessTime() << " (ns)" << std::endl;
    std::cout << "L2 access time            : " << TLB_L2->getAccessTime() << " (ns)" << std::endl << std::endl;

    std::cout << "Total time consumed       : ";
    std::cout << l1AccessTime * TLB_L1->getAccessTime() +
                 l2AccessTime * TLB_L2->getAccessTime() + pageLookUpTime * PT_walk_time << " (ns)" << std::endl;

    std::cout << "L1 TLB miss rate          : ";
    std::cout << std::fixed << std::setprecision(2) << L1TLBMissRate * 100 << "%" << std::endl;

    std::cout << "L2 TLB miss rate          : ";
    std::cout << std::fixed << std::setprecision(2) << L2TLBMissRate * 100 << "%" << std::endl;
}

