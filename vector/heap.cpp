// Creates a min heap and removes the smallest elemnt 50 times
#include "helper.cpp"
#include <stdlib.h> 
#include <algorithm> 
#include <vector>

bool greaterThan(int a, int b){
    return a>b;
}

int main(){
    std::vector<int> numVec;
    std::vector<int> resultVec;
    genNumVec(numVec);

    //Make a heap
    std::make_heap(numVec.begin(), numVec.end(), greaterThan);
    
    //Pop the smallest element 50 times
    for(int i = 0; i < 50; i++){
        resultVec.push_back(numVec[0]);
        std::pop_heap( numVec.begin(), numVec.end(), greaterThan );
        numVec.pop_back();
    }
    
    output50Smallest(resultVec, "output/output_heap.txt");
}
