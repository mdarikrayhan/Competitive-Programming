#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) (x).begin(),(x).end()
#define clr(v, d)            memset(v, d, sizeof(v))
#define fx(x) fixed<<setprecision(x)
#define sz(x) x.size()
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
const int N = 1e6+2;
const ll mod = 1e9+7;
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
int getbit(int num, int idx) {return (num >> idx) & 1;}
int sitbit1(int num, int idx) {return num | (1 << idx);}
int sitbit0(int num, int idx){return num & ~(1 << idx);}
int countbits1(int num){int cnt = 0;while (num){cnt += num & 1; /* first bit in num*/num >>= 1;/* num/=2;*/}return cnt;}

void solve()
{
    int n,k,x;cin>>n>>k>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int mx=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]==x&&v[i-1]==x)
        {
            int l=i-1,r=i;
            queue<pair<int,int>>q;
            int sum=2;
            if(i+1<n)
            {
                pair<int,int>c={v[i+1],1};
                for(int j=i+2;j<n;j++)
                {
                    if(v[j]!=c.first)
                    {
                        q.push(c);
                        c={v[j],1};
                        continue;
                    }
                    c.second++;
                }
                q.push(c);
            }
            if(i-1>0)
            {
                pair<int,int>c={v[i-2],1};
                for(int j=i-3;j>=0;j--)
                {
                    if(v[j]!=c.first)
                    {
                        if(q.empty()||c.first!=q.front().first||c.second+q.front().second<3)
                        {
                            break;
                        }
                        sum+=c.second+q.front().second;
                        q.pop();
                        c={v[j],1};
                        continue;
                    }
                    c.second++;
                }
                if(q.size()&&q.front().first==c.first&&c.second+q.front().second>=3)
                    sum+=c.second+q.front().second;
            }
            mx=max(mx,sum);
        }
    }
    cout<<mx;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("metro.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--)solve();
}

		    	    	   	 			 			     		