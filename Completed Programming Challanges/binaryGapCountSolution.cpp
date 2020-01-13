// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    typedef unsigned int uint;
    uint mask = 1;
    uint maxGap = 0;
    uint tempGap = 0;
    N |= N-1;
    while(mask < N)
    {
        if(mask & N)
        {
            maxGap = std::max(tempGap, maxGap);
            tempGap = 0;
        }
        else
        {
            tempGap += 1;
        }
        mask = mask << 1;
    }
    
    return maxGap;
    
}
