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
    cout << strings.size() << endl;

    for(int i = 0; i < strings.size(); i++) {
        int index = perfectHash(strings[i]);

        if(hashTableArray[index] == nullptr) { //Insert initial string
            cout << "here";

            hashTableArray[index] = new HashLin(1);
            hashTableArray[index]->insertString(strings[i]);
            cout << "TEST 1234" << endl;
        }

        else { //DOUBLE SIZE AND REHASH!!!
            cout << "HERE!!!!!!" << endl;
            
            int temp = hashTableArray[index]->getSize();
            
            int newSize = 0;
            if(temp == 1) {
                newSize = 4;
            }
            else{ 
                newSize = (temp*temp);
            }
            
            cout << newSize << endl;
            //TODO: RESIZE FUNCTION
            hashTableArray[index]->resizePerfect(newSize);

            hashTableArray[index]->insertString(strings[i]); // ISSUE
        }
        cout << "////////////////////" << i << "////////////////////////" << endl;
    }
}

//TODO Implement
void HashPerfect::printPerfect() {
    cout << "//////// PRINTING ////////////" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << i << ": -->" << endl;
        hashTableArray[i]->printIndent();
    }
}
