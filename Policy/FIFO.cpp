//
// Created by zackHu on 2023/11/12.
//

#include "FIFO.h"
#include <iostream>

bool FIFO::search(std::queue<int> *entries, int page, int entryCnt) {
    return Policy::search(entries, page, 0);
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
