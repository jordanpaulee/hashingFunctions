#include "HashPerfect.hpp"
#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// INITIALIZATION
void HashPerfect::init() {
    for (int i = 0; i < 10; i++) {
        hashTableArray[i] = nullptr;
    }
}


// HASHING METHOD
int HashPerfect::perfectHash(string hashTarget) {
    unsigned long hash = 0;

    for (int i = 0; i < hashTarget.length(); i++) {
        unsigned char w = hashTarget[i];
        hash = (37 * hash + w) % 10;
    }
    return hash;
}


// INSERTION METHOD FOR LINEAR HASH SUB TABLES
    // Used to build the hash linear tables pointed to by the hash perfect table
void HashPerfect::insertIn(int n, vector<string> strings){
    int size = strings.size();
    int newSize = size*size;
    hashTableArray[n] = new HashLin(newSize);
    string temp;
    
    for(int i = 0; i < size; i++){
        temp = strings[i];
        hashTableArray[n]->insertString(temp);
    }
}


// CONSTRUCTOR
HashPerfect::HashPerfect() {
    init();
}


// INSERTION METHOD FOR HASH PERFECT
void HashPerfect::insertStringPerfect(vector<string> strings) {
    //Temp vectors used for ordering values hashed to 0-9 index in hashPerfect table
    vector<string> one;
    vector<string> two;
    vector<string> three;
    vector<string> four;
    vector<string> five;
    vector<string> six;
    vector<string> seven;
    vector<string> eight;
    vector<string> nine;
    vector<string> ten;

    //Filler methods
    for(int i = 0; i < strings.size(); i++) {
        int index = perfectHash(strings[i]);
        
        switch(index) {
            case 0:
                one.push_back(strings[i]);
                break;
            case 1:
                two.push_back(strings[i]);
                break;
            case 2:
                three.push_back(strings[i]);
                break;
            case 3:
                four.push_back(strings[i]);
                break;
            case 4:
                five.push_back(strings[i]);
                break;
            case 5:
                six.push_back(strings[i]);
                break;
            case 6:
                seven.push_back(strings[i]);
                break;
            case 7:
                eight.push_back(strings[i]);
                break;
            case 8:
                nine.push_back(strings[i]);
                break;
            case 9:
                ten.push_back(strings[i]);
                break;
        }
    }
    
    // Loops through each vector to hash and insert each item into the hashLinear table pointed to at each index
    for(int j = 0; j < 10; j++){
        switch(j) {
            case 0: {
                this->insertIn(j, one);
            }
            break;

            case 1: {
                this->insertIn(j, two);
            }
            break;
            
            case 2: {
                this->insertIn(j, three);
            }
            break;
            
            case 3: {
                this->insertIn(j, four);
            }
            break;
            
            case 4: {
                this->insertIn(j, five);
            }
            break;
            
            case 5: {
                this->insertIn(j, six);
            }
            break;
            
            case 6: {
                this->insertIn(j, seven);
            }
            break;
            
            case 7: {
                this->insertIn(j, eight);
            }
            break;
            
            case 8: {
                this->insertIn(j, nine);
            }
            break;
            
            case 9: {
                this->insertIn(j, ten);
            }
            break;
        }
    }
}


// PRINT METHOD
void HashPerfect::printPerfect() {
    for (int i = 0 ; i < 10; i++) {
        cout << i << ": -->" << endl;
        hashTableArray[i]->printIndent();
    }
}
