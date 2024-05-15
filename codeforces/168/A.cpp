#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    float n,x,y;
    cin>>n>>x>>y;
    int k=ceil(n*(y/100));
    cout<<((x>k)?0:k-x);

    return 0;
}