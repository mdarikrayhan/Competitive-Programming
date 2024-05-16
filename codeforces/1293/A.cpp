#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--){
        ll n,s,k;
        cin>>n>>s>>k;
        set<int>se;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            se.insert(x);
        }
        if(se.find(s)==se.end()){
            cout<<"0"<<endl;
        }
       
    else
    {
        ll i = s + 1;
        while(i <= n && se.find(i) != se.end())
        {
            i++;
        }
        ll M = -1;
        if(i <= n)
        {
            M = i;
        }
 
        ll j = s - 1;
 
        while(j >= 1 && se.find(j) != se.end())
        {
            j--;
        }
        ll m = -1;
        if(j >= 1)
        {
            m = j;
        }
        ll ans;
         if(m == -1)
        {
            // cout << M << "\n";
            ans = M;
        }
        else if(M == -1)
        {
            // cout << m << "\n";
            ans = m;
        }
        else
        {
            if(s - m < M - s)
            {
                // cout << m << "\n";
                ans = m;
            }
            else
            {
                // cout << M << "\n";
                ans = M;
            }
        }
        cout << abs(s - ans) << "\n";
 
    }
        }
}