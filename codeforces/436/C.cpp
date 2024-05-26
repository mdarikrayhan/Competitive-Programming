#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define pb push_back
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define go(a,x) for(auto &a:x)
#define inn(a) go(x,a)cin>>x
#define print(v) go(x,v){cout<<x<<" ";}cout<<endl;
// const ll inf=9223372036854775807;
void yes(){cout <<"YES"<<endl;}
void no(){cout <<"NO"<<endl;}
void ne(){cout <<-1<<endl;}
#define yn(a) cout<<((a)?"YES\n":"NO\n")
typedef pair<ll, ll> pii;
using pq = priority_queue<ll>;
using vi = vector<ll>;
using vii = vector<pair<ll,ll>>;
using mii = map<ll,ll>;
using umii = unordered_map<ll,ll>;
using si = set<ll>;
using usi = unordered_set<ll>;
using msi = multiset<ll>;
ll n,m,k,w;
ll v[1000][10][10];
ll rrr(ll x,ll y){
        ll ans=0;
        fr(i,0,n){
            fr(j,0,m){
                if(v[x][i][j]!=v[y][i][j])ans++;
            }
        }
        return ans*w;
}
//initialize vectors
vi parent;
vi set_size;
void make(ll v)
{
    parent[v] = v;
    set_size[v] = 1;
}

ll find_par(ll v)
{
    if(parent[v] == v) return v;
    else return parent[v] = find_par(parent[v]);
}

void union_set(ll a, ll b)
{
    a = find_par(a);
    b = find_par(b);
    if(a!=b)
    {
        if(set_size[a] < set_size[b]) swap(a,b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}


void solve(){
      cin>>n>>m>>k>>w;
      fr(a,0,k){
        fr(b,0,n){
            fr(c,0,m){
                char d;cin>>d;
                v[a][b][c]=int(d);
            }
        }
      }
    //creating a vector to store the edges and weights in the form 
    //weight,{node1,node2}
    vector<pair<pair<ll,ll>,ll>>edges;
    fr(i,0,k){
        fr(j,i+1,k){
            edges.push_back({{i,j},rrr(i,j)});
        }
    }
    sort(edges.begin(),edges.end(),[](auto left, auto right){
        return left.second<right.second;
    });
    parent.assign(k,-1);
    set_size.assign(k,0);
    for(ll i=0;i<k;i++){
        make(i);
    }
    ll ans=0;
    vector<ll> g[k];
    for(auto x:edges){
        ll weight=x.second;
        ll a=(x.first).first;
        ll b=(x.first).second;
        if(find_par(a)!=find_par(b)){
            if(weight<n*m){
            union_set(a,b);
            g[a].pb(b);
            g[b].pb(a);
            ans+=weight;
            }
        }     
    }
    si s;
    vector<ll> vis(k,0);
    fr(i,0,k){
        s.insert(find_par(i));
    }
    ans+=int(s.size())*n*m;

    cout<<ans<<endl;
    
    go(x,s){
        stack<ll>sk;
        cout<<x+1<<" "<<0<<endl;
        vis[x]=1;
        sk.push(x);
        while(!sk.empty()){
            ll y=sk.top();
            sk.pop();
            // cout<<"y "<<y<<endl;
            // print(g[y]);
            go(z,g[y]){
                if(!vis[z]){
                    vis[z]=1;
                    cout<<z+1<<" "<<y+1<<endl;
                    sk.push(z);
                }
            }
        }

    }


}

int main(){
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
ios::sync_with_stdio(0); cin.tie(0);
  ll tt=1;

   // cin>>tt;

  while(tt--){
     solve();
  }
     
return 0;
}