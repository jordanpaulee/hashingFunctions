#include "HashLin.hpp"
#include "HashPerfect.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


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
///////////// 
/*
string testArray9[9] = {"the", "quick", "brown", "fox", "jumped", "over", "a", "lazy", "dog"};
string testArray10[10] = {"hello", "street", "leaves", "fall", "Thanksgiving", "candy", "pumpkin", "pie", "Halloween", "fun"};
vector<string> testVector9;
vector<string> testVector10;


int stringSize = sizeof(testArray9)/sizeof(testArray9[0]);
int newSize = nextPrime(stringSize);

HashLin test(newSize);
HashPerfect testPerfect;
*/ 
///////////


int main() {

    /*
    cout << sizeof(testArray9) << endl;
    cout << sizeof(testArray9[0]) << endl;
    cout << stringSize << endl;
    */

   /*******************************
    // FILL VECTOR 
    for (int k = 0; k < stringSize; k++){
        testVector9.push_back(testArray9[k]);
    }
    
    //FILL HASH LIN ARRAY
    for (int i = 0; i < stringSize; i++){
        test.insertString(testArray9[i]);
    }
    //PRINT HASHLIN
    cout << "Hash Table with Linear Probing (size = " << newSize << "): " << endl << endl;
    test.print();
    cout << endl << endl;
    
    //FILL HASHPERFECT
    testPerfect.insertStringPerfect(testVector9);

    //PRINT HASHPERFECT
    cout << "Perfect Hash Table: " << endl << endl;
    testPerfect.printPerfect();
    *********************/
   
    vector<string> tempVector;
    string temp;

    do{
        cin >> temp;
        if(temp != "!"){
            tempVector.push_back(temp);
        }
    } while(temp != "!");
    
    int vectorSize = tempVector.size();

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


    HashPerfect hashPerfect;
    
    //FILL HASHPERFECT
    hashPerfect.insertStringPerfect(tempVector);

    //PRINT HASHPERFECT
    cout << "Perfect Hash Table: " << endl << endl;
    hashPerfect.printPerfect();
}



