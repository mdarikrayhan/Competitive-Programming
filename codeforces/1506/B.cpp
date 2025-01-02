#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long int
#define mod (int)(1e9 + 7)
#define pb push_back 
#define eb emplace_back
#define mpp make_pair 
#define vi vector<int>
#define vc vector<char>
#define SI set<int>
#define SC set<char>
#define mpf map<int,int>
#define rr(i,a,b) for(int i=a;i>=b;i--)
#define r(i,a,b) for(int i=a;i<b;i++)
#define rv(i,mpp) for(auto i:mpp)
#define debug(x) cerr << (#x) << " is " << (x) << endl
#define minele(x) *min_element(all(x))
#define maxele(x) *max_element(all(x))
#define all(x) x.begin(), x.end()
#define set_bits(x) __builtin_popcountll(x)
#define leading_zero(x) __builtin_clz(x)
#define trailing_zero(x) __builtin_ctz(x)
using namespace std;

void speed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void phan()
{
    int n,k,ans=0,st=-1,ed=-1;
    cin>>n>>k;
    string s;
    cin>>s;
    r(i,0,n)
    {
        if(s[i]=='*')
        {
            if(st==-1)
            st=i;
            ed=i;
        }
    }
    ed=min(n-1,ed);
    for(int i=st;i<=ed;i+=k)
    {
        while(s[i]=='.')
        i--;
        s[i]='X';
        ans++;    
        //cout<<i<<" ";
    }
    if(s[ed]!='X')
    ans++;
    cout<<ans;
    
    cout<<"\n";
}


int main() {
    speed();
	int itp;
	cin>>itp;
	for(int iot=0;iot<itp;iot+=1)
	phan();
	return 0;
}