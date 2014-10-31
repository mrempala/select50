// An approach that stores a max heap of the 50 smallest values
// and replaces the max if there is a new value smaller than the max.
// Performs a std::sort on the vector of the 50 smallest elements afterwards.
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 

int main(int argc,char *argv[]){
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open("randInts.txt");
    //Using a vector wastes a bit of memory compared to a fixed sized array
    //But it was easier to do it this way when using the std heap funcions
    std::vector<int> heapVec;
    int inputInt;
    
    //Read input file and create a heap of
    //the smallest 50 elements while doing so
    while(inputFile.good()){
        inputFile>>inputInt;
        
        //Add to heap if size is less than 50 regardless of value
        if( heapVec.size() < 50 ){
            heapVec.push_back(inputInt);
            std::push_heap (heapVec.begin(), heapVec.end());
        }
        
        //Otherwise if smaller than heap max, replace
        else if( inputInt < heapVec[0] ){
            std::pop_heap (heapVec.begin(), heapVec.end());
            heapVec.pop_back();
            heapVec.push_back(inputInt);
            std::push_heap (heapVec.begin(), heapVec.end());
        }
    }
    inputFile.close();
    
    //Sort the vector of 50 smallest ints
    std::sort( heapVec.begin(), heapVec.end() );
    
    //Output Smallest 50
    outputFile.open("output/output_heap.txt");
    for(int i = 0; i<50; i++){
        outputFile<<heapVec[i]<<'\n';
    }
    outputFile.close();
    
    return 0;
}
