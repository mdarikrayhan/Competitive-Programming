#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll N,A[202020][4],R[202020];
ll RS;
ll S;

ll P[(1<<21)+10];  // Px+Q
ll Q[(1<<21)+10];
ll V[(1<<21)+10][16];
ll Lma[101010],Rma[101010];


int ok(int x,int cur,int add) {
	ll ma=1LL<<60;
	int mask,i;
	
	if(cur&&Lma[cur-1]>x) return 0;
	if(cur<N-1&&Rma[cur+1]>x) return 0;
	
	FOR(mask,1<<4) {
		ll cut=V[x][mask];
		ll sum=0;
		FOR(i,4) {
			if(mask&(1<<i)) {
				cut+=A[N][i];
			}
			else {
				sum+=max(0LL,x-A[cur][i]);
			}
		}
		//cout<<"aa"<<mask<<" "<<cur<<" "<<cut<<" "<<sum<<" "<<R[cur]<<endl;
		cut-=min(sum,R[cur]+add);
		ma=min(ma,cut);
	}
	
	//cout<<x<<" "<<cur<<" "<<ma<<" "<<RS-(R[cur]+add)<<endl;
	
	return (ma>=RS-(R[cur]+add));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	cin>>N;
	FOR(i,N+1) {
		FOR(j,4) {
			cin>>A[i][j];
			S+=A[i][j];
			Lma[i]=max(Lma[i],A[i][j]);
		}
		Lma[i+1]=Lma[i];
		
	}
	for(i=N-1;i>=0;i--) {
		Rma[i]=Rma[i+1];
		FOR(j,4) Rma[i]=max(Rma[i],A[i][j]);
	}
	
	FOR(i,N) {
		int a=S/N;
		FOR(j,4) a-=A[i][j];
		R[i]=a;
		RS+=a;
	}
	
	
	FOR(mask,16) {
		ZERO(P);
		ZERO(Q);
		FOR(i,N) {
			vector<int> V;
			FOR(j,4) if((mask&(1<<j))==0) V.push_back(A[i][j]);
			sort(ALL(V));
			V.push_back(1<<21);
			ll cur=0;
			FOR(j,V.size()-1) {
				ll nex=cur+1LL*(j+1)*(V[j+1]-V[j]);
				P[V[j]]+=j+1;
				Q[V[j]]+=cur-1LL*(j+1)*V[j];
				if(nex<=R[i]) {
					P[V[j+1]]-=j+1;
					Q[V[j+1]]-=cur-1LL*(j+1)*V[j];
					cur=nex;
				}
				else {
					ll over=(R[i]-cur+j)/(j+1)+V[j];
					P[over]-=j+1;
					Q[over]-=cur-1LL*(j+1)*V[j];
					Q[over]+=R[i];
					break;
				}
			}
			
		}
		for(i=0;i<=1<<21;i++) {
			if(i) {
				P[i]+=P[i-1];
				Q[i]+=Q[i-1];
			}
			V[i][mask]=P[i]*i+Q[i];
		}
	}
	
	FOR(i,N) {
		ll ret=0;
		FOR(j,4) {
			int add=min(R[i],A[N][j]);
			A[N][j]-=add;
			R[i]-=add;
			
			int cur=(1<<21)-1;
			for(k=20;k>=0;k--) if(ok(cur-(1<<k),i,add)) cur-=1<<k;
			//cout<<i<<" "<<j<<" "<<cur<<" "<<A[i][j]+add<<" "<<A[i][j]<<" "<<add<<endl;
			ret=max(ret,A[i][j]+add-cur);
			R[i]+=add;
			A[N][j]+=add;
		}
		cout<<ret<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
