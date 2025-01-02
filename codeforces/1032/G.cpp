// LUOGU_RID: 158269252
//Crimson flames tied through my ears
//Rollin' high and mighty traps
//Pounced with fire on flaming roads
//Using ideas as my maps
//"We'll meet on edges, soon," said I
//Proud 'neath heated brow
//Ah, but I was so much older then
//I'm younger than that now.
//
//Half-cracked prejudice leaped forth
//"Rip down all hate," I screamed
//Lies that life is black and white
//Spoke from my skull, I dreamed
//Romantic facts of musketeers
//Foundationed deep, somehow
//Ah, but I was so much older then
//I'm younger than that now.
//
//Girls' faces formed the forward path
//From phony jealousy
//To memorizing politics
//Of ancient history
//Flung down by corpse evangelists
//Unthought of, thought, somehow
//Ah, but I was so much older then
//I'm younger than that now.
//A self-ordained professor's tongue
//Too serious to fool
//Spouted out that liberty
//Is just equality in school
//"Equality," I spoke the word
//As if a wedding vow
//Ah, but I was so much older then
//I'm younger than that now.
//
//In a soldier's stance, I aimed my hand
//At the mongrel dogs who teach
//Fearing not that I'd become my enemy
//In the instant that I preach
//My existence led by confusion boats
//Mutiny from stern to bow
//Ah, but I was so much older then
//I'm younger than that now.
//
//Yes, my guard stood hard when abstract threats
//Too noble to neglect
//Deceived me into thinking
//I had something to protect
//Good and bad, I define these terms
//Quite clear, no doubt, somehow
//Ah, but I was so much older then
//I'm younger than that now.

#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
/*=====================================================================*/
#define ll long long
//#define int ll
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pdd pair<double,double>
#define ull unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(s) (s).begin(),(s).end()
#define repd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define forr(i,a,b,c) for(int i=(int)(a);i<=(int)(b);i+=(int)(c))
#define forn(i,p,n) for(int i=(int)(p);i<=(int)(n);++i)
#define ford(i,p,n) for(int i=(int)(n);i>=(int)(p);--i)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define modcg(x) if(x>=mod)x-=mod;
#define modcl(x) if(x<0)x+=mod;
#define lowbit(x) ((x)&(-(x)))
#define ckmax(x,y) x=max(x,y)
#define ckmin(x,y) x=min(x,y)
/*=====================================================================*/
mt19937 GeN(chrono::system_clock::now().time_since_epoch().count());
int Rand(int l,int r)
{
	uniform_int_distribution<>RAND1(l,r);
	return RAND1(GeN);
}
struct Fastmod
{
	int mod,b;
	typedef __int128 lll;
	void init(int m)
	{
		mod=m;
		b=((lll)1<<64)/mod;
	}
	int operator()(ull a)
	{
		int q=((lll)a*b)>>64,r=a-q*mod;
		modcg(r);
		return r;
	}
}MOD;
int mul(int a,int b)
{
	return MOD(a*b);
}
/*======================================================================*/
//think twice,code once
//think once,debug forever
const int MAXN=3e5+10,MAXM=22;
int l[MAXM][MAXN],r[MAXM][MAXN];
int n,N;
struct ST1
{
	int st[MAXM][MAXN];
	int Log[MAXN];
	void init(int op)
	{
		forn(i,2,N)
		{
			Log[i]=Log[i>>1]+1;
		}
		forn(i,1,N)
		{
			st[0][i]=l[op][i];
		}
		forn(j,1,Log[N])
		{
			forn(i,1,N-(1<<j)+1)
			{
				st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	int qurey(int l,int r)
	{
		int s=Log[r-l+1];
		return min(st[s][l],st[s][r-(1<<s)+1]);
	}
}ST1;
struct ST2
{
	int st[MAXM][MAXN];
	int Log[MAXN];
	void init(int op)
	{
		forn(i,2,N)
		{
			Log[i]=Log[i>>1]+1;
		}
		forn(i,1,N)
		{
			st[0][i]=r[op][i];
		}
		forn(j,1,Log[N])
		{
			forn(i,1,N-(1<<j)+1)
			{
				st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	int qurey(int l,int r)
	{
		int s=Log[r-l+1];
		return max(st[s][l],st[s][r-(1<<s)+1]);
	}
}ST2;
int a[MAXN];
int ans[MAXN],L[MAXN],R[MAXN];
void solve()
{
	cin>>n;
	N=n*3;
	forn(i,1,n)
	{
		cin>>a[i];
		a[i+n]=a[i+n*2]=a[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return;
	}
	forn(i,1,N)
	{
		l[0][i]=max(i-a[i],1);r[0][i]=min(i+a[i],N);
	}
	forn(j,1,20)
	{
		ST1.init(j-1);ST2.init(j-1);
		forn(i,1,N)
		{
			l[j][i]=ST1.qurey(l[j-1][i],r[j-1][i]);
			r[j][i]=ST2.qurey(l[j-1][i],r[j-1][i]);
		}
	}
//	forn(j,0,20)
//	{
//		forn(i,1,N)
//		{
//			cout<<l[j][i]<<" ";
//		}
//		cout<<endl;
//	}
//	forn(j,0,20)
//	{
//		forn(i,1,N)
//		{
//			cout<<r[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	forn(i,1,N)
	{
		L[i]=R[i]=i;
	}
	ford(j,0,20)
	{
		ST1.init(j);ST2.init(j);
		forn(i,1,N)
		{
			int l=ST1.qurey(L[i],R[i]);
			int r=ST2.qurey(L[i],R[i]);
			if(r-l+1<n)
			{
				L[i]=l;R[i]=r;
				ans[i]+=1<<j;
			}
		}
	}
	forn(i,n+1,n*2)
	{
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;
}
/*======================================================================*/
signed main()
{
    cin.tie(0);
    cout.tie(0);
	std::ios::sync_with_stdio(false);
//#define Hank2007
#ifdef Hank2007
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
  	/*====================================================================*/
  	int TEST_CASE=1;
//	cin>>TEST_CASE;
  	while(TEST_CASE--)
  	{
  		solve();
  	}
  	return 0;
}