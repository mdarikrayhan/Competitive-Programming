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

int T;
int N;
ll X[3030],Y[3030];
int O[3030],pos[3030];

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 1<<20;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<12> st;

bool cmp(pair<pair<int,int>,int> L,pair<pair<int,int>,int> R) {
	return 1LL*L.first.first*R.first.second<1LL*R.first.first*L.first.second;
}

int CX,CY;
bool cmp2(int L,int R) {
	ll a=1LL*CX*X[L]+1LL*CY*Y[L];
	ll b=1LL*CX*X[R]+1LL*CY*Y[R];
	if(a<b) return 1;
	if(a>b) return 0;
	return L<R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(r,T) {
		cin>>N;
		j=0;
		k=N;
		FOR(i,2*N) {
			st.update(i,i+1,-st.getval(i,i+1));
			cin>>x>>y>>s;
			if(s=="(") {
				X[j]=x;
				Y[j]=y;
				j++;
			}
			else {
				X[k]=x;
				Y[k]=y;
				k++;
			}
		}
		/*
		if(T==100) {
			if(r==2) {
				cout<<N<<endl;
				FOR(i,2*N) cout<<X[i]<<" "<<Y[i]<<endl;
			}
			continue;
		}
		*/
		
		vector<pair<ll,int>> V;
		FOR(i,2*N) V.push_back({(X[i]<<20)+Y[i],i});
		sort(ALL(V));
		int ng=0;
		FOR(i,V.size()) {
			O[i]=V[i].second;
			pos[V[i].second]=i;
			if(V[i].second<N) {
				st.update(i,2*N,1);
			}
			else {
				st.update(i,2*N,-1);
			}
		}
		if(st.getval(0,2*N)==0) {
			cout<<"YES"<<endl;
			continue;
		}
		vector<pair<pair<int,int>,int>> cand;
		FOR(y,2*N) FOR(x,y) {
			if(X[x]<=X[y]&&Y[x]<=Y[y]) continue;
			if(X[y]<=X[x]&&Y[y]<=Y[x]) continue;
			int dy=abs(Y[y]-Y[x]);
			int dx=abs(X[y]-X[x]);
			int g=__gcd(dx,dy);
			cand.push_back({{dy/g,dx/g},x});
			cand.push_back({{dy/g,dx/g},y});
		}
		sort(ALL(cand),cmp);
		reverse(ALL(cand));
		int ok=0;
		vector<int> prev;
		for(int L=0,R=0;L<cand.size();L=R) {
			vector<int> A=prev;
			prev.clear();
			while(R<cand.size()&&cand[L].first==cand[R].first) {
				A.push_back(cand[R].second);
				prev.push_back(cand[R].second);
				R++;
			}
			sort(ALL(A));
			A.erase(unique(ALL(A)),A.end());
			vector<int> Os;
			FORR(a,A) {
				Os.push_back(pos[a]);
				if(a<N) st.update(pos[a],2*N,-1);
				else st.update(pos[a],2*N,1);
			}
			CX=cand[L].first.first;
			CY=cand[L].first.second;
			sort(ALL(Os));
			sort(ALL(A),cmp2);
			FOR(i,Os.size()) {
				pos[A[i]]=Os[i];
				O[Os[i]]=A[i];
				if(A[i]<N) st.update(pos[A[i]],2*N,1);
				else st.update(pos[A[i]],2*N,-1);
			}
			if(st.getval(0,2*N)==0) {
				ok=1;
			}
		}
		
		
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
