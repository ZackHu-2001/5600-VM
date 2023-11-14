//
// Created by zackHu on 2023/11/12.
//

#include <sstream>
#include <iostream>
#include "TLB.h"
#include "Policy/FIFO.h"

TLB::TLB(int entryCnt, Policy* policy) : entryCnt(entryCnt), policy(policy) {}


int TLB::replaceOrAdd(int page) {
    return policy->replace(&entries, page, entryCnt);
}

bool TLB::search(int page) {
    return policy->search(&entries, page, entryCnt);
}

std::string TLB::toString() {
    std::stringstream stringBuilder;
    stringBuilder << "[";
    std::queue<int> tmp(entries);
    for (int i=0; i < entryCnt; i++) {
        if (!tmp.empty()) {
            stringBuilder << tmp.front();
            tmp.pop();
        } else {
            stringBuilder << 0;
        }
        if (i != entryCnt - 1) {
            stringBuilder << ", ";
        }
    }
    stringBuilder << "]";

    return stringBuilder.str();
}
