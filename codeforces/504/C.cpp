#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V w){writer(x,' ');writer(y,' ');writer(z,' ');writer(w,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

#define MD 1000000007

int N;
int A[200000];
int cnt[200000];

int need[200000], dame;

ll solve(void){
  int i, j, k, x, y;
  int odd = 0;
  int a, b, c, d;
  int a1, a2, b1, b2;
  ll res;

  rep(i,N) A[i]--;
  rep(i,N) cnt[i] = 0;
  rep(i,N) cnt[A[i]]++;
  rep(i,N) odd += cnt[i] % 2;
  if(odd > 1) return 0;
  if(N%2==0 && odd) return 0;

  res = (ll)N * (N+1) / 2;
  rep(i,N) if(A[i] != A[N-1-i]) break;
  if(i==N) return res;

  a = c = N;
  b = d = -1;
  
  if(N%2==0){
    rep(i,N/2){
      if(A[N/2+i] == A[N/2-1-i]) continue;
      a = min(a, N/2-1-i);
      b = max(b, N/2-1-i);
      c = min(c, N/2+i);
      d = max(d, N/2+i);
    }
  } else {
    rep(i,N) if(cnt[i]%2) odd = i;
    rep(i,N/2+1){
      if(A[N/2+i] == A[N/2-i] && i) continue;
      if(i==0 && odd == A[N/2]) continue;
      a = min(a, N/2-i);
      b = max(b, N/2-i);
      c = min(c, N/2+i);
      d = max(d, N/2+i);
    }
  }

  dame = 0;
  rep(i,N) need[i] = 0;
  for(i=a;i<N;i++){
    x = A[i];
    y = A[N-1-i];
    if(i!=N-1-i){
      if(i<N-1-i){ need[y]++; if(need[y]>0) dame++; }
      else if(i<=d){ if(need[x]>0) dame--; need[x]--; }
      if(need[x]>0) dame--; need[x]--;
    } else {
      need[odd]++; if(need[odd]>0) dame++;
      if(need[x]>0) dame--; need[x]--;
    }

    if(i >= b && dame==0){
      a1 = a; b1 = i;
      break;
    }
  }

  dame = 0;
  rep(i,N) need[i] = 0;
  for(i=d;;i--){
    x = A[i];
    y = A[N-1-i];
    if(i!=N-1-i){
      if(i>N-1-i)  { need[y]++; if(need[y]>0) dame++; }
      else if(i>=a){ if(need[x]>0) dame--; need[x]--; }
      if(need[x]>0) dame--; need[x]--;
    } else {
      need[odd]++; if(need[odd]>0) dame++;
      if(need[x]>0) dame--; need[x]--;
    }

    if(i <= c && dame==0){
      a2 = i; b2 = d;
      break;
    }
  }
  
  res = 0;
  res += (ll)(a1+1) * (N-b1);
  res += (ll)(a2+1) * (N-b2);
  a1 = min(a1, a2);
  b1 = max(b1, b2);
  res -= (ll)(a1+1) * (N-b1);

  return res;
}

ll brute(void){
  int i, j, k, a, b;
  int arr[100];
  int res = 0;

  rep(a,N) REP(b,a,N){
    rep(i,N) arr[i] = A[i];
    sort(arr+a, arr+b+1);
    do{
      rep(i,N) if(arr[i] != arr[N-1-i]) break;
      if(i==N){ res++; break; }
    }while(next_permutation(arr+a,arr+b+1));
  }

  return res;
}

int main(){
  int i;
  ll res, buf;

  reader(&N);
  rep(i,N) reader(A+i);

  res = solve();
  writerLn(res);

  myed;
  return 0;
}
