#ifndef HashPerfect_hpp
#define HashPerfect_hpp
#include "HashLin.hpp"
#include <string>
#include <vector>
using namespace std;


class HashPerfect {
    

    private:
    /*
    array hash table
        - 10 pointers pointing to hashLin objects

    */
    HashLin * hashTableArray[10];
    /*

    init method
        - Initializes all members in the table to null
     */
    void init();
    /*   
    hash function
    */
    int perfectHash(string hashTarget);



    public:

    /* 
    constuctor that calls init
    */
    HashPerfect();
    /*

    insert method
        - Takes entire vector of strings as a param
        - Determines number of strings that hash to each location
        - Dynamically allocates memory to each location
        - Inserts all of the strings into the secondary hash tables

    */
    void insertStringPerfect(string input);
    /*
    print method
        - Print out elements in the table and the secondary tables
    */
    void printPerfect(); 
};

#endif