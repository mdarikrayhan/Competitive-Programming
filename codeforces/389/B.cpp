#include<bits/stdc++.h>
 
#define Safid_Anir ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(x)  (int)(x).size()
#define all(x)  (x).begin(),(x).end()
#define rall(x)  (x).rbegin(),(x).rend()
#define alll(x) (x).begin(),(x).end(),(x).begin()
#define sp " "
#define nl '\n'
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vpd vector<pair<double, double>>
#define vps vector<pair<string, string>>
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define ps partial_sum
#define ite iterator
#define pq priority_queue
#define ll long long
#define ld long double
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define f(x,y) for(long long x=0;x<y;x++)
#define pi 2*acos(0.0)
 
const ll N =  1e9+7;
 
using namespace std;
 
void judge()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
void print(vector<ll>v)
{
    for(auto &x : v)
        cout << x << sp;
    cout << nl;
}
 
// void substring(string s)
// {
//     for (int i = 0; i <= l(s); i++)
//     {
//         for (int j = 0; j <= l(s) -i; j++)
//         {
//             int l = j + i - 1;
//             for (int k = i; k <= l; k++)
//                 cout << s[k];
 
//             cout << nl;
//         }
//     }
// }
 
// void permutation(vector<ll>v)
// {
//     sort(all(v));
//     cout << "All possible permutations with the elements:\n";
//     do
//     {
//         print(v);
//     }
//     while (next_permutation(all(v)));
// }
 
// string to_binary(int x) {
//     string s;
//     while(x > 0) {
//         s += (x % 2 ? '1' : '0');
//         x /= 2;
//     }
//     reverse(s.begin(), s.end());
//     return s;
// }
 
// ll GCD(ll x,ll y)
// {
//     if(y==0)
//         return x;
//     else
//         return GCD(y,x%y);
// }
 
// ll LCM(ll x,ll y)
// {
//     return (x*y/(GCD(x,y)));
// }
 
// vector<bool> Sieve(ll n) 
// { 
//     vector<bool>prime(n+1,true); 
//     for(ll p = 2; p * p <= n; p++) 
//     {  
//         if (prime[p] == true) 
//         {  
//             for (ll i = p * p; i <= n; i += p) 
//                 prime[i] = false; 
//         } 
//     }  
//     return prime;
// } 
 
// void tree(ll l,ll r,vl& v,vector<vector<ll>>&u)
// {
//     if(u[l].size()==1 && u[l][0]==r)
//         v[l]=1;
//     else
//     {
//         for(auto&x:u[l])
//         {
//             if(x!=r)
//             {
//                 tree(x,l,v,u);
//                 v[l]+=v[x];
//             }
//         }
//     }
// }

// vl baloon(ll mid,ll m,vector<vector<ll>>v)
// {
//     vl vx;
//     ll s = 0;
//     f(i,v.size())
//     {
//         ll t = v[i][0];
//         ll x = v[i][1];
//         ll y = v[i][2];
//         ll n = t*x+y;
//         ll g = (mid/n)*x + min(x,((mid%n)/t));
//         if(s+g>m)
//             g=m-s;
//         s+=g;
//         vx.pb(g);
//     }
//     return vx;
// }
 
// vl v(2e5+1,0);
// void sd()
// {
//     for(ll i=1;i<=2e5;i++)
//     {
//         ll s = 0,j=i;
//         while(j>0)
//         {
//             s+=j%10;
//             j/=10;
//         }
//         v[i]=v[i-1]+s;
//     }
// }

// vector<ll>vd;
// ll nd(vector<ll>v)
// {
//     ll cnt = 0;
//     f(i,l(v))
//     {
//         ll c=0,x=v[i],f=0;
//         while(x>0)
//         {
//             ll r = x%10;
//             if(r==0 && !f)
//                 c++;
//             else
//             {
//                 vd.pb(c);
//                 f=1;
//             }
//             x/=10;
//             cnt++;
//         }
//     }
//     return cnt;
// }

// bool Comparator(const pair<int, int>& a, const pair<int, int>& b) {
//     // if (a.first == b.first) {
//     //     return a.second < b.second; // If first elements are equal, sort by second element
//     // }
//     return a.second < b.second;
// }

// ll n,k;
// vl v;

// bool ok(ll m)
// {
//     ll s=0;
//     f(i,n)
//     {
//         if(v[i]<m)
//             s+=m-v[i];
//     }
//     return s<=k;
// }

// bool digits(ll n)
// {
//     while(n>0)
//     {
//         ll r=n%10;
//         n/=10;
//         if(r!=0 && r!=1)
//             return false;
//     }
//     return true;
// }

// ll check(ll n,vl v,ll k)
// {
//     ll ans=0;
//     ll mx=*max_element(v.begin(),v.begin()+k);
//     if(mx>v[k])
//         return 0;
//     if(k!=0)
//         ans++;
//     for(ll i=k+1;i<n;i++)
//     {
//         if(v[i]>v[k])
//             break;
//         ans++;
//     }
//     return ans;
// }

// ll fix_MOD(ll a,ll b)
// {
//     return ((a%b)+b)%b;
// }

 
// ll rec(ll i)
// {
//     return 0;
// }


// void display(ll i,ll j)
// {

// }

void solution()
{
    ll n;
    cin >> n;
    vs v;
    vector<vector<ll>>vd;
    vd.assign(n,vector<ll>(n,0));
    f(i,n)
    {
        string s;
        cin >> s;
        v.pb(s);
    }
    ll c=0;
    f(i,n)
    {
        f(j,n)
        {
            if(v[i][j]=='#' && vd[i][j]==0)
            {
                c++;
                vd[i][j]=1;
                if(i+2<n && j+1<n && j-1>=0)
                {
                    if(v[i+1][j]=='#' && v[i+2][j]=='#' && v[i+1][j-1]=='#' && v[i+1][j+1]=='#')
                    {
                        if(vd[i+1][j]==0 && vd[i+2][j]==0 && vd[i+1][j-1]==0 && vd[i+1][j+1]==0)
                        {
                            vd[i+1][j]=vd[i+2][j]=vd[i+1][j-1]=vd[i+1][j+1]=1;
                        }
                        else
                        {
                            no;
                            return;
                        }
                    }
                    else
                    {
                        no;
                        return;
                    }
                }
                else
                {
                    no;
                    return;
                }
            }
        }
    }
    yes;
}  
int main()
{
    Safid_Anir;
    judge();
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solution();
        //cout << nl;
        //cout << t << nl;
        // if(t>0)
        //     cout << nl;
    }
    return 0;
}

	 	  			  	 		 	  	    	  	 		