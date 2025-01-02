#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define db double
using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << '>' << #x << ':'; _print(x); cerr << endl;
#else
#define debug(x);
#endif
template<typename T>
void _print(const vector<T>& v) {
    cerr << "<";
    for (const auto& elem : v) {
        cerr << elem << " ";
    }
    cerr << ">";
}

template<typename T>
void _print(const T& t) {
    cerr << t;
}
// Syntax to define an ordered_set
/*functions:
order_of_key()
find_by_order()
are provided by the policy based data structure so we dont have to implement binary search ourselves....
*/
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& value) {
    ForwardIterator it;
    typename std::iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first, last);
    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (!(value < *it)) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}
#define ll long long

// Commonly used functions

long long nCr(int n, int r){
    if (r > n - r){
        r = n - r;
    }
    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
// Modular exponentiation
ll modpow(ll base, ll exp, ll modulus) {
    ll result = 1;
    base %= modulus;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

// Greatest Common Divisor (GCD)
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Least Common Multiple (LCM)
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

// Factorial
ll factorial(int n) {
    ll fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Prime checking function
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes for prime number generation
vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

// Graph related functions

// Function to add an edge to the graph
void addEdge(int u, int v,vector<vector<int>> &adj) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph
}

// Depth First Search (DFS)
void dfs(int node, vector<bool>& visited,vector<vector<int>> &adj) {
    visited[node] = true;
    for (int u : adj[node]) {
        if (!visited[u]) {
            dfs(u, visited,adj);
        }
    }
}

// Breadth First Search (BFS)
void bfs(int start,vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // Process node
        for (int u : adj[node]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}


// Binary Search
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Element not found
}
// Function to handle input/output
void solve() {
    int n;
    cin>>n;
    int minl =0,maxr =0,maxn =0,vall =0,valr =0,minval =0;
    for(int i =1;i<= n;i++){
        int l,r,c;
        cin>>l>>r>>c;
        if(i == 1){
            minl =l;
            maxr =r;
            maxn = r - l +1;
            vall= valr =c;
            minval =c;
        }
        else{
            if(l < minl){
                minl = l;
                vall =c;
            }
            else if(l == minl){
                vall = min(vall,c);
            }
            if(r > maxr){
                maxr =r;
                valr =c;
            }
            else if(maxr == r){
                valr = min(valr,c);
            }
            if(r - l + 1 > maxn){
                maxn = r - l +1;
                minval =c;
            }
            else if(r - l +1 == maxn){
                minval =min(minval,c);
            }
        }
        int ans = vall + valr;
        if(maxn == maxr - minl + 1){
            ans =min(ans,minval);
        }
        cout<<ans<<endl;
        
    }
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}