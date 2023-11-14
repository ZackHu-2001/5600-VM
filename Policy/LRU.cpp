//
// Created by zackHu on 2023/11/12.
//

#include <iostream>
#include "LRU.h"

bool LRU::search(std::queue<int> *entries, int page, int entryCnt) {
    bool found = false;
    std::queue<int> tempQueue;

    int location = -1;
    int counter = 0;

    while (!entries->empty()) {
        if (entries->front() == page) {
            found = true;
            location = counter;
            entries->pop();
            continue;
        }
        tempQueue.push(entries->front()); // Remove the front element for the next iteration
        entries->pop();
        counter += 1;
    }

    for (int i=0; i<counter; i++) {
        entries->push(tempQueue.front());
        tempQueue.pop();
    }

    if (found) {
        entries->push(page);
    }
    return found;
//    return Policy::search(entries, page, 0);
}

int LRU::replace(std::queue<int> *entries, int page, int entryCnt) {
    if (page == -1) {
        return -1;
    }

    int result = -1;
    if (entries->size() < entryCnt) {
        entries->push(page);
    } else if (entries->size() == entryCnt) {
        result = entries->front();
        entries->pop();
        entries->push(page);
    }
    return result;
}
