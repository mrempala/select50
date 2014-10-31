// A simple and readable approach that ustilizes std::sort
// Not meant to be very efficent, but it was easy to implement
#include <algorithm>
#include <stdlib.h> 
#include <fstream>
#include <vector>

int main(){
    std::ofstream outputFile; 
    
    srand(57624); // Just an arbitrary seed number
    std::vector<int> numVec;
    for(int i = 0; i < 1000000; i++){
        numVec.push_back(rand() % 1000000000);
    }
    
    std::sort(numVec.begin(), numVec.end());
    
    outputFile.open("output_readability.txt");
    for(int i = 0; i<50; i++){
        outputFile<<numVec[i]<<'\n';
    }
    outputFile.close();
    
    return 0;
}
