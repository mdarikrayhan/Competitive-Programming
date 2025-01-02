#include <bits/stdc++.h>
#define ll long long
#define vi vector <long long int>
#define pb push_back
#define mp make_pair
#define fo(i,a,b) for (long long int i = a; i < b; i++)
#define MAX 998244353
#define ma 1000000007
#define bi 1e18
#define sm -1000000
using namespace std;
    // ll int vis[100000];
    // ll int tot[100000];
    // vector<pair<ll int,ll int>> list[100000];
// bool compare(const pair<int, int>&i, const pair<int, int>&j) 
// {
//     if(i.first==j.first) return i.second>j.second;
//     return i.first < j.first; 
// }
ll int in;
ll int gcdExtended(ll int a,ll int b,ll int* x,ll int* y);
 


// Function to find modulo inverse of a
ll int modInverse(ll int A, ll int M)
{
    ll int x, y;
    ll int g = gcdExtended(A, M, &x, &y);
   
 
        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
   
}
 
// Function for extended Euclidean Algorithm
ll int gcdExtended(ll int a,ll int b,ll int* x,ll int* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    ll int x1, y1;
    ll int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
ll int expo(ll int a,ll int b){
  if(a==0) return 0;
  if(b==0) return 1;
  if(b==1) return a;
  ll int x=expo(a,b/2);
  x=x*x;
  x%=MAX;
  if(b%2) return ((a*x)%MAX);
  return x;
}
ll int dfs(ll int a,ll int vis[],ll int tot[],vector<pair<ll int,ll int>>list[]){
  vis[a]=1;
  ll int x,y,z=0,cu;
  tot[a]=0;
  fo(i,0,list[a].size()){
    x=list[a][i].first;
    y=list[a][i].second;
    if(vis[list[a][i].first]){
      continue;
    }
    cu=dfs(x,vis,tot,list);
    if(tot[x]+y-cu>z) z=tot[x]+y-cu;
    tot[a]+=tot[x]+2*y;
  }
  return tot[a]-z;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n,x,t,a,b,c,d,m,flag,k,y,sum,mid,g,q,z;
    // cin>>t;
    t=1;
    // vector<ll int> list[300];
    ll int arr[100][100];
    ll int tot[100000];
    // vector<pair<ll int,ll int>> list[100000];
    string str,st;
    vi v,ve,va,vb,vc,av,bv,cv;
    fo(i,0,t){
      cin>>n>>m;
      if(n==1&&m==1){
        cout<<1;
        continue;
      }
      if(m+n<=4){
                cout<<-1;
        continue;
      }
      if(n==2&&m==3){
        cout<<"1 5 3 \n4 2 6 \n";
        continue;
      }
      if(n==1&&m==4){
        cout<<"3 1 4 2";
        continue;
      }
            if(m==1&&n==4){
        cout<<"3 \n1 \n4 \n2 \n";
        continue;
      }
      fo(j,0,n*m) arr[j/m][j%m]=0;
      arr[0][0]=1;
      x=2;
      a=1;
      if(m==3) a=2;
      while(x<=n*m){
        b=a/m;
        c=a%m;
        flag=0;
        if(!arr[b][c]){
          if(b>0){
            if(arr[b-1][c]==x-1) flag=1;
          }
          if(b<n-1){
            if(arr[b+1][c]==x-1) flag=1;
          }
          if(c>0){
            if(arr[b][c-1]==x-1) flag=1;
          }
          if(c<m-1){
            if(arr[b][c+1]==x-1) flag=1;
          }
        }
        else flag=1;
        a++;
        if(m==3){
          a++;
          if(a==n*m) a++;
        }
        a%=m*n;
        if(!flag){
          arr[b][c]=x;
          x++;
        }
      }
      fo(j,0,n){
        fo(k,0,m) cout<<arr[j][k]<<" ";
        cout<<endl;
      }


    }
    return 0;
}