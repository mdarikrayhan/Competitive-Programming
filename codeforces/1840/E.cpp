#include <bits/stdc++.h>
#define ll long long int
#define si set<long long int>
#define vi vector<long long int>
#define pii pair<long long int, long long int>
#define mii map<long long int, long long int>
#define M 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int i, j;
    cin >> t;
    while(t--){
        string a,s;
        cin >> a >> s;
        int n = a.size();
        vi diff(n);
        mii block;
        ll c=0;
        for(i=0;i<n;i++){
            if(a[i]!=s[i]){
                c++;
                diff[i]=1;
            }
        }
        ll t,q;
        cin >> t >> q;
        for(i=0 ; i<q ; i++){
            if(block[i]==1){
                c++;
            }
            ll type;
            cin >> type;
            if(type==1){
                ll pos;
                cin >> pos;
                pos--;
                if(diff[pos]==1){
                    c--;
                    block[i+t]=1;
                }
            }
            else if(type==2){
                ll x, y, pos1, pos2;
                cin >> x >> pos1 >> y >> pos2;
                pos1--; pos2--;
                if(diff[pos1]==1){
                    diff[pos1]=0;
                    c--;
                }
                if(pos1!=pos2 && diff[pos2]==1){
                    diff[pos2]=0;
                    c--;
                }
                if(x==1 && y==1){
                    swap(a[pos1],a[pos2]);
                }
                else if(x==1 && y==2){
                    swap(a[pos1],s[pos2]);
                }
                else if(x==2 && y==1){
                    swap(a[pos2],s[pos1]);
                }
                else if(x==2 && y==2){
                    swap(s[pos2],s[pos1]);
                }
                if(a[pos1]!=s[pos1]){
                    diff[pos1]=1;
                    c++;
                }
                if(pos1!=pos2 && a[pos2]!=s[pos2]){
                    diff[pos2]=1;
                    c++;
                }
            }
            else{
                cout << ((c==0) ? "YES\n" : "NO\n");
            }
            // for(auto it : diff){
            //     cout << it << " ";
            // }
            // cout << c << "\n";
            // for(auto it : block){
            //     cout << it << " ";
            // }
            // cout << "\n\n";
        }
    }
    return 0;
}