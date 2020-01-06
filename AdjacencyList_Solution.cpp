#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E, A, B;
    cin >> V >> E;
    vector<int> adjList[V];
    
    for(int i = 0; i < E; i++)
    {
        cin >> A >> B;
        adjList[A].push_back(B);
    }
    
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> A >> B;
        for(int  j = 0; j < adjList[A].size(); j++)
        {
            if(!adjList[A].empty() && adjList[A][j] == B)
            {
                cout << "YES" <<"\n";
                break;
            }
            else if(adjList[A].empty() || j == adjList[A].size()-1)
            {
                cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}
