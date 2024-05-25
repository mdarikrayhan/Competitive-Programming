#include<iostream>
#include <vector>
#include <deque>
#define int long long
using namespace std;

struct T{
    int num, v, d, p;
    T(int a, int b, int c, int d){
        num = a;
        v = b;
        this->d = c;
        p = d;
    }
};


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    deque <T> v;
    for (int i = 1; i <= n; ++i){
        int V, d, p;
        cin >> V >> d >> p;
        v.push_back(T(i, V, d, p));
    }
    vector <int> ans;
    while (v.size()){
        T cur = v[0];
        ans.push_back(cur.num);
        v.pop_front();
        for (int i = 0; i < min((int)v.size(), cur.v); ++i){
            v[i].p -= cur.v-i;
        }
        for (int i = 0; i < v.size(); ++i){
            if (v[i].p < 0){
                int j = i;
                while (j+1 != v.size()){
                    swap(v[j], v[j+1]);
                    v[j].p -= v[j+1].d;
                    j++;
                }
                v.pop_back();
                i--;
            }
        }
        
    }
    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " ";
    return 0;
}
