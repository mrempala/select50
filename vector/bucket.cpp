// Bucket Approach
// Creates 1,000 different vectors that act like buckets
// that can store 1 million different values each.
// Originally did 10,000 buckets for 100,000 values, but 
// timing the program shows that 1,000 buckets is faster,
// most likely due to time required for allocating memory.
// Might be faster to avoid using vectors and instead use static sized arrays.
#include "helper.cpp"
#include <stdlib.h>
#include <iostream> 
#include <algorithm>
#include <vector>

int main(){
    std::vector<int> numVec;
    std::vector<int> resultVec;
    std::vector<int> tempVec;
    std::vector<int> bucketArr[1000];
    
    genNumVec(numVec);
    
    for(int i = 0; i<numVec.size(); i++){
        int value = numVec[i];
        //Won't work with 1 billion inclusive
        int bucket = value / 1000000;
        if(bucket > 9999)
            std::cout<<"something went wrong, yo"<<std::endl;
        else
            bucketArr[bucket].push_back(value);
    
    }
    
    int bucket = 0;
    while( resultVec.size() < 50 ){
        if( !bucketArr[bucket].empty() ){
            std::sort(bucketArr[bucket].begin(), bucketArr[bucket].end());
            for(int i = 0; i < bucketArr[bucket].size(); i++)
                resultVec.push_back(bucketArr[bucket][i]);
        }
        bucket++;
    }
    
    output50Smallest(resultVec, "output/output_bucket.txt");

    return 0;
}

