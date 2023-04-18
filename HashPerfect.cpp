#include "HashPerfect.hpp"
#include "HashLin.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//TODO: Documentation

void HashPerfect::init() {
    for (int i = 0; i < 10; i++) {
        hashTableArray[i] = nullptr;
    }
}


int HashPerfect::perfectHash(string hashTarget) {
    unsigned long hash = 0;

    for (int i = 0; i < hashTarget.length(); i++) {
        unsigned char w = hashTarget[i];
        hash = (37 * hash + w) % 10;
    }
    return hash;
}

void HashPerfect::insertIn(int n, vector<string> strings){
    int size = strings.size();
    int newSize = size*size;
    hashTableArray[n] = new HashLin(newSize);
    string temp;
    
    for(int i = 0; i < size; i++){
        temp = strings[i];
        //cout <<"Size: " << size << " TEMP: " << temp << endl;
        hashTableArray[n]->insertString(temp);
    }
    /*
        if(hashTableArray[n] == nullptr) { //Insert initial string
            

            hashTableArray[n] = new HashLin(size);
            hashTableArray[n]->insertString(strings[i]);
            
        }

        else { //DOUBLE SIZE AND REHASH!!!
            
            int temp = (hashTableArray[n]->getItemsIn())+1;
            
            int newSize = temp*temp;
            
            
            hashTableArray[n]->resizePerfect(newSize);

            hashTableArray[n]->insertString(strings[i]);

        }*/
        //cout << "Done" << endl;
    //return tempHashLin;
}

HashPerfect::HashPerfect() {
    init();
}


void HashPerfect::insertStringPerfect(vector<string> strings) {
    //cout << strings.size() << endl;
    vector<string> one;
    vector<string> two;
    vector<string> three;
    vector<string> four;
    vector<string> five;
    vector<string> six;
    vector<string> seven;
    vector<string> eight;
    vector<string> nine;
    vector<string> ten;

    for(int i = 0; i < strings.size(); i++) {
        int index = perfectHash(strings[i]);
        
        /*
        if(hashTableArray[index] == nullptr) { //Insert initial string
            

            hashTableArray[index] = new HashLin(1);
            hashTableArray[index]->insertString(strings[i]);
            
        }

        else { //DOUBLE SIZE AND REHASH!!!
            
            
            int temp = (hashTableArray[index]->getItemsIn())+1;
            
            int newSize = temp*temp;
            
            
            hashTableArray[index]->resizePerfect(newSize);

            hashTableArray[index]->insertString(strings[i]);
        }*/
        //Below is my failed attempt at storing the values in each
        //index and THEN hashing them into the
       
        switch(index) {
            case 0:
                //cout << "Works 1" << endl;
                one.push_back(strings[i]);
                //cout <<"1 SIZE: "<< one.size() << endl;
                break;
            case 1:
                two.push_back(strings[i]);
                //cout <<"2 SIZE: "<< two.size() << endl;
                break;
            case 2:
                three.push_back(strings[i]);
                //cout <<"3 SIZE: "<< three.size() << endl;
                break;
            case 3:
                four.push_back(strings[i]);
                //cout <<"4 SIZE: "<< four.size() << endl;
                break;
            case 4:
                five.push_back(strings[i]);
                break;
            case 5:
                six.push_back(strings[i]);
                break;
            case 6:
                seven.push_back(strings[i]);
                break;
            case 7:
                eight.push_back(strings[i]);
                break;
            case 8:
                nine.push_back(strings[i]);
                break;
            case 9:
                ten.push_back(strings[i]);
                break;
        }
    }
    
    
    for(int j = 0; j < 10; j++){
        switch(j) {
            case 0: {
                this->insertIn(j, one);
            }
            break;

            case 1: {
                this->insertIn(j, two);
            }
            break;
            
            case 2: {
                this->insertIn(j, three);
            }
            break;
            
            case 3: {
                this->insertIn(j, four);
            }
            break;
            
            case 4: {
                this->insertIn(j, five);
            }
            break;
            
            case 5: {
                this->insertIn(j, six);
            }
            break;
            
            case 6: {
                this->insertIn(j, seven);
            }
            break;
            
            case 7: {
                this->insertIn(j, eight);
            }
            break;
            
            case 8: {
                this->insertIn(j, nine);
            }
            break;
            
            case 9: {
                this->insertIn(j, ten);
            }
            break;
    
        }
    }
}

//TODO Implement
void HashPerfect::printPerfect() {
    //cout << "//////// PRINTING ////////////" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << i << ": -->" << endl;
        hashTableArray[i]->printIndent();
    }
}
