#include <iostream>
#include "MMU.h"
#include "Policy/Policy.h"
#include "Policy/FIFO.h"
#include "Policy/LRU.h"
#include "Policy/RAND.h"
#include "Policy/CLOCK.h"

int main() {
    int L1_TLB_ENTRY_CNT = 8;
    int L2_TLB_ENTRY_CNT = 16;
    int PAGE_SIZE = 4096;
    std::string REPLACE_POLICY = "RAND";

    std::vector<int> workload;
    workload.push_back(1);
    workload.push_back(2);
    workload.push_back(3);
    workload.push_back(4);
    workload.push_back(5);
    workload.push_back(6);
    workload.push_back(7);
    workload.push_back(8);

//    workload.push_back(2);
//    workload.push_back(3);
//    workload.push_back(4);
//    workload.push_back(5);
//    workload.push_back(6);
//    workload.push_back(7);
//    workload.push_back(8);

    workload.push_back(9);
    workload.push_back(10);
    workload.push_back(11);

    Policy* policy;
    if (REPLACE_POLICY == "FIFO") {
        policy = new FIFO();
    } else if (REPLACE_POLICY == "LRU") {
        std::cout << "here" << std::endl;
        policy = new LRU();
    } else if (REPLACE_POLICY.compare("RAND") == 0) {
        policy = new RAND();
    } else if (REPLACE_POLICY.compare("CLOCK") == 0) {
        policy = new CLOCK();
    }

    TLB* TLB_L1 = new TLB(L1_TLB_ENTRY_CNT, policy);
    TLB* TLB_L2 = new TLB(L2_TLB_ENTRY_CNT, policy);

    std::cout << "Configurations: " << std::endl;
    std::cout << "L1_TLB_ENTRY_CNT :  " << L1_TLB_ENTRY_CNT << std::endl;
    std::cout << "L2_TLB_ENTRY_CNT :  " << L2_TLB_ENTRY_CNT << std::endl;
    std::cout << "PAGE_SIZE        :  " << PAGE_SIZE << std::endl;
    std::cout << "REPLACE_POLICY   :  " << REPLACE_POLICY << std::endl;
    std::cout << "workload         :  [";
    for (int i = 0; i < workload.size(); ++i) {
        std::cout << workload[i];
        if (i != workload.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;


    MMU* mmu = new MMU(TLB_L1, TLB_L2, PAGE_SIZE, &workload);
    mmu->start();

    return 0;
}
