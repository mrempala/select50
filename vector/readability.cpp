// A simple and readable approach that ustilizes std::sort
// Not meant to be too efficent, but it was stupid easy to implement
// It's one line of code, that has to count for readability
#include "helper.cpp"
#include <algorithm>
#include <stdlib.h> 
#include <vector>
#include <iostream>
#include <time.h>

int main(){
    std::vector<int> numVec;
    genNumVec(numVec);
    
    clock_t progTime = clock();
    
    
    // Yup, this is all there is to it
    std::sort(numVec.begin(), numVec.end());
    
    
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    output50Smallest(numVec, "output/output_readability.txt");
    
    return 0;
}
