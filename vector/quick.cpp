// Efficent time complexity approach
// Utilizes quicksort partitioning,
// but avoids sorting unneeded partitions.
#include <algorithm>
#include <stdlib.h> 
#include <fstream>
#include <iostream>
#include <vector>

// Straight offa wikipedia
int partition(std::vector<int> &numVec, int left, int right){
     //pivotIndex := choosePivot(array, left, right)
     int pivotIndex = left; // Numbers are random, so this should be okay
     int pivotValue = numVec[pivotIndex];
     std::swap(numVec[pivotIndex], numVec[right]);
     int storeIndex = left;
     //for i from left to right - 1
     for( int i = left; i < right; i++){
         if( numVec[i] < pivotValue ){
             std::swap(numVec[i], numVec[storeIndex]);
             storeIndex++;
         }
     }
     std::swap(numVec[storeIndex], numVec[right]);  // Move pivot to its final place
     return storeIndex;
}

void quick(std::vector<int> &A, int i, int k){
  if(i < k){
    int p = partition(A, i, k);
    quick(A, i, p - 1);
    if( p < 50 )
        quick(A, p + 1, k);
  }
}

int main(){
    std::ofstream outputFile; 
    
    srand(57624); // Just an arbitrary seed number
    std::vector<int> numVec;
    for(int i = 0; i < 1000000; i++){
        numVec.push_back(rand() % 1000000000);
    }

    quick(numVec, 0, numVec.size()-1);
    
    outputFile.open("output_quick.txt");
    for(int i = 0; i<50; i++){
        outputFile<<numVec[i]<<'\n';
    }
    outputFile.close();

    return 0;
}









