#include <bits/stdc++.h>
#include <typeinfo>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long 

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;


#define see(x) printDebug(#x, x);

template<typename T>
void printDebug(const char* name, const T& value) {
    cout << name << " (" << typeid(value).name() << ") => " << value << endl;
}

void printDebug(const char* name, const string& value) {
    cout << name << " (string) => \"" << value << "\"" << endl;
}

template<typename T>
void printDebug(const char* name, const vector<T>& value) {
    cout << name << " (vector) => [";
    for(size_t i = 0; i < value.size(); ++i) {
        cout << value[i];
        if(i != value.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template<typename T>
void printDebug(const char* name, const set<T>& value) {
    cout << name << " (set) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << *it;
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename T>
void printDebug(const char* name, const multiset<T>& value) {
    cout << name << " (multiset) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << *it;
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename K, typename V>
void printDebug(const char* name, const map<K, V>& value) {
    cout << name << " (map) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << "{" << it->first << ", " << it->second << "}";
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename K, typename V>
void printDebug(const char* name, const multimap<K, V>& value) {
    cout << name << " (multimap) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << "{" << it->first << ", " << it->second << "}";
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename K, typename V>
void printDebug(const char* name, const unordered_map<K, V>& value) {
    cout << name << " (unordered_map) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << "{" << it->first << ", " << it->second << "}";
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename K, typename V>
void printDebug(const char* name, const unordered_multimap<K, V>& value) {
    cout << name << " (unordered_multimap) => {";
    auto it = value.begin();
    while(it != value.end()) {
        cout << "{" << it->first << ", " << it->second << "}";
        ++it;
        if(it != value.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename T>
void printDebug(const char* name, const queue<T>& value) {
    cout << name << " (queue) => {";
    queue<T> temp = value;
    while(!temp.empty()) {
        cout << temp.front();
        temp.pop();
        if(!temp.empty()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template<typename T>
void printDebug(const char* name, const stack<T>& value) {
    cout << name << " (stack) => {";
    stack<T> temp = value;
    while(!temp.empty()) {
        cout << temp.top();
        temp.pop();
        if(!temp.empty()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}


/*
Write logic here













*/

// Calculates the binomial coefficient nCr using the logarithmic formula
int nCr(int n, int r) {
    // If r is greater than n, return 0
    if (r > n) return 0;
    // If r is 0 or equal to n, return 1
    if (r == 0 || n == r) return 1;
    // Initialize the logarithmic sum to 0
    double res = 0;
    // Calculate the logarithmic sum of the numerator and denominator using loop
    for (int i = 0; i < r; i++) {
        // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
        res += log(n-i) - log(i+1);
    }
    // Convert logarithmic sum back to a normal number
    return (int)round(exp(res));
}


void solve()
{


int n;
cin>>n;

int x=nCr(5+n-1,n-1);
int y=nCr(3+n-1,n-1);

cout<<x*y<<endl;



}


signed main()
{
    fastio;
    int t;
    // cin >> t;
    t=1;
    
    while(t--)
    {
        solve();
    }
    return 0;
}
