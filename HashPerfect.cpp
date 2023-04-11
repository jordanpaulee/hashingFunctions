#include "HashPerfect.hpp"
#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//TODO: Documentation

void HashPerfect::init() {
    for (int i = 0; i < 10; i++) {
        hashTableArray[i] = nullptr;
    }
}


int HashPerfect::perfectHash(string hashTarget) {
    unsigned long hash = 0;

    for (int i = 0; i < hashTarget.length(); i++) {
        unsigned char w = hashTarget[i];
        hash = (37 * hash + w) % 10;
    }
    return hash;
}


HashPerfect::HashPerfect() {
    this->init();
}


void HashPerfect::insertStringPerfect(string input) {
    int index = perfectHash(input);

    if(hashTableArray[index] == nullptr) {
        *hashTableArray[index] = HashLin(1); // TODO: Check if this pointer syntax actually works
    }
    
    else {
        hashTableArray[index]->insertString(input); // TODO: Check if this is correct data handling
    }
}

//TODO Implement
void HashPerfect::printPerfect() {
    //TODO
}
