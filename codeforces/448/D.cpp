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



n m 
2
2


   1 2 
1 
2 


will x be the kth smallest 

yes 
no 



yes if min(x/1,n)+x/2+x/3+....x/n => k







25*10^10


*/

bool ok(int n,int m,int mid,int k){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=min(m,mid/i);
    }
    return cnt>=k;
}
void solve()
{

int n,m,k;
cin>>n>>m>>k;
int lo=1;
int high=1e13;


int ans;


while(lo<=high){
    int mid=(lo+(high-lo)/2ll);
    if(ok(n,m,mid,k)){
        ans=mid;
        high=mid-1;
    }
    else{
        lo=mid+1;
    }
}

cout<<ans<<endl;




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
