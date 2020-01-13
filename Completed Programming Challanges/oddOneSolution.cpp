// you can use includes, for example:
#include <algorithm>
#include <unordered_map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    typedef unsigned int uint;
    std::unordered_map<int,int> dict;
    
    for(uint i = 0; i < A.size(); i++)
    {
        if(!dict.insert({A[i], 1}).second)
            dict.at(A[i]) += 1;
    }
    for(auto& i : dict)
    {
        if((i.second % 2) != 0)
            return i.first;
    }
    return 0;
}