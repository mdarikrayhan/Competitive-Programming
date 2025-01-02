#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int degree[n];
    int xorsum[n];
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        cin>>degree[i]>>xorsum[i];
        if(degree[i] == 1)
        {
            q.push(i);
        }
    }
    vector<pair<int,int>> result;
    while(!q.empty())
    {
        int from = q.front();
        q.pop();
        if(degree[from] != 1)continue;
        int to = xorsum[from];
        xorsum[from] = 0;
        // if(from != to)
            result.push_back({from, to});
        xorsum[to] ^= from;
        degree[to]--;
        if(degree[to] == 1)
            q.push(to); 
    }
    cout<<result.size()<<"\n";
    for(pair<int,int> e: result)
    {
        cout<<e.first<<" "<<e.second<<"\n";
    }
    return 0;
}