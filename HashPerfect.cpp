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
    init();
}


void HashPerfect::insertStringPerfect(vector<string> strings) {
    //ALL WRONG
    /*int index = perfectHash(input);
    cout << "Perfect Hash: " << index << endl;

    if(hashTableArray[index] == nullptr) {
        cout << "here";
        hashTableArray[index] = new HashLin(1); //SEGMENTATION FAULT HERE
        hashTableArray[index]->insertString(input);
        cout << "TEST 1234" << endl;

    }
    
    else {
        hashTableArray[index]->insertString(input); // TODO: Check if this is correct data handling
    }*/

    
}

//TODO Implement
void HashPerfect::printPerfect() {
    cout << "//////// PRINTING ////////////" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << i << ": -->" << endl;
        hashTableArray[i]->printIndent();
        /*ISSUES:
            - hash lin needs to resize after insert? 
            - Seems that once two items are in the table, it needs to be resized to 4?
            - Print statement makes no sense on answer key.
        */
    }
}
