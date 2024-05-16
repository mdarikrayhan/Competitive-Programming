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






void solve()
{


string s;
cin>>s;
int q;
cin>>q;




int n=s.size();


vector<int>pre(n,-1);


stack<int>st;

for(int i=0;i<n;i++){
    if(s[i]=='('){
        st.push(i);
    }
    else{
        if(st.size()){
            pre[i]=st.top();
            st.pop();
        }
    }
}


ordered_set stt;

vector<vector<int>>v;

vector<int>ans(q);

int j=0;
for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    v.push_back({r,l,j});
    j++;
}

sort(v.begin(),v.end());


j=0;

for(int i=0;i<n;i++){

    if(pre[i]!=-1)stt.insert(pre[i]);
    
   

    while(j<q and v[j][0]==i){
        int x=v[j][1];
        x=stt.size()-stt.order_of_key(x);
        // see(x);
        ans[v[j][2]]=2*x;
        j++;
    }    

}


// see(ans);
for(int i:ans)cout<<i<<endl;


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
