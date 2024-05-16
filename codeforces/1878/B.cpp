/*****************************************
        author: |  Suzit Datta  |
******************************************/
 
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define double long double
#define endl '\n'
#define INF 1e18
#define MOD 1e9+7
#define PI (2.0 * acos(0.0))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define asort(x) sort(all(x))
#define dsort(x) sort(all(x), greater<int>())
#define unq(x) {sort(all(x));x.erase(unique(x.begin(), x.end()), x.end());}
#define setBits(x) __builtin_popcount(x)  // count 1 in binary representation
#define deci(x, zeros) cout << fixed << setprecision(zeros) << x << endl;
#define bs(v, x) binary_search(all(v), x)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Kamehameha() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
int fact(int n) {if (n == 0)return 1; int res = 1;for(int i = 2; i <= n; i++)res = res * i; return res;}
int gcd(int a, int b) {if(b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return (a / gcd(a, b) * b);}
int digitSum(int a) {int sum = 0; for (int i = a; i > 0; i /= 10){sum += i % 10;}return sum;}
int gcdExtended(int a, int b, int *x, int *y) {
    if (b == 0) {*x = 1; *y = 0; return a;} 
    int x1, y1; int gcd = gcdExtended(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return gcd; 
} 
int lastSetBit(int n) {bitset<64>x(n); for (int i = 63; i >= 0; i--)if (x[i] == 1)return i; return 0;}
 
bool isPrime(int n) {for(int i = 2; i * i <= n; i++){if (n % i == 0){return false;}}return true;}
bool isPalindrome(string s) {int i = 0, j = s.size()-1; for(i, j; i <= j; i++, j--){if(s[i] != s[j]) return 0;} return 1;}
bool isPalindrome(int num){int n,digit,rev=0;n=num; do{digit=num%10; rev=(rev*10)+digit; num=num/10;}
    while (num != 0);if(n == rev){return true;}return false;}
bool cmpPair(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first > p2.first) return true;
    else if (p1.first == p2.first) return (p1.second < p2.second);
    return false;
}

bool cmp3Pair(const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
{
    if (p1.second.second < p2.second.second) return true;
    else if (p1.second.second == p2.second.second && p1.second.first < p2.second.first) return true;
    else if (p1.second.second == p2.second.second && p1.second.first == p2.second.first && p1.first < p2.first)
        return true;
    return false;
}

//===============  solution ===============
 
inline void solveJutsu() {
    int n;  cin>>n;
    vector<int> ans(n);
    ans[0] = 3;
    ans[1] = 4;

    int i = 0, j = 5;
    while (i < n-2)
    {
        if((3*j)%(ans[i]+ans[i+1]) != 0){
            ans[i+2] = j;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    Kamehameha();

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solveJutsu();
    }
    return 0;
}