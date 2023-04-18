#include "HashLin.hpp"
#include "HashPerfect.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// PRIME METHODS
    //Duplicate code from hashLin for easier use in main() wihtout object instantiation

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
        return false;

    return true;
}

int nextPrime(int n) {
    
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


int main() {

    vector<string> tempVector;
    string temp;

    // Load in strings from .txt document
    do{
        cin >> temp;
        if(temp != "!"){
            tempVector.push_back(temp);
        }
    } while(temp != "!");
    
    // Number of Strings in .txt
    int vectorSize = tempVector.size();

    // Calculate nextprime size
    int primedSize = nextPrime(vectorSize);
    HashLin hashLin(primedSize);


    //FILL HASH LIN ARRAY
    for (int i = 0; i < vectorSize; i++){
        hashLin.insertString(tempVector[i]);
    }

    //PRINT HASHLIN
    cout << "Hash Table with Linear Probing (size = " << primedSize << "): " << endl << endl;
    hashLin.print();
    cout << endl << endl;


    /// Hash Perfect ///
    HashPerfect hashPerfect;
    
    //FILL HASHPERFECT
    hashPerfect.insertStringPerfect(tempVector);

    //PRINT HASHPERFECT
    cout << "Perfect Hash Table: " << endl << endl;
    hashPerfect.printPerfect();
};