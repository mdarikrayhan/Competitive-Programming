#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> answer;

int query(int a, int b, int c) {
    //cout << "QUERYING " << a <<" " << b <<" " << c << endl;
    cout << "? " << a+1 <<" " << b+1 <<" " << c+1 << endl;
    int x;
    cin >> x;
    return x;
}
void result(vector<int> v) {
    vector<int> w;
    for (int i=0; i<v.size(); i++) {
        if (v[i]==0) {
            w.push_back(i);
        }
    }
    cout << "! " << w.size();
    for (auto i:w) {
        cout << " " << i+1;
    }
    cout << endl;
}
void solvegroup(int gind, int knownopp, int majval) {
    int a = gind*3;
    int b = gind*3+1;
    int c = gind*3+2;
    int w = query(a,b,knownopp);
    int x = query(a,c,knownopp);
    if (w==majval && x==majval) {
        answer[a] = answer[b] = answer[c] = majval;
        return;
    }
    if (w!=majval && x!=majval) {
        answer[a] = 1-majval;
        answer[b] = answer[c] = majval;
        return;
    }
    answer[a] = majval;
    if (w==majval) {
        answer[b] = majval;
    }
    else {
        answer[b] = 1-majval;
    }
    answer[c] = 1-answer[b];
    return;
    
}

void solveindex(int index, int knownimp, int knowncre) {
    answer[index] = query(index, knownimp, knowncre);
}


void solve() {
    int n;
    cin >> n;
    int k = n/3;
    vector<int> v(k);
    int impv = -1;
    int crev = -1;
    for (int i=0; i<k; i++) {
        //cout << i << endl;
        int a = i*3;
        int b = i*3+1;
        int c = i*3+2;
        v[i] = query(a,b,c);
        if (v[i]==0) {
            impv=i;
        }
        else {
            crev=i;
        }
    }
    assert(impv!=-1 && crev!=-1);
    int a,b,c,d,e,f;
    a=impv*3;
    b=impv*3+1;
    c=impv*3+2;
    d=crev*3;
    e=crev*3+1;
    f=crev*3+2;
    int w = 0;
    int x = query(b,c,d);
    int y = query(c,d,e);
    int z = 1;
    int knowi = -1;
    int knowc = -1;
    if (w==0 && x==1) {
        knowi = a;
        knowc = d;
    }
    if (x==0 && y==1) {
        knowi = b;
        knowc = e;
    }
    if (y==0 && z==1) {
        knowi = c;
        knowc = f;
    }
    assert(knowi!=-1 && knowc!=-1);
    answer = vector<int>(n,-1);
    answer[knowi] = 0;
    answer[knowc] = 1;
    for (int i=0; i<k; i++) {
        if (i!=impv && i!=crev) {
            if (v[i]==0) solvegroup(i, knowc, 0);
            if (v[i]==1) solvegroup(i, knowi, 1);
        }
        else {
            a=i*3;
            b=i*3+1;
            c=i*3+2;
            vector<int> tau = {a,b,c};
            for (auto j:tau) {
                if (j!=knowi && j!=knowc) {
                    solveindex(j,knowi,knowc);
                }
            }
        }
    }
    result(answer);
    
    
    
    

}

signed main() {
    /*#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
    /*#ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif*/ //fast IO
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
}

