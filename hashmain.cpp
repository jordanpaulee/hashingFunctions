#include "HashLin.hpp"
#include "HashPerfect.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


HashLin foo(0);
HashLin test(9);


string testArray9[9] = {"the", "quick", "brown", "fox", "jumped", "over", "a", "lazy", "dog"};
string testArray10[10] = {"hello", "street", "leaves", "fall", "Thanksgiving", "candy", "pumpkin", "pie", "Halloween", "fun"};

int main() {
  /*
    foo.insertString("the");
    foo.insertString("quick");
    foo.insertString("brown");
    foo.insertString("fox");
    foo.insertString("jumped");
    foo.insertString("over");
    foo.insertString("a");
    foo.insertString("lazy");
    foo.insertString("dog");
    foo.print();
    */
/*
hello
street
leaves
fall
Thanksgiving
candy
pumpkin
pie
Halloween
fun
*/
/*
    foo.insertString("hello");
    foo.insertString("street");
    foo.insertString("leaves");
    foo.insertString("fall");
    foo.insertString("Thanksgiving");
    foo.insertString("candy");
    foo.insertString("pumpkin");
    foo.insertString("pie");
    foo.insertString("Halloween");
    foo.insertString("fun");
    foo.print();*/


    //better implementation seems to be to read in the values into and array and then hash
    //Matches output better for 9 and 10
    for (int i = 0; i < 11; i++){
        test.insertString(testArray10[i]);
    }
    test.print();
}



