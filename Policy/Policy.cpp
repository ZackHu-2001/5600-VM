//
// Created by zackHu on 2023/11/12.
//

#include "Policy.h"
#include <iostream>

bool Policy::search(std::queue<int> *entries, int page, int entryCnt) {
    bool found = false;

    std::queue<int> tempQueue = *entries;
    while (!tempQueue.empty()) {
        if (tempQueue.front() == page) {
            found = true;
            break;
        }
        tempQueue.pop(); // Remove the front element for the next iteration
    }
    return found;
}

int Policy::replace(std::queue<int> *entries, int page, int entryCnt) {
    std::cout << "WRONG" << std::endl;
    return 0;
}
