#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#define ll long long
#define ull unsigned long long
#define ld long double
#define nl "\n"
#define str string
#define sp " "
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define vec vector
#define pb push_back
#define fixed(n) fixed << setprecision(n)
using namespace std;
 
void Moageza()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin),freopen("output.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
}
void solve()
{
   int a,d=0,c=0,s=0,f=0;cin >> a;
   vec<int>v(a);
   for(int i = 0; i < a; i++)cin >> v[i];
   for(int i =0; i < a; i++){
    if(v[i]==-1)c++;
    else if(v[i]==1) {
        d=max(d,c);
        c=0;
    }
   }
   d=max(d,c);
   if(d==0){
    for(int i = 0;i < a;i++){
        if(i<=1)s-=v[i];
        else s+=v[i];
    }
   }
    if(d==1){
    for(int i = 0;i < a;i++){
        if(((v[i]==-1&&v[i+1]==1)||(v[i]==1&&v[i+1]==-1))&&f==0){
            s-=v[i],s-=v[i+1];
            i++,f++;
        }
        else s+=v[i];
    }
   }
    if(d>=2){
    for(int i = 0;i < a;i++){
        if(v[i]==-1&&v[i+1]==-1&&f==0){
            f++;
            s+=abs(v[i]),s+=abs(v[i+1]);
            i++;
        }
        else s+=v[i];
    }
   }
   cout<<s;
}
int main()
{
    Moageza();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
           cout << nl;
    }
    //   solve();
    return 0;
}