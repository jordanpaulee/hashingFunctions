#ifndef HashLin_hpp
#define HashLin_hpp
#include <vector>
using namespace std;

class HashLin {
    ////// @PrivateFunctions ///////
    
    ////Initialization///
    void init();

    ///// Linear Hashing Function ///// 
    int linHash();

    /// @brief Is Prime?
    /// @param n
    /// @return True or False for "is n prime?"
    bool isPrime(int n);

    /// @brief Next prime
    /// @param n 
    /// @return Closest larger prime
    int nextPrime(int n);

/*
    /// @brief Count size
    /// @param target 
    /// @return Char in string
    int countSize(string target);
*/
    public:
    /// @Constructor ////
    /// @param size /////
    HashLin(int size);

    ///// INSERT /////
    void insert(string input);
   
    //// PRINT ////
    void print();
    

    
};

#endif