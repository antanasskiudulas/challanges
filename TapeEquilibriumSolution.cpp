// you can use includes, for example:
#include <algorithm>
#include <limits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    typedef unsigned int uint;
    vector<int> runSum(A.size());
    uint tempSum = 0;
    for(uint i = 0; i < A.size(); i++)
    {
        tempSum = tempSum + A.at(i);
        runSum[i] = tempSum;
    }
    
    uint minAbsDiff = std::numeric_limits<int>::max();
    for(uint i = 0; i < runSum.size()-1; i++)
    {
        uint absDiff = abs(runSum[i] - (runSum.back()-runSum[i]));
        minAbsDiff = (absDiff < minAbsDiff) ? absDiff : minAbsDiff;
    }
    return minAbsDiff;
}