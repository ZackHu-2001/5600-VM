//
// Created by zackHu on 2023/11/12.
//

#include "CLOCK.h"

bool CLOCK::search(std::queue<int> *entries, int page, int entryCnt) {
    // initialize the array
    if (this->memory == nullptr) {
        this->memory = new int[entryCnt];
        for (int i=0; i<entryCnt; i++) {
            this->memory[i] = 0;
        }
    }

    bool found = false;

    std::queue<int> tempQueue = *entries;
    int counter = 0;
    while (!tempQueue.empty()) {
        if (tempQueue.front() == page) {
            found = true;
            this->memory[counter] = 1;
            break;
        }
        tempQueue.pop(); // Remove the front element for the next iteration
        counter += 1;
    }


    printf("memory: [");
    for (int i=0; i<entryCnt; i++) {
        if (i == entryCnt - 1) {
            printf("%d]\n", this->memory[i]);
        } else {
            printf("%d, ", this->memory[i]);
        }
    }
    return found;
}

int CLOCK::replace(std::queue<int> *entries, int page, int entryCnt) {
    if (page == -1) {
        return -1;
    }

    int result = -1;
    if (entries->size() < entryCnt) {
        entries->push(page);
    } else if (entries->size() == entryCnt) {
        while (this->memory[0] > 0) {
            for (int j=0; j<entryCnt-1; j++) {
                this->memory[j] = this->memory[j + 1];
            }
            this->memory[entryCnt - 1] = 0;
            entries->push(entries->front());
            entries->pop();
        }
        for (int j=0; j<entryCnt-1; j++) {
            this->memory[j] = this->memory[j + 1];
        }
        this->memory[entryCnt - 1] = 0;

        result = entries->front();
        entries->pop();
        entries->push(page);
    }

    printf("memory: [");
    for (int i=0; i<entryCnt; i++) {
        if (i == entryCnt - 1) {
            printf("%d]\n", this->memory[i]);
        } else {
            printf("%d, ", this->memory[i]);
        }
    }
    printf("\nleave: %d\n", result);
    return result;
}
