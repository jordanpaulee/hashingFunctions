#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


//// Initialization
void HashLin::init() {

    this->itemsInHashTable = 0;
    
    //initializes every value in the hash table to empty
    for(int i=0; i<hashTableSize; i++){
        hashTable.vector::insert(hashTable.begin()+i ,"");
    }
}


//// Hashing Method
int HashLin::linHash(string hashTarget) {
    unsigned long hash = 0;

    // hashing calculation
    for (int i = 0; i < hashTarget.length(); i++) {
        unsigned char w = hashTarget[i];
        hash = (37 * hash + w) % hashTableSize;
    }
    return hash;
};


//// Prime Checker
    //Checks if integer n is prime or not (Used for calculating size for constructor)
bool HashLin::isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
        return false;

    return true;
}


///////PUBLIC////////

//// Constructor
HashLin::HashLin(int size) {
    this -> hashTableSize = size;
    init();
};


///// Insertion Method
void HashLin::insertString(string input){ 
    //Dynamic Resizing. Shouldn't be used in current implementation, but code can be refactored to utilize this.
    if (itemsInHashTable == hashTableSize){
        
        int newSize = nextPrime(hashTableSize);
        HashLin newTable(newSize);

        for (int i = 0; i < hashTableSize; i++){ 

            if (this->hashTable[i]!= ""){
                newTable.insertString(this -> hashTable[i]);
                }
            }

        this->hashTable = newTable.hashTable;
        this->hashTableSize = newTable.hashTableSize;
        this->itemsInHashTable = newTable.itemsInHashTable;
        }

    int hashValue = linHash(input);

    //Linear Probing Condition (If value in index is not empty, move to next.)
    if (hashTable[hashValue] != ""){
        
        while(hashTable[hashValue] != ""){
            hashValue++;
            hashValue = hashValue % hashTableSize;
        }
    }
    
    //Sets index to input value and iterates items in table.
    hashTable[hashValue] = input;
    itemsInHashTable++;
};


//// Print
void HashLin::print(){
    for (int i = 0; i < hashTableSize; i++) {
        cout << i << ": " << hashTable[i] << endl;
    }
};


// Print Indent
    //Print indent prints the hash linear table for use in hash perfect print.
void HashLin::printIndent(){
    if (this != nullptr) {
        for (int i = 0; i < hashTableSize; i++) {
            cout << "       " << i << ": " << hashTable[i] << endl;
        }
    }
};


//// Next Prime
    //Used to find the next prime for size in constructor
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


//Getter for size
int HashLin::getSize()  {
    return hashTableSize;
}


//Getter for items in hash table
int HashLin::getItemsIn(){
    return itemsInHashTable;
}


//Likely unused. Dynamic resizing not utilized in this project
void HashLin::resizePerfect(int n){
    HashLin newTable(n);

    for (int i = 0; i < hashTableSize; i++){ 

        if (this->hashTable[i]!= ""){
            newTable.insertString(this -> hashTable[i]);
            }
        }

    this->hashTable = newTable.hashTable;
    this->hashTableSize = newTable.hashTableSize;
    this->itemsInHashTable = newTable.itemsInHashTable;
}
