#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N;
    cin >> T;
    
    while(T--)
    {
        cin >> N;
        vector<pair<int,int>> stations(N);
        
        for(int i = 0; i < N; i++)
            cin >> stations[i].first;
        for(int i = 0; i < N; i++)
            cin >> stations[i].second;
            
        long long minCost = stations[0].first;
        long long totalCost = 0;
        
        for(int i = 0; i < stations.size(); i++)
        {
            totalCost += minCost * stations[i].second;
            if(stations[i+1].first < minCost)
                minCost = stations[i+1].first;
        }
        cout << totalCost << "\n";
    }
    
    
    return 0;
}
