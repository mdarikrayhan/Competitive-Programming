#include <bits/stdc++.h>
using namespace std;
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define int long long
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define MOD 1000000007
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define endl '\n'
void vecprint(vector<int> &a)
{
    for (auto val : a)
        cout << val << " ";
    cout << endl;
}
void mapprint(map<int, int> &a)
{
    for (auto val : a)
        cout << val.first << " " << val.second << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<n+1<<endl;
    for(int i=0;i<n;i++){
        a[i]+=10000;
    }
    cout<<1<<" "<<n<<" "<<10000<<endl;
    for(int i=0;i<n;i++){
        cout<<2<<" "<<i+1<<" "<<a[i]-i-1<<endl;
    }
    return 0;
}