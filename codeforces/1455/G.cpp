#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const LL INF = 1e18;
struct Node{
    LL add = 0;
    map<int, LL> mp;
    multiset<LL> s;

    void set(int x, LL y){
        if (mp.contains(x)){
            s.erase(s.find(mp[x]));
        }
        mp[x] = y - add;
        s.insert(mp[x]);
    }

    void add_all(LL x){
        add += x;
    }

    LL get(int x){
        if (!mp.contains(x)) return INF;
        return mp[x] + add;
    }

    LL get_mn(){
        return *s.begin() + add;
    }

    void del(int x){
        if (mp.contains(x)){
            s.erase(s.find(mp[x]));
            mp.erase(x);
        }
    }

    void merge(Node &t){
        if (mp.size() < t.mp.size()) swap(*this, t);
        for(auto [x, y] : t.mp){
            if (get(x) > y + t.add){
                set(x, y + t.add);
            }
        }
    }

};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, s;
    cin >> n >> s;
    vector<Node> stk;
    stk.push_back({});
    stk.back().set(0, 0);
    while(n--){
        string op;
        cin >> op;
        if (op == "set"){
            int v, c;
            cin >> v >> c;
            LL mn = stk.back().get_mn();
            stk.back().add_all(c);
            if (v != s) stk.back().set(v, mn);
        }
        else if (op == "if"){
            int x;
            cin >> x;
            LL cost = stk.back().get(x);
            stk.back().del(x);
            stk.push_back({});
            stk.back().set(x, cost);
        }
        else{
            stk[stk.size() - 2].merge(stk.back());
            stk.pop_back();
        }
    }
    cout << stk.back().get_mn() << '\n';

}