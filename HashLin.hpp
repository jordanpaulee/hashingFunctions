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

    /// @brief Initializes empty vector to size specified by constructor
    void init();


    /// @brief Method to calculate hash value of input string
    /// @param hashTarget is the string for hashing
    /// @return hash value for indexing
    int linHash(string hashTarget);


    /// @brief Is Prime?
    /// @param n
    /// @return True or False for "is n prime?"
    bool isPrime(int n);

    

    public:
    
    /// @brief Constructor
    /// @param size parameter must be fed prime number for hashLin and n^2 for hashPerfect
    HashLin(int size);

    /// @brief Takes input string and handles hashing of input value into linear hash table (Does support dynamic resizing)
    /// @param input is the string to be input
    void insertString(string input);
   
    /// @brief Print method
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