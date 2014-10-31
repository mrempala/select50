// A program to generate 1 million random integers with values
// between 0 and 1 billion.
#include <stdlib.h> 
#include <fstream>

int main(){
    std::ofstream outputFile;
    srand(57624); // Just an arbitrary seed number
    
    outputFile.open("randInts.txt");
    for(int i = 0; i < 1000000; i++){
        outputFile << (rand() % 1000000000) << '\n';
    }
    
    outputFile.close();
    
    return 0;
}
