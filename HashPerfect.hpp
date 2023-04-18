#ifndef HashPerfect_hpp
#define HashPerfect_hpp
#include "HashLin.hpp"
#include <string>
#include <vector>
using namespace std;


class HashPerfect {
    

    private:
    /// @brief Hash Table Array for storing pointers to Linear Hash tables
    HashLin* hashTableArray[10];
    
    
    /// @brief init() used to initialize all values in hashTableArray to nullptrs
    void init();
    

    /// @brief Perfect Hash method for determining postion in hash table array (Does not control linHash objects)
    /// @param hashTarget 
    /// @return Hash value for given string
    int perfectHash(string hashTarget);

    /// @brief To insert hashLin into hashPerfect correctly
    void insertIn(int n, vector<string> strings);


    public:

    /// @brief Constructor that calls init()
    HashPerfect();


    /*  insert method
        - Takes entire vector of strings as a param
        - Determines number of strings that hash to each location
        - Dynamically allocates memory to each location
        - Inserts all of the strings into the secondary hash tables  */
    void insertStringPerfect(vector<string> strings);
    
    
    /// @brief Print method to output perfect hash
    void printPerfect(); 
};

#endif