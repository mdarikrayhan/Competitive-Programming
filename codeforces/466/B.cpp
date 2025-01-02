/*
    Author: Ritwij Kumar
    Hello there!
    Enjoy my code
*/

#include<bits/stdc++.h>
#include<numeric>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define float long double
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PYes cout<<"Yes\n"
#define PNo cout<<"No\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define ff(i,a,b) for(int i=b-1;i>=a;i--)
#define int long long
#define vi vector <int>
#define pb push_back
#define fr first
#define se second
#define look a int a; cin>>a
#define vvi vector < pair <int,int> >
#define pbmp(a,b) push_back(make_pair(a,b))
#define Hakunamatata ios_base::sync_with_stdio(false); cin.tie(NULL);
const int MOD = 1e9 + 7;

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void vin(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}


bool comp1(pair<int,int>p1, pair<int,int>p2){
    return p1.first<p2.first;
}
//sort(v.begin(), v.end(), comp1);
bool comp2(pair<int,int>p1, pair<int,int>p2){
    return p1.second<p2.second;
}
//sort(v.begin(), v.end(), comp2);
int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}
// seive of erastothenes
    // vector <bool> is_prime(n+1, true);
    // is_prime[0]=is_prime[1]=false;
    // for(int i=2; i<n; i++){
    //     if(is_prime[i] && i*i<=n){
    //         for(int j=i*i; j<=n; j+=i)
    //         is_prime[j]=false;
    //     }
    // }
    // for(int i=0; i<n ; i++){
    //     if(is_prime[i]==true)
    //     cout<<i<<" ";
    // }

// lower_bound(arr.begin(),arr.end(),x)-arr.begin();
// upper_bound(arr.begin(),arr.end(),x)-arr.begin();

int32_t main(){
    Hakunamatata 
    int n, x, y;
    cin >> n >> x >> y;
    float mf = sqrt(6 * n);
    int m = ceil(mf);
    int ans = 1e18,ans_x=x,ans_y=y;
    int s = 6 * n;
    if (x * y >= s)
    {
        cout << x * y << endl;
        cout << x << " " << y << endl;
    }
    else{
        for (int i = min(x,y); i <= m; i++)
        {
            if(s/i>=max(x,y)){
                int j;
                (s % i==0) ? j = s / i : j = s / i + 1;
                int area = i * j;
                if (area < ans && area >= s)
                {
                    ans = area;
                    ans_x = i;
                    ans_y = j;
                }
            }
        }
        cout << ans << endl;
        if(x<=y)cout << ans_x << " " << ans_y << endl;
        else
            cout << ans_y << " " << ans_x << endl;
    }
}