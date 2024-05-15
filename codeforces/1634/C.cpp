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
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES\n";
        r(i,1,n+1)
        cout<<i<<"\n";
        return;
    }
    if(!(n&1))
    {
        cout<<"YES\n";
        int od=1,ev=2;
        r(i,0,n)
        {
            int kk=k;
            if(i&1)
            {
                while(kk--)
                {
                    cout<<od<<" ";
                    od+=2;
                }
                cout<<"\n";
            }
            else
            {
                while(kk--)
                {
                    cout<<ev<<" ";
                    ev+=2;
                }
                cout<<"\n";
            }
        }
        return;
    }
    cout<<"NO";
    
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