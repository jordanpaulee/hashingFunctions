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
    
    /// @brief Next prime
    /// @param n 
    /// @return Closest larger prime
    int nextPrime(int n);

    
};

#endif