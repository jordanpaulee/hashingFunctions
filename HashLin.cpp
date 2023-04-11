#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


//// Initialization
void HashLin::init() {
     cout << "4: init() called" << endl;
    this->itemsInHashTable = 0;

    //cout << "5: Items in hash table: " << this->itemsInHashTable << endl;
    
    for(int i=0; i<hashTableSize; i++){
        //cout << "6: Loop Count: " << i << endl;
        //cout << "7: Hash Table Size: " << hashTableSize << endl;
        
        hashTable.vector::insert(hashTable.begin()+i ,"");
        //cout << "Test: " << hashTable[i] << endl;
    }

    cout << "8: End init()" << endl;
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
    cout << endl << "/////////CONSTRUCTOR///////////" << endl;
    cout << "1: Constructor Call" << endl;
    
    int newSize = nextPrime(size);
    cout << "Next Prime: " << newSize << endl;
    
    this -> hashTableSize = newSize;
    cout << "3: CHECK. New Size: " << newSize << " | Hash Table Size: " << this -> hashTableSize << endl;
   
    init();
    cout << endl << endl;
};


///// Insertion Method
void HashLin::insertString(string input){ 
    cout << "/////////STRING INSERT/////////" << endl;
    cout << "Item to insert: " << input << endl;
    cout << "Items in hash table: " << itemsInHashTable << endl;
    cout << "Hash Table Size: " << hashTableSize << endl;

    // Check if resize is needed
    if (itemsInHashTable == hashTableSize){
        
        cout << endl << "//////RESIZE////////" << endl;
        //int tempSize = nextPrime(hashTableSize); //Not hitting 3. Redundant?
        
        HashLin newTable(hashTableSize);

        cout << "Hashing old values into new table" << endl;
        for (int i = 0; i < hashTableSize; i++){ //POSSIBLE ISSUE #1
            /*
            Check doesn't completely match out9.txt because "brown" is read from previous hash table before "the"
            - Ask prof.
            */

            if (this->hashTable[i]!= ""){
                newTable.insertString(this -> hashTable[i]);
                }
            }
            
        //ALTERNATE REHASHING


        cout << "Finished rehashing old values into new table, reassigning old table pointers to new" << endl;
        
        this->hashTable = newTable.hashTable;
        this->hashTableSize = newTable.hashTableSize;
        this->itemsInHashTable = newTable.itemsInHashTable;
        cout << endl << endl;
        //Continue to insert new value
        }
    
    // Otherwise, hash and insert with linear probing
    int hashValue = linHash(input);

    cout << "Hash Value: "<< hashValue << endl;
    cout << "Value: " << hashTable[hashValue] << endl;

    if (hashTable[hashValue] != ""){
        cout << "Linear probing condition called" << endl;
        
        while(hashTable[hashValue] != ""){
            hashValue++;
            
            hashValue = hashValue % hashTableSize;
           
            cout << "New hash value: " << hashValue << endl;
            
        } //SHOULD PROVIDE VALID hashValue if this terminates
    }

    hashTable[hashValue] = input;
    itemsInHashTable++;
    cout << "Hash Index: " << hashValue << "  Value: " << hashTable[hashValue] << endl;
    cout << endl << endl;
};


//// Print
void HashLin::print(){
    for (int i = 0; i < hashTableSize; i++) {
        cout << i << ": " << hashTable[i] << endl;
    }
};


//// Next Prime
int HashLin::nextPrime(int n) {
    cout << "2: Next Prime Call" << endl;
    
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
