#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class HashLin{
    /// Private variables ///
    vector<string> hashTable;
    int size;


    /// @brief Initialization
    void HashLin::init() {
        for(int i=0; i<size; i++){
            hashTable[i] = "";
        }
    };


    /// @brief Hashing Method
    /// @param String to be hashed
    /// @return Hash value
    int HashLin::linHash(string hashTarget) {
        
        unsigned long hash = 0;

        for (int i = 0; i < hashTarget.length(); i++) {
            unsigned char w = hashTarget[i];
            hash = (37 * hash + w) % size;
        }
        return hash;
    }


    /// @brief Is n prime?
    /// @param n 
    /// @return Boolean
    bool HashLin::isPrime(int n){
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
            return false;

        return true;
    };


    /// @brief Find next largest prime for n
    /// @param n 
    /// @return Closest prime number greater than n
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

/*
    /// @brief Count size
    /// @param target 
    /// @return  Char in string
    int HashLin::countSize(string target) {
        
        unsigned int count;
        for (int i=0; i < target.length(); i++){
            count++;
        }
        return count;
    };
*/

    public:
    /// @brief Constructor
    /// @param size 
    HashLin::HashLin(int size) {
        
        init();
    };

    /// @brief Insert Function
    /// @param input 
    void HashLin::insert(string input){
        /* For items in input 
        */
    };

    /// @brief Print function
    void HashLin::print(){

    };
};