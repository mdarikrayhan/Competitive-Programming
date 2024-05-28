#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define mapi map<int,int>
#define mapll map<ll,ll>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

const int M = 1e9 + 7;

int binexp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}
// For x mmi M, do binexp(x, M - 2, M)

const int p1 = 31;
const int p2 = 53;
const int hashM = 1e9 + 9;

void computePrefixHash(
    string &str, int n,
    int prefix[],
    int power[])
{
    prefix[0] = 0;
    prefix[1] = str[0];
 
    for (int i = 2; i <= n; i++)
        prefix[i] = (prefix[i - 1] % hashM + (str[i - 1] % hashM * power[i - 1] % hashM) % hashM) % hashM;
 
    return;
}

void computeSuffixHash(
    string &str, int n,
    int suffix[],
    int power[])
{
    suffix[0] = 0;
    suffix[1] = str[n - 1];
 
    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++)
        suffix[j] = (suffix[j - 1] % hashM + (str[i] % hashM * power[j - 1] % hashM) % hashM) % hashM;
    return;
}

//Pass 1 based
int computeHash(
    string &str, int n,
    int prefix[],
    int power[],
    int start, int end)
{
    ll val = (prefix[end] - prefix[start - 1] + hashM) % hashM;
    val = (val * (power[n - start])) % hashM;
    return val;
}

//Pass 1 based
int computeRevHash(
    string &str, int n,
    int suffix[],
    int power[],
    int end, int start)
{
    start = n + 1 - start;
    end = n + 1 - end;
    ll val = (suffix[end] - suffix[start - 1] + hashM) % hashM;
    val = (val * power[n - start]) % hashM;
    return val;
}

void solve(){
    int n, m;
    cin>>n>>m;
    int arr[n + 1][m];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    int x = 1, y = 1;
    int low = 0, high = 1e9;
    int check = (1<<m) - 1;
    int hash2[1<<m]{0};
    int hash[n + 1]{0};
    while(low <= high){
        int mid = (low + high) / 2;
        for(int i = 1; i <= n; i++){
            int mask = 0;
            for(int j = 0; j < m; j++){
                int bit = 1<<j;
                if(arr[i][j] >= mid)mask = mask ^ bit;
            }
            hash[i] = mask;
        }
        for(int i = 0; i <= check; i++)hash2[i] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= check; j++){
                if((j & hash[i]) == j)hash2[j] = i;
            }
        }
        int f = 0;
        for(int i = 1; i <= n; i++){
            int find = hash[i] ^ check;
            if(hash2[find] > 0){
                x = i; y = hash2[find];
                low = mid + 1;
                f = 1;
                break;
            }
        }
        if(f)low = mid + 1;
        else high = mid - 1;
    }
    cout<<x<<" "<<y<<endl;
}

signed main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}