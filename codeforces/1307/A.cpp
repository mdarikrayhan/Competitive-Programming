#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define salah  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define no cout << "NO" << endl
#define yes cout << "YES" << endl

#define sort_(n) sort(n.begin(),n.end())
#define reverse_(n) reverse(n.begin(),n.end())


//a.erase(uniqu e(a.begin(), a.end()), a.end());

//**********************************************
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}
//************************************************
string Tobinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
//************************************************
bool isPrime(int num)
{
    if (num<2)
        return false;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}
//*************************************************

const double pi=3.141592654;
const int NMAX=1e9+7;
const int MOD=32768;
const int N=2e5;
ll n,k,m,l,r,e,q,a,b,x=0,y,c,z,d,avg,g,h,w;


int node[N]={0};



void solve()
{
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            while(a[i]>0)
            {
                a[i]--;
                if(k-i>=0)
                    k-=i;
                else
                    break;
                ans++;
            }
        }
    }
    cout << ans+a[0] << endl;
}



int main()
{
    salah;
    int t=1; cin >> t;
    while(t--){
            solve();
    }
    return 0;
}








    /*
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> node[i];
        }
        for(int i=0;i<n-1;i++)
        {
            ll u,v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(1);
    */






/*
1
3334567
3337654
3337554
3334667
*/









    /*
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> node[i];
        }
        for(int i=0;i<n-1;i++)
        {
            ll u,v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(1);
    */






/*
1
3334567
3337654
3337554
3334667
*/
