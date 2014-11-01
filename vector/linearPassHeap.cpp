// Originally wrote for a file stream, but converting to use a vector was easy enough
// An approach that stores a max heap of the 50 smallest values
// and replaces the max if there is a new value smaller than the max.
// Performs a std::sort on the vector of the 50 smallest elements afterwards.

#include "helper.cpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 

int main(int argc,char *argv[]){
    std::vector<int> heapVec;
    std::vector<int> numVec;
    int inputInt;
    
    genNumVec(numVec);
    
    //Copy first 50 element to the heap and create the heap
    for(int i = 0; i < 50; i++){
        heapVec.push_back(numVec[i]);
    }
    std::make_heap(heapVec.begin(), heapVec.end());

    for(int i = 50; i<numVec.size(); i++){
        //Otherwise if smaller than heap max, replace
        if( numVec[i] < heapVec[0] ){
            std::pop_heap (heapVec.begin(), heapVec.end());
            heapVec.pop_back();
            heapVec.push_back(numVec[i]);
            std::push_heap (heapVec.begin(), heapVec.end());
        }
    }
    
    //Sort the vector of 50 smallest ints
    std::sort( heapVec.begin(), heapVec.end() );
    
    
    
    output50Smallest(heapVec, "output/output_linearPassHeap.txt");
    
    return 0;
}
