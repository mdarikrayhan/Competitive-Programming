#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

bool sign=1;

#define debug(x) if(sign) cerr<<#x<<"="<<(x)<<'\n';
#define bug(x) if(sign) cout<<"@"<<(x)<<'\n';
#define kill(x) return cout<<x<<'\n',void()
#define fixset(x) fixed<<setprecision(x)
#define endl '\n'

const int N=3e5+5;
int a[N];

int testcase,tc,n;

void RuinGuard()
{
    cin>>n;
    string str; cin>>str;

    if(str.front()!='9') {
        string ans;
        for(auto c : str) {
            ans += to_string('9'-c);
        }
        kill(ans);
    }
    
    vector <int> res(n);
    for(int i=0;i<n-1;i++) {
        res[i]='9'-str[i];
    }
    res[n-1]='9'-str.back()+1;

    for(auto it : res) debug(it);
    reverse(res.begin(),res.end());

    // string num;
    // for(int i=1;i<=n;i++) num.push_back('1');

    for(int i=0;i<n;i++) {
        res[i]++;
        if(res[i]>=10) {
            res[i+1]++;
            res[i] %= 10;
        }
    }
    if(res.back()>=10) {
        res.push_back(1);
        res.back() %= 10;
    }

    for(int i=n-1;i>=0;i--) {
        cout<<res[i]<<(i ? "" : "\n");
    }
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); sign=0;
    
    cin>>testcase;
    for(tc=1;tc<=testcase;tc++) {
    	RuinGuard();
	} 

    return 0;
}