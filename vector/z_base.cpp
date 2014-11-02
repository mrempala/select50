// A simple and readable approach that ustilizes std::sort
// Not meant to be too efficent, but it was stupid easy to implement
// It's one line of code, that has to count for readability
#include "helper.cpp"
#include <algorithm>
#include <stdlib.h> 
#include <vector>

int main(){
    std::vector<int> numVec;
    genNumVec(numVec);
    
    output50Smallest(numVec, "output/junk.txt~");
    
    return 0;
}
