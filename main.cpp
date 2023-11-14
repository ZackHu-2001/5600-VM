#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include "MMU.h"
#include "Policy/Policy.h"
#include "Policy/FIFO.h"
#include "Policy/LRU.h"
#include "Policy/RAND.h"
#include "Policy/CLOCK.h"

Policy* getPolicy(std::string REPLACE_POLICY) {
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
    return policy;
}

int main(int argc, char** argv) {
    // default parameters
    int L1_TLB_ENTRY_CNT = 8;
    int L2_TLB_ENTRY_CNT = 16;
    int PAGE_SIZE = 4096;
    std::string L1_REPLACE_POLICY = "LRU";
    std::string L2_REPLACE_POLICY = "LRU";

    Policy* l1policy = new LRU();
    Policy* l2policy = new LRU();
    std::vector<int> workload;

    // parse argument
    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                PAGE_SIZE = std::stoi(argv[i + 1]);
            } else {
                std::cerr << "Missing argument after -s" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-l1") == 0) {
            if (i + 1 < argc) {
                L1_TLB_ENTRY_CNT = std::stoi(argv[i + 1]);
            } else {
                std::cerr << "Missing argument after -l1" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-l2") == 0) {
            if (i + 1 < argc) {
                L2_TLB_ENTRY_CNT = std::stoi(argv[i + 1]);
            } else {
                std::cerr << "Missing argument after -l2" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-l1p") == 0) {
            if (i + 1 < argc) {
                L1_REPLACE_POLICY = argv[i + 1];
                l1policy = getPolicy(L1_REPLACE_POLICY);
            } else {
                std::cerr << "Missing argument after -l1p" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-l2p") == 0) {
            if (i + 1 < argc) {
                L2_REPLACE_POLICY = argv[i + 1];
                l2policy = getPolicy(L2_REPLACE_POLICY);
            } else {
                std::cerr << "Missing argument after -l2p" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-w") == 0) {
            if (i + 1 < argc) {
                std::string filePath = argv[i+1];

                std::ifstream inputFile(filePath);

                if (!inputFile.is_open()) {
                    std::cerr << "Error opening file: " << filePath << std::endl;
                    return 1; // Return an error code
                }

                std::string firstLine;
                std::getline(inputFile, firstLine);

                inputFile.close();

                std::istringstream ss(firstLine);
                int num;

                while (ss >> num) {
                    workload.push_back(num);

                    if (ss.peek() == ',')
                        ss.ignore();
                }
            } else {
                std::cerr << "Missing argument after -p" << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-h") == 0) {
            std::puts("Usage: ./TLB [OPTIONS]...\n");
            std::puts("Supported options:");
            std::puts("-s,    --size = PAGE_SIZE\n\tsize of the page");
            std::puts("-l1,   --l1tlb = L1_TLB_ENTRY_CNT\n\tl1 TLB entry count");
            std::puts("-l2,   --l2tlb = L2_TLB_ENTRY_CNT\n\tl2 TLB entry count");
            std::puts("-l1p,  --l1tlbPolicy = L1_TLB_POLICY\n\tl1 TLB policy (FIFO, LRU, RAND)");
            std::puts("-l2p,  --l2tlbPolicy = L2_TLB_POLICY\n\tl2 TLB policy (FIFO, LRU, RAND)");
            std::puts("-w,    --workload = WORKLOAD\n\tpath to workload file, workload is represented by list of page to be accessed");
            return 0;
        }
        i += 2;
    }

    TLB* TLB_L1 = new TLB(L1_TLB_ENTRY_CNT, l1policy);
    TLB* TLB_L2 = new TLB(L2_TLB_ENTRY_CNT, l2policy);

    std::cout << "Configurations: " << std::endl;
    std::cout << "L1_TLB_ENTRY_CNT :  " << L1_TLB_ENTRY_CNT << std::endl;
    std::cout << "L2_TLB_ENTRY_CNT :  " << L2_TLB_ENTRY_CNT << std::endl;
    std::cout << "PAGE_SIZE        :  " << PAGE_SIZE << std::endl;
    std::cout << "L1_REPLACE_POLICY   :  " << L1_REPLACE_POLICY << std::endl;
    std::cout << "L2_REPLACE_POLICY   :  " << L2_REPLACE_POLICY << std::endl;
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
