// Utilizes quicksort partitioning,
// but avoids sorting unneeded partitions.
#include "helper.cpp"
#include <stdlib.h> 
#include <vector>
#include <iostream>
#include <time.h>

// Straight off wikipedia's pseudo code for quick sort
int partition(std::vector<int> &numVec, int left, int right){
     int pivotIndex = left; // Numbers are random, so this should be okay
                            // Alternatives include picking a random pivot
     int pivotValue = numVec[pivotIndex];
     std::swap(numVec[pivotIndex], numVec[right]);
     int storeIndex = left;
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

      // This one if statement makes all the difference
      if( p < 50 ){
          quick(A, p + 1, k);
      }
    }
}

int main(){
    std::vector<int> numVec;
    genNumVec(numVec);

    clock_t progTime = clock();

    quick(numVec, 0, numVec.size()-1);
    
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    output50Smallest(numVec, "output/output_quick.txt");

    return 0;
}









