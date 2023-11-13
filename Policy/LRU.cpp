//
// Created by zackHu on 2023/11/12.
//

#include "LRU.h"

bool LRU::search(std::queue<int> entries, int page, int entryCnt) {
    return Policy::search(entries, page, 0);
}

int LRU::replace(std::queue<int> *entries, int page, int entryCnt) {
    return Policy::replace(entries, page, 0);
}
