//
// Created by zackHu on 2023/11/12.
//

#include "FIFO.h"
#include <iostream>

bool FIFO::search(std::queue<int> entries, int page, int entryCnt) {
    bool found = false;
    std::queue<int> tempQueue(entries);
    while (!tempQueue.empty()) {
        if (tempQueue.front() == page) {
            found = true;
            break;
        }
        tempQueue.pop(); // Remove the front element for the next iteration
    }
    return found;
}

int FIFO::replace(std::queue<int> *entries, int page, int entryCnt) {
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
