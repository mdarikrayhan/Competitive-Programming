#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define In freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> // set
#define  ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1,-1,-1};
void fileIO() {
    IO;
#ifndef ONLINE_JUDGE
    In;
#endif
}
const int N=2e5+10;
ll mod=1e9+7;
ll INF=1e18;

int main() {
    fileIO();
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(n%(i+1)==0)reverse(s.begin(),s.begin()+i+1);
    }
    cout<<s<<'\n';
}