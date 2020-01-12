#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[], vector<bool> &visited, int node)
{
    visited[node] = true;
    for(int i = 0; i < adjList[node].size(); i++)
    {
        if(!visited[adjList[node][i]])
            dfs(adjList, visited, adjList[node][i]);
    }
}

int main()
{
    int N, E, S, D, X;
    cin >> N >> E;
    vector<int> adjList[N+1];
    vector<bool> visited(N+1);
    
    for(int i = 0; i < E; i++)
    {
        cin >> S >> D;
        adjList[S].push_back(D);
        adjList[D].push_back(S);
    }
    cin >> X;
    dfs(adjList, visited, X);
    
    int unreachable = 0;
    for(int i = 1; i < visited.size(); i++)
        if(!visited[i])
            unreachable++;
    
    cout << unreachable << endl;
    
    return 0;
}
