#include <bits/stdc++.h>
#include <numeric>
#include <cmath>
#define _USE_MATH_DEFINES
#define M_PI           3.14159265358979323846  /* pi */
#define ll long long
#define loop(n); for(ll i=0; i<n; i++)
#define lop(n); for(ll j=1; j<=n; j++)
#define loop2(n); for(ll i=n-1; i>0; i--)
#define ed "\n" ;
#define cn cout<<"NO"<<ed;
#define cy cout<<"YES"<<ed;
#define all(x) (x).begin() , (x).end()
#define in(v); for(auto &i:v){cin>>i;}
#define ON(n,k) ((n)|(1<<k))
#define OFF(n,k) ((n)&~(1<<k))
#define isON(n,k) (((n)>>(k))&1)
const int OO = 0x3f3f3f3f;

using namespace std;
// Recursive Binary Search function to find the index of an
// element 'x' in a sorted array 'arr' if elements is
// present, otherwise it return -1

// low: The index of the first element in the current
// sub-array high: The index of the last element in the
// current sub-array
int binarySearch(int arr[], int low, int high, int x) {
    // Base case: If the search space becomes empty, the
    // element is not present in the array
    if (high >= low) {
        // Calculate the middle index to divide the search
        // space in half
        int mid = low + (high - low) / 2;
        // If the middle element is equal to 'x', we have
        // found the element, return its index
        if (arr[mid] == x)
            return mid;

        // If the middle element is greater than 'x', search
        // in the left half of the array
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // If the middle element is less than 'x', search in
        // the right half of the array
        return binarySearch(arr, mid + 1, high, x);
    }

    // If the base case is reached, the element is not
    // present in the array, return -1
    return -1;
}
bool isLucky(int n) {
    int x;
    while(n>0) {
        x=n%10;
        n/=10;
        if(x==7 || x==4)
            return 1;
    }
    return 0;
}
void solvee() {
    int n;
    cin>>n;
    for(int i=4; i<=n; i++) {
        if(n%i==0 && isLucky(i) ) {
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}

int ddiv(int n, int x) {
    if(n<=x)return 1;
    return ddiv(n>>1,x)+ddiv((n>>1)+(n&1), x);
}
void round_number( ) {
    int n,cnt=0;
    cin>>n;
    int i=1,x;
    vector<int>v;
    while(n>0) {
        x=n%10;
        if(x!=0) {
            v.push_back(x*i);
            cnt++;
        }
        n/=10;
        i*=10;
    }
    cout<<cnt<<endl;
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
}


bool eight (int m) {
    int n = abs(m);
    int x;
    while(n>0) {
        x=n%10;
        n/=10;
        if(x==8)
            return true;
    }
    return false;
}

int Mod_Addition ( ll x, ll y) {
    int ans=0;
    while (x < y) {
        if(x+x <=y) {
            ans++;
            x+=x;
        } else {
            x += (y%x);
            ans++;
        }

    }
    cout<<ans<<endl;
}

ll gcd1(ll a, ll b) {
    return b ? gcd1(b, a % b) : a;
}
struct point {
    int d, m, k, sp  ;
    string s ;
};

bool com (point x, point y  ) {
    if (x.d != y.d )
        return x.d > y.d ;
    if (x.m != y . m )
        return x.m > y.m;
    if (x.k != y.k )
        return x.k > y.k ;
    if (x.sp != y.sp)
        return x.sp > y.sp ;
    return x.s < y.s ;
}
int gcd2(int a, int b) {
    for(int i=min(a,b) ; i>=1; i--) {
        if(a%i==0 && b%i==0) {
            cout<<i;
            break;
        }
    }
}
void prefix (int n) {
    int a[n]= {0};
    int p[n]= {0};
    loop(n) {
        cin>>a[i];
        p[i]=p[i-1] + a[i];
    }
    loop(n) {
        cout<< p[i] <<" ";
    }
}
int p (int x, int &y) {

    x++;
    y++;
    return x;
}
bool is_prime(int x) {
    if(x<=1) return 0;
    for(int i=2; i<=sqrt(x); i++) {
        if (x%i==0) {
            return 0;
        }
    }
    return 1;

}
double distance ( int a, int b, int c, int d) {
    int x=a-c;
    int y=b-d;
    return sqrt (x*x + y*y);
}
ll bin_to_des( string s) {
    ll ans=0;
    reverse(s.begin(), s.end());
    loop(s.size()) {
        if(s[i]=='1') {
            ans+=pow(2,i);
        }
    }
    return ans;
}
string des_to_bin(int n) {
    string s;
    /* while(n>0){
     s+=(n%2==0)? '0' : '1';
     n/=2;
    } */
    for(int i=31; i>=0; i--) {
        s+= to_string(isON(n,i));
    }
    return s;
}
bool find_word(string s) {
    string word;
    cin>>word;
    size_t found = s.find (word);
    if (found !=string::npos ) return 1;
    return 0;

}
bool  find_word2( string s, string f) {
    int k=0;
    loop(s.size()) {
        if(k<f.size() && s[i]==f[k]) {
            k++;
        }
    }
    if (k==f.size()) return 1;
    return 0;
}
bool isPalindrome(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        if(s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}
int op(int i, int j) {
    if(i==0 || i==9 || j==0 || j==9) {
        return 1;
    } else if(i==1 || i==8 || j==1 || j==8) {
        return 2;
    } else if(i==2 || i==7 || j==2 || j==7) {
        return 3;
    } else if(i==3 || i==6 || j==3 || j==6) {
        return 4;
    }
    return 5;
}
void solve() {
    ll a,b,c,n=0;
    cin>>a>>b>>c;
    int ans = __gcd(a, __gcd(b,c));
    n+=(a/ans)-1;
    n+=(b/ans)-1;
    n+=(c/ans)-1;
    if (n<=3) {
        cy return;
    }
    cn return;
}
int get_sum(int x ) {
    int res=0;
    while(x) {
        res+=x%10;
        x/=10;
    }
    return res;
}
void modified ( int*a, int n) {
    loop(n) {
        a[i]*=2;
    }
    loop(n) {
        cout<<a[i]<<" ";
    }
}
/*
void prefix_2d(int n, int m){
   int a[n][m];
   int p[n][m]={0};
    loop(n){
    loopp(m){
    cin>>a[i][j];
    if(i==0 && j==0){p[i][j]= a[i][j];}
    else if(i==0 && j!=0){p[i][j]= a[i][j]+p[i][j-1];}
    else if(i!=0 && j==0){p[i][j]= a[i][j]+p[i-1][j];}
    else if(i!=0 && j!=0){p[i][j]= a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];}
    }
    }
    loop(n){
    loopp(m){
     cout<<p[i][j]<<" ";
    }
    cout<<endl;
    }

}
int getRectangleSum( int p[][],&p , int x1, int y1, int x2, int y2){
    x1--; x2--; y1--; y2--;
    int sum = p[x2][y2];
    if (x1 > 0) {
        sum -= prefixSum[x1 - 1][y2];
    }

    if (y1 > 0) {
        sum -= prefixSum[x2][y1 - 1];
    }

    if (x1 > 0 && y1 > 0) {
        sum += prefixSum[x1 - 1][y1 - 1];
    }

    return sum;
}
*/
/*
void prefix_2d(int n, int m){
   int a[n][m];
   int p[n][m]={0};
    loop(n){
    loopp(m){
    cin>>a[i][j];
    if(i==0 && j==0){p[i][j]= a[i][j];}
    else if(i==0 && j!=0){p[i][j]= a[i][j]+p[i][j-1];}
    else if(i!=0 && j==0){p[i][j]= a[i][j]+p[i-1][j];}
    else if(i!=0 && j!=0){p[i][j]= a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];}
    }
    }
    loop(n){
    loopp(m){
     cout<<p[i][j]<<" ";
    }
    cout<<endl;
    }

}
int getRectangleSum( int p[][],&p , int x1, int y1, int x2, int y2){
    x1--; x2--; y1--; y2--;
    int sum = p[x2][y2];
    if (x1 > 0) {
        sum -= prefixSum[x1 - 1][y2];
    }

    if (y1 > 0) {
        sum -= prefixSum[x2][y1 - 1];
    }

    if (x1 > 0 && y1 > 0) {
        sum += prefixSum[x1 - 1][y1 - 1];
    }

    return sum;
}
*/
int findMaxInStack(stack<ll> s) {
    if (s.empty()) {
        return INT_MIN;
    }

    ll topElement = s.top();
    s.pop();
    ll maxInRest = findMaxInStack(s);
    return max(topElement, maxInRest);
}
ll get_sum_m(int i) {
    ll n;
    cin>>n;
    ll a[n];
    if(i==n) return 0;
    return a[i] + get_sum_m(i+1);
}

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
string ask(int x) {
    cout<<x<<'\n';
    cout.flush();
    string res;
    cin>>res;
    return res;
}
int check(int x) {
    int ans=0,w;
    while(true) {
        w=x%10;
        x/=10;
        if(w==0) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}
int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}
void speed_up() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool canMakeZero(int n, vector<int>& arr) {
    if (arr[0] < arr[1] || arr[n - 1] < arr[n - 2]) {
        return false;
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < max(arr[i - 1], arr[i + 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    speed_up();
    string s;
    cin>>s;
    int h=0,ans=0;
    for(auto it:s) {
        if(it=='(') {
            h++;
        } else {
            if(h) {
                h--;
                ans+=2;
            }
        }
    }
    cout<<ans;
    return 0;
}
