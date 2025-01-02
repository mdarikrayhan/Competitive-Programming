#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
struct node {
   int mx,sz;bool bg;
   pair<int,int> mn;
   vector<node*> cp;
   void cln(){for(node* i:cp)i->cp.erase(find(i->cp.begin(),i->cp.end(),this));cp.clear();}
   void fresh() {
      if(!bg) return;
      bg=false;int sum=0;node* lt=nullptr;
      for(node* i:cp)if(i->bg){lt=i;sum++;}
      if(sum==1){lt->mx=lt->sz;lt->bg=false;lt->cln();}
   }
   ~node(){cln();}
};
int prevAns;
pair<int,int> fa[1002][1002];
pair<int,int> getfa(pair<int,int> x) {
   if(fa[x.first][x.second]==x) return x;
   return fa[x.first][x.second]=getfa(fa[x.first][x.second]);
}
void merge(pair<int,int> x,pair<int,int> y) {
   pair<int,int> t=getfa(x);
   fa[t.first][t.second]=getfa(y);
}

int n,q;
node* bk[1002][1002];
bool vis[1002][1002];
vector<pair<int,int>> dxy={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}},xy={{-1,0},{0,1},{1,0},{0,-1}};
void Delta() {
   cin >> n >> q;
   bk[1][1]=new node{n*n,n*n,false,{0,0},{}};
   for(int i=0;i<=n+1;++i)
      for(int j=0;j<=n+1;++j) {
         fa[i][j]={i,j};
         if(i==0||j==0||i==n+1||j==n+1) {
            fa[i][j]={0,0};
            vis[i][j]=true;
            bk[i][j]=nullptr;
         } else {
            bk[i][j]=bk[1][1];
            vis[i][j]=false;
         }
      }
   prevAns=0;
   while(q--) {
      int x,y,cnt=1;cin >> x >> y;
      x^=prevAns;
      y^=prevAns;
      pair<int,int> Q[8];
      int P[4]={0,0,0,0};
      for(int i=0;i<8;++i)
         Q[i]=getfa({x+dxy[i].first,y+dxy[i].second});
      for(int i=0;i<8;++i)
         for(int j=1;j<8;++j)
            if(Q[i]==Q[(i+j)%8]) {
               cnt++;
               for(int k=(i+1)%8;k!=(i+j)%8;k=(k+1)%8)
                  if(k%2==1)
                     P[k/2]+=1ll<<cnt;
               break;
            }
      vis[x][y]=true;
      for(pair<int,int> i:dxy)
         if(vis[x+i.first][y+i.second])
            merge({x,y},{x+i.first,y+i.second});
      bk[x][y]->fresh();
      if((P[0]&P[1]&P[2]&P[3])==max({P[0],P[1],P[2],P[3]})) {
         prevAns=bk[x][y]->mx;
         cout << prevAns << ' ';
         bk[x][y]->mx--;bk[x][y]->sz--;
         for(node* i:bk[x][y]->cp) i->mx--;
         if(bk[x][y]->sz==0) delete bk[x][y];
      } else {
         vector<pair<int,int>> s[4];
         queue<pair<int,int>> q[4];
         pair<int,int> id[4];
         int cnt,dc=0;
         {
            vector<int> R;
            for(int i=0;i<4;++i) R.push_back(P[i]);
            sort(R.begin(),R.end());
            R.resize(unique(R.begin(),R.end())-R.begin());
            cnt=R.size();
            for(int i=0;i<4;++i)
               P[i]=lower_bound(R.begin(),R.end(),P[i])-R.begin();
         }
         for(int i=0;i<cnt;++i) {
            for(int j=0;j<4;++j)
               if(P[j]==i&&!vis[x+xy[j].first][y+xy[j].second]) {
                  id[i]={x+xy[j].first,y+xy[j].second};
                  if(!vis[id[i].first][id[i].second]) {
                     q[i].push(id[i]);
                     s[i].push_back(id[i]);
                     vis[id[i].first][id[i].second]=true;
                     dc++;
                  }
                  break;
               }
         }
         while(dc>1)
            for(int i=0;i<4;++i)
               if(q[i].size()!=0) {
                  pair<int,int> t=q[i].front();q[i].pop();
                  for(int j=0;j<4;++j) {
                     pair<int,int> p={t.first+xy[j].first,t.second+xy[j].second};
                     if(!vis[p.first][p.second]) {
                        q[i].push(p);s[i].push_back(p);
                        vis[p.first][p.second]=true;
                     }
                  }
                  if(q[i].empty()) --dc;
               }
         vector<int> sm,bg;node* tp[4];
         if(bk[x][y]->mx==bk[x][y]->sz) {
            if(dc==1) {
               for(int i=0;i<4;++i)
                  if(!q[i].empty()) bg.push_back(i);
                  else if(!s[i].empty()) sm.push_back(i);
               for(int i:sm) {
                  tp[i]=new node{bk[x][y]->mx,(int)s[i].size(),false,{x,y},{}};
                  for(pair<int,int> j:s[i])
                     bk[j.first][j.second]=tp[i];
               }
               for(int i:sm) {
                  for(int j:sm)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
                  bk[x][y]->sz-=s[i].size();
               }
               prevAns=bk[x][y]->sz;
               cout<< prevAns << ' ';
               bk[x][y]->sz--;bk[x][y]->mx=bk[x][y]->sz;
            } else {
               int mxz=0;
               for(int i=0;i<4;++i)
                  if(!s[i].empty()) {
                     sm.push_back(i);
                     mxz=max(mxz,(int)s[i].size());
                  }
               prevAns=mxz+1;
               cout << prevAns << ' ';
               for(int i:sm) {
                  tp[i]=new node{bk[x][y]->mx,(int)s[i].size(),(int)s[i].size()==mxz,{x,y},{}};
                  for(pair<int,int> j:s[i])
                     bk[j.first][j.second]=tp[i];
               }
               for(int i:sm)
                  for(int j:sm)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
               delete bk[x][y];
            }
         } else {
            vector<node*> ar;vector<int> lt,ult;
            if(dc==1) {
               int sult=1,ty=bk[x][y]->mx;
               pair<int,int> pmn=bk[x][y]->mn;
               bk[x][y]->mn={x,y};bk[x][y]->sz--;
               for(int i=0;i<4;++i)
                  if(!s[i].empty()) {
                     if(!q[i].empty()) {
                        bg.push_back(i);
                        tp[i]=bk[x][y];
                     }
                     else {
                        tp[i]=new node{bk[x][y]->mx,(int)s[i].size(),false,{x,y},{}};
                        sm.push_back(i);
                        bk[x][y]->sz-=(int)s[i].size();
                        for(pair<int,int> j:s[i])
                           bk[j.first][j.second]=tp[i];
                     }
                  }
               pair<int,int> tmp=pmn;
               for(pair<int,int> i:xy) {
                  node* t=bk[i.first+tmp.first][i.second+tmp.second];
                  if(t!=nullptr&&pair<int,int>{i.first+tmp.first,i.second+tmp.second}!=pair<int,int>{x,y}) {
                     ar.push_back(t);
                  }
               }
               vector<node*> cp=bk[x][y]->cp;
               for(node* i:cp) i->cp.erase(find(i->cp.begin(),i->cp.end(),bk[x][y]));
               bk[x][y]->cp.clear();
               for(int i=0;i<4;++i) {
                  if(!s[i].empty()) {
                     if(id[i]==tmp||find(ar.begin(),ar.end(),bk[id[i].first][id[i].second])!=ar.end()) {
                        tp[i]->mn=pmn;
                        lt.push_back(i);
                     } else {
                        ult.push_back(i);
                        sult+=tp[i]->sz;
                     }
                  }
               }
               for(int i:ult)
                  for(int j:ult)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
               for(node* i:cp) {
                  for(int j:lt) {
                     i->cp.push_back(tp[j]);
                     tp[j]->cp.push_back(i);
                  }
                  i->mx-=sult;
               }
               prevAns=ty-sult+1;
               cout << prevAns << ' ';
               for(int i:lt) {
                  for(int j:lt)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
                  tp[i]->mx-=sult;
               }
            } else {
               pair<int,int> pmn=bk[x][y]->mn;
               int sult=1;
               for(int i=0;i<4;++i)
                  if(!s[i].empty()) {
                     tp[i]=new node{bk[x][y]->mx,(int)s[i].size(),false,{x,y},{}};
                     for(pair<int,int> j:s[i])
                        bk[j.first][j.second]=tp[i];
                  }
               pair<int,int> tmp=bk[x][y]->mn;
               for(pair<int,int> i:xy) {
                  node* t=bk[i.first+tmp.first][i.second+tmp.second];
                  if(t!=nullptr&&pair<int,int>{i.first+tmp.first,i.second+tmp.second}!=pair<int,int>{x,y})
                     ar.push_back(t);
               }
               for(int i=0;i<4;++i)
                  if(!s[i].empty()) {
                     if(id[i]==tmp||find(ar.begin(),ar.end(),bk[id[i].first][id[i].second])!=ar.end()) {
                        tp[i]->mn=pmn;
                        lt.push_back(i);
                     } else {
                        ult.push_back(i);
                        sult+=(int)s[i].size();
                     }
                  }
               for(int i:ult)
                  for(int j:ult)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
               for(node* i:bk[x][y]->cp) {
                  for(int j:lt) {
                     i->cp.push_back(tp[j]);
                     tp[j]->cp.push_back(i);
                  }
                  i->mx-=sult;
               }
               for(int i:lt) {
                  for(int j:lt)
                     if(i!=j) tp[i]->cp.push_back(tp[j]);
                  tp[i]->mx-=sult;
               }
               prevAns=bk[x][y]->mx-sult+1;
               cout << prevAns << ' ';
               delete bk[x][y];
            }
         }
         for(int i=0;i<4;++i)
            for(pair<int,int> j:s[i])
               vis[j.first][j.second]=false;
      }
      bk[x][y]=nullptr;
   }
   set<node*> _;
   for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
         _.insert(bk[i][j]);
   for(node* i:_)
      if(i!=nullptr) delete i;
   cout << endl;
}
signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   int T;cin >> T;
   while(T--) Delta();
}