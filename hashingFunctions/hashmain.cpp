#include "HashLin.hpp"
#include "HashPerfect.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int size = 11;

int linHash(string hashTarget) {
        
        unsigned long hash = 0;

        for (int i = 0; i < hashTarget.length(); i++) {
            unsigned char w = hashTarget[i];
            hash = (37 * hash + w) % size;
        }
        return hash;
    }

int main() {
    int test = linHash("fox");
    cout << test << endl;
}

