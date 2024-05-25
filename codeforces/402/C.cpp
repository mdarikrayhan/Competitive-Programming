#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    int n,p;
    cin>>n>>p;
    int total = 2*n+p;
    map<pair<int,int>,bool> ex;
    vector<pair<int,int>> result;
    int x = 1, y = 2;
    for(int i=1; i<=total; i++)
    {
        while(ex[{x,y}] || ex[{y,x}] || y == x)
        {
            y++;
        }
        if(y > n)
        {
            y = 1;
            x++;
            i--;
            continue;
        }
        result.push_back({x,y});
        ex[{x,y}] = true;
    }
    for(pair<int,int> e: result)
    {
        cout<<e.first<<" "<<e.second<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}