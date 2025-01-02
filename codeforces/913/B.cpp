// reBLACKBLACKBLACKBLACKBLACKBLACKB
// redrBLACKBLACKBLACKBLABLACKBLACKB
// redredr      I Stand
// redredred    With
// redredr      Palestine!
// redrGREENGREENGREENGRENGREENGREEN
// reGREENGREENGREENGREENGREENGREENG
#include<bits/stdc++.h>
using namespace std;
#define KYALI ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define all(v) v.begin() , v.end()
#define ull unsigned long long
#define vl vector<ll>
#define int ll
template<typename T>istream& operator>>(istream& is, vector<T>& v) {T value;for (int i = 0; i < v.size(); ++i) {cin>>v[i];}return is;}

void Free_Palestine(){
    int n;
    cin>>n;
    vector< vector<int> >v(n+1);
    for (int i = 1; i < n; ++i) {
        int x;
        cin>>x;
        v[x].push_back(i+1);
    }
    int c=0,f=1;
    for (int i = 1; i <= n; ++i) {
        c=0;
        if (v[i].size()>0){
            for (int j = 0; j < v[i].size(); ++j) {
                if (v[v[i][j]].size()!=0)
                    c++;
            }
            if (v[i].size()-c<3){
                f=0;
                break;
            }
        }
    }
    if (f)
        cout<<"Yes\n";
    else
        cout<<"No\n";

}

signed main() {
//    freopen("", "r", stdin);
//    freopen("", "w", stdout);
    KYALI
    int T = 1;
    //cin >> T;
    while (T--) {
        Free_Palestine();
    }
}
