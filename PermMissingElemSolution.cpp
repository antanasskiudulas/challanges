// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    typedef unsigned int uint;
    
    vector<int> counter(A.size()+1);
    for(uint i = 0; i < A.size(); i++)
        counter[A[i]-1] += 1;
        
    for(uint i = 0; i < counter.size(); i++)
        if(counter[i] == 0)
            return i+1;
            
    return 0;
    
}