//
// Created by zackHu on 2023/11/12.
//

#include "RAND.h"

bool RAND::search(std::queue<int> entries, int page, int entryCnt) {
    return Policy::search(entries, page, 0);
}

int RAND::replace(std::queue<int> *entries, int page, int entryCnt) {
    return Policy::replace(entries, page, 0);
}
