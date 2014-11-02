// Creates a min heap and removes the smallest elemnt 50 times
#include "helper.cpp"
#include <stdlib.h> 
#include <algorithm> 
#include <vector>
#include <iostream>
#include <time.h>

bool greaterThan(int a, int b){
    return a>b;
}

int main(){
    std::vector<int> numVec;
    std::vector<int> resultVec;
    genNumVec(numVec);

    clock_t progTime = clock();

    //Make a heap
    std::make_heap(numVec.begin(), numVec.end(), greaterThan);
    
    //Pop the smallest element 50 times
    for(int i = 0; i < 50; i++){
        resultVec.push_back(numVec[0]);
        std::pop_heap( numVec.begin(), numVec.end(), greaterThan );
        numVec.pop_back();
    }
    
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    output50Smallest(resultVec, "output/output_minHeap.txt");
}
