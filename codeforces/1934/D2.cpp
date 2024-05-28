#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;
using ii = pair<long long int ,long long int>;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
ll MOD = 1000000007;
void solve(){
    ll n;
    cin>>n;
    if(__builtin_popcountll(n)%2==0)
    {
        ll x=0;
        cout<<"first"<<endl;
        ll cnt=0;
        ll temp=n;
        while(temp)
        {
            temp/=2;
            cnt++;
        }
        cnt--;
        x=(1LL<<cnt);
        n-=x;
        cout<<x<<' '<<n<<endl;
        while(1)
        {
        cin>>x>>n;
        if(x==0&&n==0)
        {
            return;
        }
        if(x==-1)
        {
            return;
        }
        if(__builtin_popcountll(n)%2==0)
        {
            temp=n;
            cnt=0;
            while(temp)
            {
                temp/=2;
                cnt++;
            }
            cnt--;
            x=(1LL<<cnt);
            n-=x;
        }
        else if(__builtin_popcountll(x)%2==0)
        {
            temp=x;
            cnt=0;
            while(temp)
            {
                temp/=2;
                cnt++;
            }
            cnt--;
            n=(1LL<<cnt);
            x-=n;
        }
        else
        {
            x=0;
            n=0;
        }
        cout<<x<<' '<<n<<endl;
        }

    }
    else
    {
        ll x=0;
        cout<<"second"<<endl;
        ll temp,cnt;
        while(1)
        {
        cin>>x>>n;
        if(x==0&&n==0)
        {
            return;
        }
        if(x==-1)
        {
            return;
        }
        if(__builtin_popcountll(n)%2==0)
        {
            temp=n;
            cnt=0;
            while(temp)
            {
                temp/=2;
                cnt++;
            }
            cnt--;
            x=(1LL<<cnt);
            n-=x;
        }
        else if(__builtin_popcountll(x)%2==0)
        {
            temp=x;
            cnt=0;
            while(temp)
            {
                temp/=2;
                cnt++;
            }
            cnt--;
            n=(1LL<<cnt);
            x-=n;
        }
        else
        {
            x=0;
            n=0;
        }
        cout<<x<<' '<<n<<endl;
        }
        
    }
}
int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    // t=1;
    cin >> t;
    while (t--) {
        solve();
    }

	// your code goes here
	return 0;
}