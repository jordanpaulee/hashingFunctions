#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


//// Initialization
void HashLin::init() {
    //resize here?
    /* 
    if (itemsInHashTable == hashTableSize){
        hashTableSize = nextPrime(hashTableSize);
        hashTable.resize(hashTableSize);
    }*/
    for(int i=0; i<hashTableSize; i++){
        hashTable[i] = "";
    }
}


//// Hashing Method
int HashLin::linHash(string hashTarget) {
    unsigned long hash = 0;

    for (int i = 0; i < hashTarget.length(); i++) {
        unsigned char w = hashTarget[i];
        hash = (37 * hash + w) % hashTableSize;
    }
    return hash;
};


//// Prime Checker
bool HashLin::isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
        return false;

    return true;
};




///////PUBLIC////////

//// Constructor
HashLin::HashLin(int size) {
    
    int newSize = nextPrime(size);

    this -> hashTableSize = newSize;
    init();
};


///// Insertion Method
void HashLin::insert(string input){ ////////////////// CURRENT TODO
    
    //Check if resize is needed?
    if (itemsInHashTable == hashTableSize){
        int tempSize = nextPrime(hashTableSize);
        //hashTable.resize(hashTableSize);
        HashLin newTable(tempSize);
        for (int i = 0; i < hashTableSize; i++){
            if (this->hashTable[i]!= ""){
                //THIS IS WHERE LINEAR PROBING COMES INTO PLAY
                int newHash = newTable.linHash(input);
                newTable.hashTable[newHash] = input;
            }
        }
        /*int newHash = linHash(input);
        newTable.hashTable[newHash] = input;*/
    }
    
};


//// Print
void HashLin::print(){
};


//// Next Prime
int HashLin::nextPrime(int n) {
    if (n <= 1)
    return 2;

    bool prime = false;

    while(!prime)
    {
        n++;
        if(isPrime(n))
        {
            prime = true;
        }
    }
    return n;
}
