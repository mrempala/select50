// Let's optimize average performance at the
// cost of crappier worst case performance!
// Numbers given follow a random normal distribution
// Let's exploit that!
// For a set of 1 million values, we want the smallest 50
// And they have a high probablity that they will all be under 50,000 
// 50,000 = 50/1,000,000 * 1,000,000,000
// Let's be like super safe and say anything
// 500,000 might be in the lowest 50.
// Linear pass through the million sized vector
// and add anything smaller than 500,000 to another vector
// Sort that additional vector and call it a day.
// Run some other algorithm in the case that this does not work.
// Fast and without guaranteed performance, but will work well in most cases.
// Obviously bad for the fact that it makes assumptions about the data that may
// not always hold up and you need all the above to justify it.
// Not gonna include it in the best solutions for this reason.
#include "helper.cpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <time.h>

const int SAFETY = 10;

int main(int argc,char *argv[]){
    std::vector<int> numVec;
    std::vector<int> resultVec;
    int inputInt;
    
    genNumVec(numVec);
    
    
    clock_t progTime = clock();
    
    for(int i = 0; i < numVec.size(); i++){
        if(numVec[i] < SAFETY * 50000 ){
            resultVec.push_back(numVec[i]);
        }
    }
    
    if(resultVec.size() < 50){
        std::cout<<"Won't work, try a higher safety margin/different algo\n";
        return 1;
    }
    
    std::sort( resultVec.begin(), resultVec.end() );
    
    
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    output50Smallest(resultVec, "output/output_z.txt");
    
    return 0;
}
