// Builds a min heap as elements are read in
// Use O(n) memory to store all elements
// Not as efficent as smallHeap.cpp
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 

bool greaterThan(int a, int b){
    return a>b;
}

int main(int argc,char *argv[]){
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::vector<int> heapVec;
    int inputInt;
    
    // Build a min heap of all elements
    inputFile.open("randInts.txt");
    while(inputFile.good()){
        inputFile>>inputInt;
        heapVec.push_back(inputInt);
        std::push_heap (heapVec.begin(), heapVec.end(), greaterThan);
    }
    inputFile.close();
    
    //Output Smallest 50 and remove from heap
    outputFile.open("output/output_minHeap.txt");
    for(int i = 0; i<50; i++){
        outputFile<<heapVec.front()<<'\n';
        std::pop_heap(heapVec.begin(), heapVec.end(), greaterThan);
        heapVec.pop_back();
    }
    outputFile.close();
    
    return 0;
}
