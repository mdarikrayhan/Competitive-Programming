#include <bits/stdc++.h>
#define int long long
using namespace std;

int INF = 1000000007;
int ceil(int x, int y) {
    int t = (y/x)-18;
    while (t*x<y) {
        t++;
    }
    //cout << "CEIL " << x <<" " << y <<" " << t << endl;
    return t;
}
int event(int m, int b) {
    //returns the point at which it reverses
    if (m==0) {
        return INF; //never reverses
    }
    if (m<0) {
        m=-m;
        b=-b;
    }
    return ceil(m,-b);
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<vector<int>> c(n);
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        a[i]=x;
    }
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        b[i]=x;
    }
    for (int i=0; i<n; i++) {
        c[i] = {0,b[i]-a[i]};
    }
    c[0] = {1,-a[0]};
    vector<vector<int>> exp;
    for (int i=0; i<n; i++) {
        vector<int> cur = c[i];
        exp.push_back(cur);
        //cout << i << " " << cur[0] <<" " << cur[1] << endl;
        for (int j=i; j<n; j+=i+1) {
            c[j][0]-=cur[0];
            c[j][1]-=cur[1];
        }
    }
    vector<vector<int>> exp2;
    for (int i=0; i<n; i++) {
        vector<int> cur = exp[i];
        if (cur[0]>0 || (cur[0]==0 && cur[1]<0)) {
            cur[0] = -cur[0];
            cur[1] = -cur[1];
            //the value should be positive at -INF
        }
        exp2.push_back({cur[0],cur[1],event(cur[0],cur[1])});
    }
    sort(exp2.begin(), exp2.end(), [&](const vector<int> v1, const vector<int> v2) {
        return v1[2]<v2[2];
    });
    int pointer = 0;
    vector<pair<int,int>> qu;
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int x;
        cin >> x;
        qu.push_back({x,i});
    }
    sort(qu.begin(), qu.end());
    vector<int> answers(q,-1);
    int m = 0;
    int bv = 0;
    for (int i=0; i<n; i++) {
        m+=exp2[i][0];
        bv+=exp2[i][1];
    }
    for (int i=0; i<n; i++) {
        //cout << i <<" " << exp2[i][0] <<" " << exp2[i][1] << " " << exp2[i][2] << endl;
    }

    for (int i=0; i<q; i++) {
        int x = qu[i].first;
        while (pointer<n && x>exp2[pointer][2]) {
            m -= 2*exp2[pointer][0];
            bv -= 2*exp2[pointer][1];
            pointer++;
        }
        //cout << "iteration " << i <<" " << x <<" " << pointer <<" " << m <<" " << bv << endl;
        answers[qu[i].second] = m*x+bv;
    }
    for (int i=0; i<q; i++) {
        cout << answers[i] <<endl;
    }

}

