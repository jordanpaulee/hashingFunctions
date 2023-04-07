#include "HashLin.hpp"
#include "HashPerfect.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/* FOR TESTING HASH ALGO
int sizeOf = 11;

int linHash(string hashTarget) {
        
        unsigned long hash = 0;

        for (int i = 0; i < hashTarget.length(); i++) {
            unsigned char w = hashTarget[i];
            hash = (37 * hash + w) % sizeOf;
        }
        return hash;
    }
*/

HashLin foo(1);

int main() {
    /* FOR TESTING HASH ALGO
    int test = linHash("fox");
    cout << test << endl;
    */

   /* Pseduocode:
        - Read in file
        - As each item is inserted, do we need to grow?
        - if we need to grow:
            - resize hashtable and reinsert values with new size param
        - else:
            - hash and insert into hash table
   */
    int i = foo.nextPrime(5); //Testing prime refactoring
    cout << i << endl;
}



