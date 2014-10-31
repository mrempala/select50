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

// Outputs 50 smallest when using a sorted vector
void output50Smallest(std::vector<int> &numVec, const char *fileName){
    std::ofstream outputFile; 
    outputFile.open(fileName);
    for(int i = 0; i<50; i++){
        outputFile<<numVec[i]<<'\n';
    }
    outputFile.close();
}
