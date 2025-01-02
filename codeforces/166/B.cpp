#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF=(ll)1e18+10,M=2e5+137;
struct Pt{
    ll x, y;
    bool a;

    const bool operator < (const Pt &b){
        if(this-> x != b.x)
            return this->x < b.x;
        return this->y < b.y;
    }

    const Pt operator - (const Pt &b){
        return {this->x - b.x, this->y -b.y, 0};
    }
};

ll cross(Pt a, Pt b){
    return a.x*b.y - a.y*b.x;
}
Pt a[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]= {x,y,1};
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[n+i]= {x,y,0};
    }
    
    int k= n+m;
    sort(a,a+k);
    vector<Pt> ch;
    //this code finds ch with collinear points
    //but may contain multiple occurrence of same point in ch
    int sz=0;
    for(int i=0;i<k;i++){
        while(sz>1){
            Pt o= ch[sz-2];
            if(cross(ch[sz-1]-o, a[i]-o) > 0)
                ch.pop_back(), sz--;
            else
                break;
        }
    
        ch.pb(a[i]), sz++;
    }

    int pre=sz;
    //changing i=k-2 generates wrong solution
    for(int i= k-1;i>=0;i--){
        while(sz>pre){
            Pt o= ch[sz-2];
            if(cross(ch[sz-1]-o, a[i]-o) > 0)
                ch.pop_back(), sz--;
            else
                break;
        }

        ch.pb(a[i]), sz++;
    }
    
    bool is=0;
    for(Pt u: ch)
        if(!u.a)
            is=1;

    cout<<(is? "NO": "YES");
}
