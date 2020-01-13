#include <bits/stdc++.h>
using namespace std;

stack<int> trace_path(vector<int> &path, int X, int Y)
{
    stack<int> shortest_path;
    int curr = Y;
    while(path[curr] != -1)
    {
        shortest_path.push(curr);
        curr = path[curr];
    }
    shortest_path.push(X);
    return shortest_path;
}

void bfs(vector<int> adjList[], int X, vector<bool> &visited, vector<int> &path)
{
    queue<int> q;
    
    q.push(X);
    visited[X] = true;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int w = 0; w < adjList[curr].size(); w++)
        {
            if(!visited[adjList[curr][w]])
            {
                visited[adjList[curr][w]] = true;
                path[adjList[curr][w]] = curr;
                q.push(adjList[curr][w]);
            }
        }
    }
}

int main()
{
    //GETTING ALL THE BASIC IO INPUTS
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, C, T, U, V, X, Y;
    cin >> N >> M >> C >> T;
    vector<int> adjList[N+1];
    
    for(int i = 0; i < M; i++)
    {
        cin >> U >> V;
        adjList[U].push_back(V);
        adjList[V].push_back(U);
    }
    
    //sorting the array so that the solution is laxographically shortest path
    for(int i = 1; i < N+1; i++)
        sort(adjList[i].begin(), adjList[i].end());
    
    cin >> X >> Y;
    
    //CREATING UTILITY CONTAINERS
    vector<bool>visited(N+1);
    vector<int>path(N+1, -1);
    bfs(adjList, X, visited, path);
    
    stack<int> shortest_path = trace_path(path, X, Y);
    
    //OUTPUT
    cout << shortest_path.size() << "\n";
    while(!shortest_path.empty())
    {
        cout << shortest_path.top() << " ";
        shortest_path.pop();
    }
    cout << "\n";
    
    return 0;
}
