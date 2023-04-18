#ifndef HashLin_hpp
#define HashLin_hpp
#include <string>
#include <vector>

using namespace std;

class HashLin {
    private:
    ///// Private Variables ////////
    
    int hashTableSize;
    int itemsInHashTable;
    vector<string> hashTable;


    ////// Private Functions ///////
    
    ////Initialization///
    /// Initializes empty vector to size specified by constructor ///
    void init();

    ///// Linear Hashing Function ///// 
    int linHash(string hashTarget);

    /// @brief Is Prime?
    /// @param n
    /// @return True or False for "is n prime?"
    bool isPrime(int n);

    



    public:
    ///// PUBLIC FUNCTIONS //////
    /// @Constructor ////
    /// @param size /////
    HashLin(int size);

    ///// INSERT /////
    //Takes input string and handles resizing and hashing of input value into linear hash table
    void insertString(string input);
   
    //// PRINT ////
    void print();

    /// @brief prints with indent for HashPerfect
    void printIndent();
    
    /// @brief Next prime
    /// @param n 
    /// @return Closest larger prime
    int nextPrime(int n);

    /// @brief Getter for array size
    /// @return hashTableSize
    int getSize();

    /// @brief Returns number of items for quadratic growth in perfect hashing
    /// @return # of items
    int getItemsIn();

    /// @brief for resizing hashlin objects for perfect hashing
    /// @param n for resize int
    void resizePerfect(int n);

    
};

#endif