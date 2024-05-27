#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve() {
    int n;
    cin >> n; 
    vector<int> v;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    if (n==1) {
        cout << 1 << endl;
        cout <<1<<endl;
        return;
    }
    vector<int> psum;
    int p=0;
    psum.push_back(p);
    vector<int> ordering;
    for (int it=0; it<n; it++) {
        int nex = n-p;
        int nval = v[nex-1];
        ordering.push_back(nex-1);
        p+=nval;
        psum.push_back(p);
    }
    vector<int> visited(n,-1);
    int worked=0;
    for (int i=0; i<=n; i++) {
        if (visited[psum[i]]!=-1) {
            worked=1;
            cout << i-visited[psum[i]] << endl;
            for (int j=visited[psum[i]]; j<i; j++) {
                cout << ordering[j]+1 <<" ";
            }
            cout << endl;
            break;
        }
        visited[psum[i]] = i;
    }
    if (!worked) assert(false);
}

signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif //fast IO
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
}

