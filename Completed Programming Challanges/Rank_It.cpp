#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int X, int start, int N, vector<int> &A)
{
    int low = start;
    int high = N;
    while(low <= high)
    {
        int mid = (low+high)>>1;
        if(A[mid] < X)
            low = mid+1;
        else if(A[mid] > X)
            high = mid-1;
        else
            return mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N;
    vector<int> A(N);
    
    for(int i = 0; i < N; i++)
        cin >> A[i];
        
    sort(A.begin(), A.end());
    
    cin >> Q;
    vector<int> queries(Q);
    
    for(int i = 0; i < Q; i++)
        cin >> queries[i];
        
    for(int query : queries)
        cout << BinarySearch(query, 0, N, A) << "\n";
    
    return 0;
}
