#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tst;
    cin>>tst;
    for(ll test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        ll n;
        cin>>n;
        string s;
        cin>>s;
        bool flag=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='8')
            {
                if(n-i>=11)
                {
                    flag=true;
                    break;
                }
            }
        }
        flag?yes:no;

    }
}
		 			   	  	  			  			