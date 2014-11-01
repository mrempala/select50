// helper functions
#include <stdlib.h> 
#include <fstream>
#include <vector>

// Generate a random number vector from scratch
void genNumVec(std::vector<int> &numVec){
    srand(57624); // Just an arbitrary seed number
    for(int i = 0; i < 1000000; i++){
        numVec.push_back(rand() % 1000000000);
    }
}

// Read from file to numbervector
// Slower than generating a random vector from scratch
// Lol, file I/O is sloooooow
void readIntsFromFile(std::vector<int> &numVec, const char *fileName){
    int inputInt;
    std::ifstream inputFile;
    inputFile.open(fileName);
    while(inputFile.good()){
        inputFile>>inputInt;
        numVec.push_back(inputInt);
    }
    inputFile.close();
}

// Outputs 50 smallest when using a sorted vector
void output50Smallest(std::vector<int> &numVec, const char *fileName){
    std::ofstream outputFile; 
    outputFile.open(fileName);
    for(int i = 0; i<50; i++){
        outputFile<<numVec[i]<<'\n';
    }
    outputFile.close();
}
