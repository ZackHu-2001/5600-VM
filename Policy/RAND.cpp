//
// Created by zackHu on 2023/11/12.
//

#include <random>
#include "RAND.h"

bool RAND::search(std::queue<int> *entries, int page, int entryCnt) {
    return Policy::search(entries, page, 0);
}

int RAND::replace(std::queue<int> *entries, int page, int entryCnt) {
    if (page == -1) {
        return -1;
    }

    int result = -1;
    if (entries->size() < entryCnt) {
        entries->push(page);
    } else {
        std::random_device rd;     // Initialize a random device
        std::mt19937 gen(rd());    // Seed the random number generator

        std::uniform_int_distribution<int> distribution(0, entryCnt);  // Define the range
        int randomIdx = distribution(gen);
        std::vector<int> tmp;

        for (int i=0; i<entryCnt; i++) {
            if (i == randomIdx) {
                result = entries->front();
            } else {
                tmp.push_back(entries->front());
            }
            entries->pop();
        }

        for (int i : tmp) {
            entries->push(i);
        }
        entries->push(page);
    }


    return result;
}
