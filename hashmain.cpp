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
    //cout << "2: Next Prime Call" << endl;
    
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

string testArray9[9] = {"the", "quick", "brown", "fox", "jumped", "over", "a", "lazy", "dog"};
string testArray10[10] = {"hello", "street", "leaves", "fall", "Thanksgiving", "candy", "pumpkin", "pie", "Halloween", "fun"};
vector<string> testVector10;

int stringSize = sizeof(testArray10)/sizeof(testArray10[0]);
int newSize = nextPrime(stringSize);

HashLin test(newSize);
HashPerfect testPerfect;

int main() {
    cout << stringSize << endl;
    for (int k = 0; k < 10; k++){
        testVector10.push_back(testArray10[k]);
    }

    //better implementation seems to be to read in the values into and array and then hash
    //Matches output better for 9 and 10
    for (int i = 0; i < stringSize; i++){
        test.insertString(testArray10[i]);
    }
    test.print();
    cout << endl << endl;

    for (int j = 0; j < stringSize; j++){
        //cout << "test1" << endl;
        testPerfect.insertStringPerfect(testVector10);
        //cout << "test2" << endl;
    }
    testPerfect.printPerfect();

}



