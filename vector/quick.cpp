// Efficent time complexity approach
// Utilizes quicksort partitioning,
// but avoids sorting unneeded partitions.
#include "helper.cpp"
#include <stdlib.h> 
#include <vector>

// Straight offa wikipedia pseudo code for quick sort
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

      // This one if statement makes the magic happen
      if( p < 50 ){
          quick(A, p + 1, k);
      }
    }
}

int main(){
    std::vector<int> numVec;
    genNumVec(numVec);

    quick(numVec, 0, numVec.size()-1);
    
    output50Smallest(numVec, "output/output_quick.txt");

    return 0;
}









