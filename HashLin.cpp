#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


//// Initialization
void HashLin::init() {
     cout << "6" << endl;
    this->itemsInHashTable = 0;

    cout << "7" << endl;
    
    for(int i=0; i<hashTableSize; i++){ ////////ISSUE HERE
        cout <<"Test:" << i << endl;
        cout << hashTableSize << endl;
        
        hashTable.vector::insert(hashTable.begin()+i ,"");  // Segmentation fault fixed
        cout << "Segmentation fault fixed?" << endl;
    }

    cout << "8" << endl;
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
    
    cout << "1" << endl;
    int newSize = nextPrime(size);
    
    cout << "3" << endl;
    this -> hashTableSize = newSize;
    cout << "4" << endl;
    init(); // ISSUE HERE
    cout << "5" << endl;
};


///// Insertion Method
void HashLin::insertString(string input){ 
    
    // Check if resize is needed
    if (itemsInHashTable == hashTableSize){
        int tempSize = nextPrime(hashTableSize);
        
        cout << "Resize?" << endl;
        
        HashLin newTable(tempSize);

        for (int i = 0; i < hashTableSize; i++){ //POSSIBLE ISSUE #1
            if (this->hashTable[i]!= ""){
                newTable.insertString(input);
                }
            }
        
        //hashTable.resize(tempSize); //redundant?
        this->hashTable = newTable.hashTable;
        this->hashTableSize = newTable.hashTableSize;
        this->itemsInHashTable = newTable.itemsInHashTable;
        }
    
    // Otherwise, hash and insert with linear probing
    int hashValue = linHash(input);

    cout << "Hash Value: "<< hashValue << endl;
    cout << hashTable[hashValue] << endl;

    if (hashTable[hashValue] != ""){
        while(hashTable[hashValue] != ""){
            hashValue++;
            
            cout << hashValue << endl;
            hashValue = hashValue % hashTableSize;
           
            cout << hashValue << endl;
            cout << "Kicked to new hash." << " New hash: " << hashValue << endl;
        } //SHOULD PROVIDE VALID hashValue if this terminates
    }

    hashTable[hashValue] = input;
    itemsInHashTable++;
    cout << "New Hash?: " << hashValue << "  Value: " << hashTable[hashValue] << endl;

};


//// Print
void HashLin::print(){
};


//// Next Prime
int HashLin::nextPrime(int n) {
    cout << "2" << endl;
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
