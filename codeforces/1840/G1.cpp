#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void setIO(string name)
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    if(name.size()){freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------------------------code------------------------------------*/
const ll MAXN=1e6+3;
const ll INF=1e9;
const int R=(1<<18);

vector<int> arr(MAXN, 0);
int x, mx;

int query(int val)
{
    cout<<'+'<<" "<<val<<"\n";
    val=0;
    cin>>val;
    return val;
}

void solve()
{
    cin>>x;
    int pos=1;
    arr[x]=pos;
    for(int i=1;i<1000;i++)
    {
        int res=query(1);
        pos++;
        if(arr[res])
        {
            cout<<'!'<<" "<<pos-1<<"\n";
            return;
        }
        arr[res]=pos;
    }
    while(1)
    {
        int res=query(1000);
        pos+=1000;
        if(arr[res])
        {
            cout<<'!'<<" "<<pos-arr[res]<<"\n";
            return;
        }
        arr[res]=pos;
    }
}

int main()
{
//    setIO("");
    solve();
    return 0;
}
